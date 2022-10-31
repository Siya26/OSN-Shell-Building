#include "global.h"

int dis_fd(char dv[], char pav[])
{
    DIR *ptr;
    struct dirent *dr;

    ptr = opendir(pav);
    char home[no];
    char anu[no];

    if (ptr == NULL)
    {
        perror(p);
        return 0;
    }

    char **file = (char **)malloc(no * no * sizeof(char));
    printf("%s\n", dv);
    
    int i = 0;

    while ((dr = readdir(ptr)) && (dr != NULL))
    {
        if (strncmp(dr->d_name, ".", 1))
        {
            file[i] = dr->d_name;
            i++;
        }
    }

    strcat(dv, "/");
    strcat(pav, "/");
    strcpy(home, dv);
    strcpy(anu, pav);

    for (int j = 0; j < i; j++)
    {
        strcat(dv, file[j]);
        strcat(pav, file[j]);

        if (stat(pav, &a1) == 0 && S_ISDIR(a1.st_mode))
            dis_fd(dv, pav);
        else
            printf("%s\n", dv);

        strcpy(dv, home);
        strcpy(pav, anu);
    }
}

int dis_d(char dv[], char pav[])
{
    DIR *ptr;
    struct dirent *dr;

    ptr = opendir(pav);
    char home[no];
    char anu[no];

    if (ptr == NULL)
    {
        perror(p);
        return 0;
    }

    char **file = (char **)malloc(no * no * sizeof(char));

    if (stat(pav, &a1) == 0 && S_ISDIR(a1.st_mode))
        printf("%s\n", dv);

    int i = 0;

    while ((dr = readdir(ptr)) && (dr != NULL))
    {
        if (strncmp(dr->d_name, ".", 1))
        {
            file[i] = dr->d_name;
            i++;
        }
    }

    strcat(dv, "/");
    strcat(pav, "/");
    strcpy(home, dv);
    strcpy(anu, pav);

    for (int j = 0; j < i; j++)
    {
        strcat(dv, file[j]);
        strcat(pav, file[j]);

        if (stat(pav, &a1) == 0 && S_ISDIR(a1.st_mode))
            dis_d(dv, pav);

        strcpy(dv, home);
        strcpy(pav, anu);
    }
}

int dis_f(char dv[], char pav[])
{
    DIR *ptr;
    struct dirent *dr;

    ptr = opendir(pav);
    char home[no];
    char anu[no];

    if (ptr == NULL)
    {
        perror(p);
        return 0;
    }

    char **file = (char **)malloc(no * no * sizeof(char));

    if ((stat(pav, &a1) != 0 || !S_ISDIR(a1.st_mode)))
        printf("%s\n", dv);

    int i = 0;
    while ((dr = readdir(ptr)) && (dr != NULL))
    {
        if (strncmp(dr->d_name, ".", 1))
        {
            file[i] = dr->d_name;
            i++;
        }
    }

    strcat(dv, "/");
    strcat(pav, "/");
    strcpy(home, dv);
    strcpy(anu, pav);

    for (int j = 0; j < i; j++)
    {
        strcat(dv, file[j]);
        strcat(pav, file[j]);

        if (stat(pav, &a1) == 0 && S_ISDIR(a1.st_mode))
            dis_f(dv, pav);

        else
            printf("%s\n", dv);

        strcpy(dv, home);
        strcpy(pav, anu);
    }
}

int dis_ff(char dv[], char pav[], int jj)
{
    DIR *ptr;
    struct dirent *dr;

    ptr = opendir(pav);
    char home[no];
    char anu[no];

    if (ptr == NULL)
    {
        perror(p);
        return 0;
    }

    char **file = (char **)malloc(no * no * sizeof(char));

    int i = 0;
    while ((dr = readdir(ptr)) && (dr != NULL))
    {
        if (strncmp(dr->d_name, ".", 1))
        {
            file[i] = dr->d_name;
            i++;
        }
    }

    strcat(dv, "/");
    strcat(pav, "/");
    strcpy(home, dv);
    strcpy(anu, pav);

    for (int j = 0; j < i; j++)
    {
        strcat(dv, file[j]);
        strcat(pav, file[j]);

        if (stat(pav, &a1) == 0 && S_ISDIR(a1.st_mode))
            dis_ff(dv, pav, jj);

        else
        {
            char *soyo = (char *)malloc(no * sizeof(char));
            strcpy(soyo, pav);
            char *w = strrchr(soyo, '/');
            if (w != NULL)
            {
                soyo = w;
                soyo = &soyo[1];

                if (jj)
                {
                    if (!strcmp(a[jj], soyo))
                        printf("%s\n", dv);
                }
            }
        }

        strcpy(dv, home);
        strcpy(pav, anu);
    }
}

// discover
int disn(char dv[], char pav[])
{
    DIR *ptr;
    struct dirent *dr;

    ptr = opendir(pav);
    char home[no];
    char anu[no];

    if (ptr == NULL)
    {
        perror(p);
        return 0;
    }

    char **file = (char **)malloc(no * no * sizeof(char));
    printf("%s\n", dv);
    int i = 0;

    while ((dr = readdir(ptr)) && (dr != NULL))
    {
        if (strncmp(dr->d_name, ".", 1))
        {
            file[i] = dr->d_name;
            i++;
        }
    }

    strcat(dv, "/");
    strcat(pav, "/");
    strcpy(home, dv);
    strcpy(anu, pav);

    for (int j = 0; j < i; j++)
    {
        strcat(dv, file[j]);
        strcat(pav, file[j]);

        if (stat(pav, &a1) == 0 && S_ISDIR(a1.st_mode))
            disn(dv, pav);
        else
            printf("%s\n", dv);

        strcpy(dv, home);
        strcpy(pav, anu);
    }
}

int dis()
{
    char *shr = (char *)malloc(no * sizeof(char));
    getcwd(nik, no);

    strcpy(shr, nik);
    char dv[no] = {};
    int j = 1, fd = 0, ff = 0, ffd = 0, fflag = 0;
    if (a[1] == NULL)
    {
        strcpy(dv, ".");
        char pav[no];

        getcwd(pav, no);
        disn(dv, pav);
    }

    else
    {
        int nod = 0;
        int vib = 0, wed = 0;
        while (a[j] != NULL)
        {
            if (!strcmp(a[j], "-d"))
            {
                strcpy(dv, ".");
                nod++;
                fd = 1;
            }

            else if (!strcmp(a[j], "-f"))
            {
                strcpy(dv, ".");
                nod++;
                ff = 1;
            }

            else if (!strcmp(a[j], "..") || !strcmp(a[j], ".") || !strcmp(a[j], "~"))
                nod++;

            else if (!strncmp(a[j], "./", 2))
            {
                strcpy(dv, a[j]);
                strcpy(a[j], &a[j][2]);
                strcat(nik, "/");
                strcat(nik, a[j]);
                chdir(nik);

                nod++;
                wed = j;
            }

            else if (a[j][0] == '"')
            {
                fflag = 1;
                vib = j;
                nod++;
            }

            if (fd && ff)
                ffd = 1;

            j++;
        }

        j = 1;
        while (a[j] != NULL)
        {
            if (strcmp(a[j], "-d") && strcmp(a[j], "-f"))
            {
                if (!strcmp(a[j], ".."))
                {
                    chdir("..");
                    strcpy(dv, "..");
                }

                else if (!strcmp(a[j], "~"))
                {
                    chdir(c);
                    strcpy(dv, "~");
                }

                else if (!strcmp(a[j], "."))
                    strcpy(dv, ".");
            }
            j++;
        }

        char pav[no];
        getcwd(pav, no);

        if (nod)
        {
            j = wed;
            if (!strncmp(c, a[j], strlen(c)))
                strcpy(a[j], &a[j][strlen(c)]);
            else
            {
                j = vib;
                char *w = strrchr(a[j], '"');
                if (w != NULL)
                {
                    *w = '\0';
                    a[j] = &a[j][1];
                }
            }

            if (fflag)
            {
                dis_ff(dv, pav, vib);
                chdir(shr);
            }

            else if (ffd)
            {
                dis_fd(dv, pav);
                chdir(shr);
            }
            else if (fd)
            {
                dis_d(dv, pav);
                chdir(shr);
            }
            else if (ff)
            {
                dis_f(dv, pav);
                chdir(shr);
            }
            else
            {
                dis_fd(dv, pav);
                chdir(shr);
            }
        }

        else
        {
            disn(dv, pav);
            chdir(shr);
        }
    }
}