#include "global.h"

int pip(char *tok, int *count, int *cd, int *k)
{
    int flag_s = 0;
    char met[] = "\t ";
    int input = dup(0);
    int output = dup(1);

    char **com = (char **)malloc(no * no * sizeof(char));
    str = strtok_r(tok, "|", &tok);
    int j = 0;

    while (str != NULL)
    {
        com[j] = str;
        str = strtok_r(tok, "|", &tok);
        j++;
    }

    com[j] = NULL;
    int file_des[j][2];

    int l = 0;
    int ret = pipe(file_des[0]);
    if (ret < 0)
        perror("pipe");

    ret = dup2(file_des[0][1], 1);
    if (ret < 0)
        perror("pipe");

    while (com[0][l] != '\0')
    {
        if (com[0][l] == '<' || com[0][l] == '>')
        {
            io(com[0], &count, &cd, &k);
            flag_s = 1;

            break;
        }
        l++;
    }

    if (!flag_s)
    {
        str = strtok_r(com[0], met, &com[0]);

        l = 0;
        while (str != NULL)
        {
            a[l] = str;
            str = strtok_r(com[0], met, &com[0]);
            l++;
        }

        a[l] = NULL;

        if (strcmp(a[0], "echo") == 0)
            echo();

        else if (strcmp(a[0], "pwd") == 0)
            pwd();

        else if (strcmp(a[0], "cd") == 0)
            cdf(count, cd);

        else if (strcmp(a[0], "history") == 0)
            print(k);

        else if (strcmp(a[0], "ls") == 0)
            ls(1);

        else if (strcmp(a[0], "pinfo") == 0)
            pin();

        else if (strcmp(a[0], "discover") == 0)
            dis();

        else if (strcmp(a[0], "exit") == 0)
            exit(0);

        else if (strcmp(a[0], "jobs") == 0)
            jobs();

        else
        {
            int ret = fork();
            int pid;

            if (ret < 0)
                perror(" ");

            else if (ret == 0)
            {
                if (execvp(a[0], a) < 0)
                    perror(" ");
            }

            else
                pid = waitpid(ret, NULL, WAIT_MYPGRP);
        }
    }

    if (close(file_des[0][1]) < 0)
        perror(" ");

    for (int i = 1; i < j - 1; i++)
    {
        flag_s = 0;
        l = 0;
        ret = pipe(file_des[i]);

        if (ret < 0)
        {
            perror("pipe");
            break;
        }

        ret = dup2(file_des[i][1], 1);
        if (ret < 0)
        {
            perror("pipe");
            break;
        }

        ret = dup2(file_des[i - 1][0], 0);
        if (ret < 0)
        {
            perror("pipe");
            break;
        }

        while (com[i][l] != '\0')
        {
            if (com[i][l] == '<' || com[i][l] == '>')
            {
                io(com[i], &count, &cd, &k);
                flag_s = 1;
                break;
            }
            l++;
        }

        if (!flag_s)
        {
            str = strtok_r(com[i], met, &com[i]);

            l = 0;
            while (str != NULL)
            {
                a[l] = str;
                str = strtok_r(com[i], met, &com[i]);
                l++;
            }

            a[l] = NULL;

            if (strcmp(a[0], "echo") == 0)
                echo();

            else if (strcmp(a[0], "pwd") == 0)
                pwd();

            else if (strcmp(a[0], "cd") == 0)
                cdf(count, cd);

            else if (strcmp(a[0], "history") == 0)
                print(k);

            else if (strcmp(a[0], "ls") == 0)
                ls(1);

            else if (strcmp(a[0], "pinfo") == 0)
                pin();

            else if (strcmp(a[0], "discover") == 0)
                dis();

            else if (strcmp(a[0], "exit") == 0)
                exit(0);

            else if (strcmp(a[0], "jobs") == 0)
                jobs();

            else
            {
                int ret = fork();
                int sec, pid;

                if (ret < 0)
                    perror(" ");

                else if (ret == 0)
                {
                    if (execvp(a[0], a) < 0)
                        perror(" ");
                }

                else
                    pid = waitpid(ret, NULL, WAIT_MYPGRP);
            }
        }

        if (close(file_des[i][1]) < 0)
        {
            perror(" ");
            break;
        }

        if (close(file_des[i - 1][0]) < 0)
        {
            perror(" ");
            break;
        }
    }

    l = 0;
    ret = dup2(file_des[j - 2][0], 0);
    if (ret < 0)
        perror("pipe");

    ret = dup2(output, 1);
    if (ret < 0)
        perror("pipe");

    while (com[j - 1][l] != '\0')
    {
        if (com[j - 1][l] == '<' || com[j - 1][l] == '>')
        {
            io(com[j - 1], &count, &cd, &k);
            ret = dup2(input, 0);
            if (ret < 0)
            {
                perror(" ");
                return 0;
            }

            if (close(file_des[j - 2][0]) < 0)
                perror(" ");

            close(input);
            close(output);
            return 0;
        }
        l++;
    }

    str = strtok_r(com[j - 1], met, &com[j - 1]);

    l = 0;
    while (str != NULL)
    {
        a[l] = str;
        str = strtok_r(com[j - 1], met, &com[j - 1]);
        l++;
    }

    a[l] = NULL;

    if (strcmp(a[0], "echo") == 0)
        echo();

    else if (strcmp(a[0], "pwd") == 0)
        pwd();

    else if (strcmp(a[0], "cd") == 0)
        cdf(count, cd);

    else if (strcmp(a[0], "history") == 0)
        print(k);

    else if (strcmp(a[0], "ls") == 0)
        ls(1);

    else if (strcmp(a[0], "pinfo") == 0)
        pin();

    else if (strcmp(a[0], "discover") == 0)
        dis();

    else if (strcmp(a[0], "exit") == 0)
        exit(0);

    else if (strcmp(a[0], "jobs") == 0)
        jobs();

    else
    {
        int ret = fork();
        int pid;

        if (ret < 0)
            perror(" ");

        else if (ret == 0)
        {
            if (execvp(a[0], a) < 0)
                perror(" ");
        }

        else
            pid = waitpid(ret, NULL, WAIT_MYPGRP);
    }

    ret = dup2(input, 0);
    if (ret < 0)
    {
        perror(" ");
        return 0;
    }

    if (close(file_des[j - 2][0]) < 0)
        perror(" ");

    close(input);
    close(output);
}