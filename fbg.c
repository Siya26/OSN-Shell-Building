#include "global.h"

int pro_pid;

void kes(int *so)
{
    int ved = *so;
    pid_t pid;
    int sec;

    while ((pid = waitpid(-1, &sec, WNOHANG)) > 0)
    {
        int i = 0;
        while (1)
        {
            if (c1[i].index == pid)
                break;
            i++;
        }

        if (WIFEXITED(sec))
        {
            fprintf(stderr, "%s process with pid = %d exited normally\n", c1[i].name, pid);
            c1[i].status = 1;
        }

        else
            fprintf(stderr, "%s process with pid = %d exited abnormally\n", c1[i].name, pid);

        *so = *so - 1;
    }
}

int fbg(int kom, int *so, int *count, int *cd, int *pro)
{
    int i = 0;
    char *chi = (char *)malloc(no * sizeof(char));

    int j = 0;
    char **geet;
    geet = (char **)malloc(no * sizeof(char *));

    char **pp = (char **)malloc(no * sizeof(char *));

    for (int z = 0; z < no; z++)
        pp[z] = (char *)malloc(no * sizeof(char));

    for (int z = 0; z < no; z++)
        geet[z] = (char *)malloc(no * sizeof(char));

    chi = strtok_r(pg, "&", &pg);

    while (chi != NULL)
    {
        geet[j] = chi;
        chi = strtok_r(pg, "&", &pg);
        j++;
    }
    strcpy(geet[j], "");

    int k = 0;
    char met[] = "\t ";
    int l = 0;
    while (strcmp(geet[l], "") != 0)
    {
        strcpy(pp[l], geet[l]);
        l++;
    }
    strcpy(pp[l], "");

    while (strcmp(geet[k], "") != 0)
    {
        int pro_ind = *pro;
        int ved = *so;
        int o = 0;
        str = strtok_r(pp[k], met, &pp[k]);

        while (str != NULL)
        {
            arr[o] = str;
            str = strtok_r(pp[k], met, &pp[k]);
            o++;
        }

        arr[o] = NULL;
        k++;
        int ret = fork();

        if (ret < 0)
            perror(" ");

        else if (ret == 0)
        {
            setpgid(0, 0);
            if (k == j)
            {
                if (jas[kom - 1] != '&')
                {
                    if (!strcmp(arr[0], "cd"))
                        exit(0);
                }
            }

            if (execvp(arr[0], arr) < 0)
                perror(" ");
        }

        else
        {
            setpgid(ret, 0);
            if (k == j)
            {
                if (jas[kom - 1] != '&')
                {
                    time_t t1, t2;

                    int sec;
                    int pid;

                    t1 = time(0);
                    pro_pid = ret;

                    if (!strcmp(arr[0], "cd"))
                    {
                        a = arr;
                        cdf(count, cd);
                    }
                    else
                    {
                        signal(SIGTTIN, SIG_IGN);
                        signal(SIGTTOU, SIG_IGN);

                        tcsetpgrp(0, ret);
                        waitpid(ret, &sec, WUNTRACED);
                        if (WIFSTOPPED(sec))
                        {
                            c1[pro_ind].nb = ved;
                            *so = *so + 1;

                            strcpy(c1[pro_ind].name, geet[k - 1]);
                            c1[pro_ind].index = ret;
                            strcpy(c1[pro_ind + 1].name, "");
                        }
                    }

                    pro_pid = -1;
                    t2 = time(0);

                    long int abhi = t2 - t1;
                    if (abhi)
                        fprintf(stderr, "took %lds\n", abhi);

                    tcsetpgrp(0, getpgid(getpid()));
                    signal(SIGTTIN, SIG_DFL);
                    signal(SIGTTOU, SIG_DFL);
                }

                else
                {
                    fprintf(stderr, "[%d] %d\n", ved, ret);
                    c1[pro_ind].nb = ved;
                    *so = *so + 1;

                    strcpy(c1[pro_ind].name, geet[k - 1]);
                    c1[pro_ind].index = ret;
                    strcpy(c1[pro_ind + 1].name, "");
                    c1[pro_ind].status = 0;

                    setpgid(getpid(), 0);
                    tcsetpgrp(0, getpgid(getpid()));
                }
            }

            else
            {
                fprintf(stderr, "[%d] %d\n", ved, ret);
                c1[pro_ind].nb = ved;
                *so = *so + 1;

                strcpy(c1[pro_ind].name, geet[k - 1]);
                c1[pro_ind].index = ret;
                strcpy(c1[pro_ind + 1].name, "");
                c1[pro_ind].status = 0;

                setpgid(getpid(), 0);
                tcsetpgrp(0, getpgid(getpid()));
            }
        }
        *pro = *pro + 1;
    }
}