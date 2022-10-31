#include "global.h"

void bub(int nonames)
{
    int swap = 0;
    char tempstr[no];
    int tmp1, tmp2, tmp3;

    if (nonames == 1)
        return;

    for (int i = 0; i < nonames - 1; i++)
    {
        if (strcmp(c1[i].name, c1[i + 1].name) < 0)
            continue;

        else
        {
            strcpy(tempstr, c1[i].name);
            strcpy(c1[i].name, c1[i + 1].name);
            strcpy(c1[i + 1].name, tempstr);

            tmp1 = c1[i].nb;
            c1[i].nb = c1[i + 1].nb;
            c1[i + 1].nb = tmp1;

            tmp2 = c1[i].index;
            c1[i].index = c1[i + 1].index;
            c1[i + 1].index = tmp2;

            tmp3 = c1[i].status;
            c1[i].status = c1[i + 1].status;
            c1[i + 1].status = tmp3;
        }
    }
    if (swap > 0)
        bub(nonames - 1);
}

int jobs()
{
    int i = 0;
    while (strcmp(c1[i].name, ""))
        i++;

    bub(i);
    for (int j = 0; j < i; j++)
    {
        char *proc = (char *)malloc(no * sizeof(char));
        char *buf = (char *)malloc(no * sizeof(char));

        if (c1[j].status)
            continue;

        sprintf(buf, "%d", c1[j].index);

        strcpy(proc, "/proc/");
        strcat(proc, buf);
        strcat(proc, "/stat");

        FILE *fp = fopen(proc, "r");
        if (fp == NULL)
            return 0;

        char stu;
        fscanf(fp, "%*d %*s %c", &stu);

        if (a[1] == NULL)
        {
            printf("[%d] ", c1[j].nb);

            if (stu == 'T')
                printf("Stopped ");
            else
                printf("Running ");

            printf("%s ", c1[j].name);
            printf("[%d]\n", c1[j].index);
        }

        else if (!strcmp(a[1], "-r") && (stu != 'T'))
        {
            printf("[%d] ", c1[j].nb);
            printf("Running ");

            printf("%s ", c1[j].name);
            printf("[%d]\n", c1[j].index);
        }

        else if (!strcmp(a[1], "-s") && (stu == 'T'))
        {
            printf("[%d] ", c1[j].nb);
            printf("Stopped ");

            printf("%s ", c1[j].name);
            printf("[%d]\n", c1[j].index);
        }
        fclose(fp);
    }
}

int sig()
{
    int i = 0;
    while (1)
    {
        if (!strcmp(c1[i].name, ""))
        {
            printf("Process with that job number does not exist\n");
            return 0;
        }

        else if (c1[i].nb == atoi(a[1]))
            break;

        i++;
    }

    char *proc = (char *)malloc(no * sizeof(char));
    char *buf = (char *)malloc(no * sizeof(char));
    sprintf(buf, "%d", c1[i].index);

    strcpy(proc, "/proc/");
    strcat(proc, buf);
    strcat(proc, "/stat");

    FILE *fp = fopen(proc, "r");
    if (fp == NULL)
    {
        perror(proc);
        return 0;
    }

    char stu;
    fscanf(fp, "%*d %*s %c", &stu);

    if (stu == 'T')
    {
        printf("Process with that job number is not running\n");
        return 0;
    }

    int ret = kill(c1[i].index, atoi(a[2]));
    if (ret < 0)
    {
        perror(a[2]);
        return 0;
    }
    fclose(fp);
}

int fg()
{
    signal(SIGTTIN, SIG_DFL);
    signal(SIGTTOU, SIG_DFL);

    int i = 0;
    while (1)
    {
        if (!strcmp(c1[i].name, ""))
        {
            printf("Process with that job number does not exist\n");
            return 0;
        }

        else if (c1[i].nb == atoi(a[1]))
            break;

        i++;
    }

    int pid1 = tcsetpgrp(0, getpgid(c1[i].index));
    if (pid1 < 0)
    {
        perror(" ");
        return 0;
    }

    int ret = kill(c1[i].index, SIGCONT);
    if (ret < 0)
    {
        perror(" ");
        return 0;
    }

    int sec;
    int pid;

    pid = waitpid(c1[i].index, &sec, WAIT_MYPGRP);
    c1[i].status = 1;

    signal(SIGTTOU, SIG_IGN);
    int pid2 = tcsetpgrp(0, getpgid(0));
    if (pid2 < 0)
    {
        perror(" ");
        return 0;
    }

    signal(SIGTTIN, SIG_DFL);
    signal(SIGTTOU, SIG_DFL);
}

int bg()
{
    int i = 0;
    while (1)
    {
        if (!strcmp(c1[i].name, ""))
        {
            printf("Process with that job number does not exist\n");
            return 0;
        }

        else if (c1[i].nb == atoi(a[1]))
            break;

        i++;
    }

    char *proc = (char *)malloc(no * sizeof(char));
    char *buf = (char *)malloc(no * sizeof(char));
    sprintf(buf, "%d", c1[i].index);

    strcpy(proc, "/proc/");
    strcat(proc, buf);
    strcat(proc, "/stat");

    FILE *fp = fopen(proc, "r");
    if (fp == NULL)
    {
        perror(proc);
        return 0;
    }

    char stu;
    fscanf(fp, "%*d %*s %c", &stu);

    if (stu == 'T')
    {
        int ret = kill(c1[i].index, SIGCONT);
        if (ret < 0)
        {
            perror(" ");
            return 0;
        }
    }
}