#include "global.h"

void cdf(int *count, int *cd)
{
    if (a[2] != NULL)
        printf(":No such file or directory exists\n");

    else
    {
        if (a[1] == NULL || strcmp(a[1], "~") == 0)
        {
            getcwd(d, no);
            if (*count % 2 == 0)
                strcpy(e, b);
            strcpy(b, u);

            chdir(c);
            getcwd(m, no);
            *count = 0;
        }

        else if (strncmp(a[1], "~/", 2) == 0)
        {
            getcwd(d, no);
            if (*count % 2 == 0)
                strcpy(e, b);
            strcpy(b, u);

            chdir(c);

            *count = 0;
            int fd = open(&a[1][2], O_DIRECTORY);

            if (fd < 0)
                perror(&a[1][2]);
            else
            {
                *cd = 0;
                strcat(b, "/");
                strcat(b, &a[1][2]);
                chdir(&a[1][2]);
                getcwd(m, no);
            }
        }

        else if (strcmp(a[1], "..") == 0)
        {
            getcwd(d, no);
            if (*count % 2 != 0)
                strcpy(b, e);
            else
                strcpy(e, b);

            char *prev;
            char *pr = strrchr(b, '/');

            if (pr != NULL)
            {
                *pr = '\0';
                chdir("..");
            }

            else
            {
                if (!*cd)
                {
                    strcpy(b, u);
                    strcpy(mum, c);

                    char *w;
                    w = strrchr(mum, '/');
                    if (w != NULL)
                        *w = '\0';

                    strcat(b, mum);
                    *cd = *cd + 1;
                    chdir(mum);
                }
            }

            getcwd(m, no);
            *count = 0;
        }

        else if (strcmp(a[1], ".") == 0)
        {
            getcwd(d, no);
            if (*count % 2 == 0)
                strcpy(e, b);
            else
                strcpy(b, e);
            // strcpy(e, b);
            *count = 0;
        }

        else if (strcmp(a[1], "-") == 0)
        {
            *count = *count + 1;
            if (*count % 2 != 0)
            {
                printf("%s\n", d);
                chdir(d);
            }
            else
            {
                printf("%s\n", m);
                chdir(m);
            }
        }

        else
        {
            int fd = open(a[1], O_DIRECTORY);

            if (fd < 0)
                perror(a[1]);
            else
            {
                *cd = 0;
                getcwd(d, no);
                if (*count % 2 == 0)
                    strcpy(e, b);
                else
                    strcpy(b, e);

                strcat(b, "/");
                strcat(b, a[1]);

                chdir(a[1]);
                getcwd(m, no);
                *count = 0;
            }
        }
    }
}
