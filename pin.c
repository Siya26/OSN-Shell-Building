#include "global.h"

int pin()
{
    int pid;
    if (a[1] == NULL)
        pid = getpid();
    else
        pid = atoi(a[1]);

    char *proc = (char *)malloc(no * sizeof(char));
    char *buf = (char *)malloc(no * sizeof(char));
    sprintf(buf, "%d", pid);

    strcpy(proc, "/proc/");
    strcat(proc, buf);
    strcat(proc, "/stat");
    //printf("%s\n", proc);

    FILE *fp = fopen(proc, "r");
    if(fp == NULL)
    {
        perror(proc);
        return 0;
    }
    char status;

    int pg, tp;
    long unsigned int v;
    fscanf(fp, "%d %*s %c %*d %d %*d %*d %d %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %lu", &pid, &status, &pg, &tp, &v);

    printf("pid : %d\n", pid);
    printf("process Status : {%c", status);
    if (pg == tp)
        printf("+");
    printf("}\n");

    printf("memory : ");
    printf("%lu ", v);
    printf("{Virtual Memory}\n");

    char *w = (char *)malloc(no * sizeof(char));
    w = strrchr(proc, '/');
    if (w != NULL)
        *w = '\0';

    printf("executable Path : ");
    fclose(fp);

    strcat(proc, "/exe");
    FILE *fp1 = fopen(proc, "r");
    int ret = readlink(proc, buf, no);

    if (ret == -1)
        perror("Executable path");
    else
    {
        buf[ret] = '\0';
        if (!strncmp(c, buf, strlen(c)))
        {
            strcpy(buf, &buf[strlen(c)]);
            printf("~");
        }
        printf("%s\n", buf);
    }
    fclose(fp1);
}