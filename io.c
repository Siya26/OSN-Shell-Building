#include "global.h"

int io(char *tok, int *count, int *cd, int *k)
{
    char **stro, **stri;
    stro = (char **)malloc(no * no * sizeof(char));
    stri = (char **)malloc(no * no * sizeof(char));
   
    char *out, *in;
    out = (char *)malloc(no * sizeof(char));
    in = (char *)malloc(no * sizeof(char));
   
    int length = strlen(tok);
    int loop = 0;
    char met[] = "\t ";
    
    int input = dup(0);
    int output = dup(1);
    int fl_out = 0, fl_in = 0, fl_db = 0;
    
    while (loop < length)
    {
        if (tok[loop] == '>')
        {
            if (tok[loop + 1] == '>')
            {
                fl_db = 1;
                break;
            }
                
            else
                fl_out = 1;
        }

        else if (tok[loop] == '<')
            fl_in = 1;

        loop++;
    }

    if (!fl_out && !fl_db && fl_in)
    {
        stri[0] = strtok_r(tok, "<", &tok);
        stri[1] = strtok_r(tok, "<", &tok);

        str = strtok_r(stri[0], met, &stri[0]);
        int j = 0;

        while (str != NULL)
        {
            a[j] = str;
            str = strtok_r(stri[0], met, &stri[0]);
            j++;
        }

        a[j] = NULL;
        in = strtok_r(stri[1], met, &stri[1]);
    }

    else if ((fl_out || fl_db) && !fl_in)
    {
        stro[0] = strtok_r(tok, ">", &tok);
        stro[1] = strtok_r(tok, ">", &tok);

        str = strtok_r(stro[0], met, &stro[0]);
        int j = 0;

        while (str != NULL)
        {
            a[j] = str;
            str = strtok_r(stro[0], met, &stro[0]);
            j++;
        }

        a[j] = NULL;
        out = strtok_r(stro[1], met, &stro[1]);
    }

    else
    {
        stro[0] = strtok_r(tok, ">", &tok);
        stro[1] = strtok_r(tok, ">", &tok);
        stri[0] = strtok_r(stro[0], "<", &stro[0]);
        stri[1] = strtok_r(stro[0], "<", &stro[0]);

        str = strtok_r(stri[0], met, &stri[0]);
        int j = 0;

        while (str != NULL)
        {
            a[j] = str;
            str = strtok_r(stri[0], met, &stri[0]);
            j++;
        }

        a[j] = NULL;
        in = strtok_r(stri[1], met, &stri[1]);
        out = strtok_r(stro[1], met, &stro[1]);
    }
    
    if (fl_in)
    {
        int fdin = open(in, O_RDONLY);
        if (fdin < 0)
        {
            perror(in);
            return 0;
        }

        dup2(fdin, 0);
        if (close(fdin) < 0)
        {
            perror(in);
            return 0;
        }
    }
    
    if (fl_out)
    {
        int fdo = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fdo < 0)
        {
            perror(out);
            return 0;
        }

        dup2(fdo, 1);
        if (close(fdo) < 0)
        {
            perror(out);
            return 0;
        }
    }

    if (fl_db)
    {
        int fdb = open(out, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fdb < 0)
        {
            perror(out);
            return 0;
        }

        dup2(fdb, 1);
        if (close(fdb) < 0)
        {
            perror(out);
            return 0;
        }  
    }

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

        if (ret < 0)
            perror(" ");

        else if (ret == 0)
        {
            if (execvp(a[0], a) < 0)
                perror(" ");
        }

        else
            wait(NULL);
    }

    dup2(output, 1);
    dup2(input, 0);

    close(output);
    close(input);
}