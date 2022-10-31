#include "global.h"
int flag = 0;

int comp(const void *name1, const void *name2)
{
    const char **y = (const char **)name1;
    const char **z = (const char **)name2;

    return strcasecmp(*y, *z);
}

void ls1(int *y)
{
    int i = *y;
    for (int j = 0; j < i; j++)
    {
        char *w;
        w = (char *)malloc(no * sizeof(char));
        strcpy(w, p);

        strcat(w, "/");
        strcat(w, q[j]);
        stat(w, &a1);

        if (stat(w, &a1) == 0 && S_ISDIR(a1.st_mode))
        {
            if (!flag)
            {
                printf("\033[1;34m");
                printf("%s\n", q[j]);
                printf("\033[0m");
            }

            else
                printf("%s\n", q[j]);
        }

        else if (stat(w, &a1) == 0 && (a1.st_mode & S_IXUSR))
        {
            if (!flag)
            {
                printf("\033[1;32m");
                printf("%s\n", q[j]);
                printf("\033[0m");
            }

            else
                printf("%s\n", q[j]);
        }

        else
            printf("%s\n", q[j]);
    }
}

int ls_f(int *zz)
{
    int j = *zz;
    DIR *ptr;
    struct dirent *dr;
    ptr = opendir(".");

    if (ptr == NULL)
    {
        perror(a[j]);
        return 0;
    }

    printf("%s\n", p);
    if (stat(p, &a1) == 0 && S_ISDIR(a1.st_mode))
    {
        int i = 0;
        while ((dr = readdir(ptr)) && (dr != NULL))
        {
            if (strncmp(dr->d_name, ".", 1))
            {
                q[i] = dr->d_name;
                i++;
            }
        }

        qsort(q, i, sizeof(char *), comp);
        ls1(&i);
    }

    else
    {
        if (stat(p, &a1) == 0 && (a1.st_mode & S_IXUSR))
        {
            if (!flag)
            {
                printf("\033[1;32m");
                printf("%s\n", a[j]);
                printf("\033[0m");
            }

            else
                printf("%s\n", a[j]);
        }

        else
            printf("%s\n", a[j]);
    }
    chdir(ds);
}

int ls_a(int *zz)
{
    getcwd(p, no);
    int j = *zz;
    DIR *ptr;
    struct dirent *dr;
    ptr = opendir(".");

    if (ptr == NULL)
    {
        perror(a[j]);
        return 0;
    }

    if (stat(p, &a1) == 0 && S_ISDIR(a1.st_mode))
    {
        int i = 0;
        while ((dr = readdir(ptr)) && (dr != NULL))
        {
            q[i] = dr->d_name;
            i++;
        }

        qsort(q, i, sizeof(char *), comp);
        ls1(&i);
    }

    else
    {
        if (stat(p, &a1) == 0 && (a1.st_mode & S_IXUSR))
        {
            if (!flag)
            {
                printf("\033[1;32m");
                printf("%s\n", a[j]);
                printf("\033[0m");
            }

            else
                printf("%s\n", a[j]);
        }

        else
            printf("%s\n", a[j]);
    }
    chdir(ds);
}

int ls_l(int *zz)
{
    int j = *zz;
    char per[10];
    struct stat as2 = {0};
    struct dirent *dr;

    DIR *ptr = opendir(".");
    if (ptr == NULL)
    {
        perror(a[j]);
        return 0;
    }

    if (stat(p, &a1) == 0 && S_ISDIR(a1.st_mode))
    {
        int i = 0;
        while ((dr = readdir(ptr)) && (dr != NULL))
        {
            if (strncmp(dr->d_name, ".", 1))
            {
                q[i] = dr->d_name;
                i++;
            }
        }

        long long int sum = 0;
        qsort(q, i, sizeof(char *), comp);

        for (int j = 0; j < i; j++)
        {
            if (!stat(q[j], &as2))
                sum += as2.st_blocks;
        }

        sum /= 2;
        printf("total %lld\n", sum);

        for (int j = 0; j < i; j++)
        {
            char *w;
            w = (char *)malloc(no * sizeof(char));
            strcpy(w, p);

            strcat(w, "/");
            strcat(w, q[j]);
            stat(w, &a1);

            if (stat(w, &a1) == 0 && S_ISDIR(a1.st_mode))
                per[0] = 'd';
            else
                per[0] = '-';

            // user
            if (a1.st_mode & S_IRUSR)
                per[1] = 'r';
            else
                per[1] = '-';

            if (a1.st_mode & S_IWUSR)
                per[2] = 'w';
            else
                per[2] = '-';

            if (a1.st_mode & S_IXUSR)
                per[3] = 'x';
            else
                per[3] = '-';

            // grp
            if (a1.st_mode & S_IRGRP)
                per[4] = 'r';
            else
                per[4] = '-';

            if (a1.st_mode & S_IWGRP)
                per[5] = 'w';
            else
                per[5] = '-';

            if (a1.st_mode & S_IXGRP)
                per[6] = 'x';
            else
                per[6] = '-';

            // others
            if (a1.st_mode & S_IROTH)
                per[7] = 'r';
            else
                per[7] = '-';

            if (a1.st_mode & S_IWOTH)
                per[8] = 'w';
            else
                per[8] = '-';

            if (a1.st_mode & S_IXOTH)
                per[9] = 'x';
            else
                per[9] = '-';

            printf("%s", per);
            struct passwd *usr = getpwuid(a1.st_uid);
            struct group *grp = getgrgid(a1.st_gid);

            printf("%3ld ", a1.st_nlink);
            printf("%s ", usr->pw_name);
            printf("%s", grp->gr_name);
            printf("%7ld ", a1.st_size);

            char *t;
            t = ctime(&a1.st_mtime);
            t[16] = '\0';

            printf("%s ", &t[4]);
            if (stat(w, &a1) == 0 && S_ISDIR(a1.st_mode))
            {
                if (!flag)
                {
                    printf("\033[1;34m");
                    printf("%s\n", q[j]);
                    printf("\033[0m");
                }

                else
                    printf("%s\n", q[j]);
            }

            else if (stat(w, &a1) == 0 && (a1.st_mode & S_IXUSR))
            {
                if (!flag)
                {
                    printf("\033[1;32m");
                    printf("%s\n", q[j]);
                    printf("\033[0m");
                }

                else
                    printf("%s\n", q[j]);
            }

            else
                printf("%s\n", q[j]);
        }
    }

    else
    {
        stat(p, &a1);
        per[0] = '-';

        // user
        if (a1.st_mode & S_IRUSR)
            per[1] = 'r';
        else
            per[1] = '-';

        if (a1.st_mode & S_IWUSR)
            per[2] = 'w';
        else
            per[2] = '-';

        if (a1.st_mode & S_IXUSR)
            per[3] = 'x';
        else
            per[3] = '-';

        // grp
        if (a1.st_mode & S_IRGRP)
            per[4] = 'r';
        else
            per[4] = '-';

        if (a1.st_mode & S_IWGRP)
            per[5] = 'w';
        else
            per[5] = '-';

        if (a1.st_mode & S_IXGRP)
            per[6] = 'x';
        else
            per[6] = '-';

        // others
        if (a1.st_mode & S_IROTH)
            per[7] = 'r';
        else
            per[7] = '-';

        if (a1.st_mode & S_IWOTH)
            per[8] = 'w';
        else
            per[8] = '-';

        if (a1.st_mode & S_IXOTH)
            per[9] = 'x';
        else
            per[9] = '-';

        printf("%s", per);
        struct passwd *usr = getpwuid(a1.st_uid);
        struct group *grp = getgrgid(a1.st_gid);

        printf("%3ld ", a1.st_nlink);
        printf("%s ", usr->pw_name);
        printf("%s", grp->gr_name);
        printf("%7ld ", a1.st_size);

        char *t;
        t = ctime(&a1.st_mtime);
        t[16] = '\0';

        printf("%s ", &t[4]);
        if (stat(p, &a1) == 0 && (a1.st_mode & S_IXUSR))
        {
            if (!flag)
            {
                printf("\033[1;32m");
                printf("%s\n", a[j]);
                printf("\033[0m");
            }

            else
                printf("%s\n", a[j]);
        }

        else
            printf("%s\n", a[j]);
    }
    chdir(ds);
}

int ls_al(int *zz)
{
    int j = *zz;
    char per[10];
    struct stat as2 = {0};
    struct dirent *dr;

    DIR *ptr = opendir(".");
    if (ptr == NULL)
    {
        perror(a[j]);
        return 0;
    }

    if (stat(p, &a1) == 0 && S_ISDIR(a1.st_mode))
    {
        int i = 0;
        while ((dr = readdir(ptr)) && (dr != NULL))
        {
            q[i] = dr->d_name;
            i++;
        }

        long long int sum = 0;
        qsort(q, i, sizeof(char *), comp);

        for (int j = 0; j < i; j++)
        {
            if (!stat(q[j], &as2))
                sum += as2.st_blocks;
        }

        sum /= 2;
        printf("total %lld\n", sum);

        for (int j = 0; j < i; j++)
        {
            char *w;
            w = (char *)malloc(no * sizeof(char));
            strcpy(w, p);

            strcat(w, "/");
            strcat(w, q[j]);
            stat(w, &a1);

            if (stat(w, &a1) == 0 && S_ISDIR(a1.st_mode))
                per[0] = 'd';
            else
                per[0] = '-';
            // user
            if (a1.st_mode & S_IRUSR)
                per[1] = 'r';
            else
                per[1] = '-';

            if (a1.st_mode & S_IWUSR)
                per[2] = 'w';
            else
                per[2] = '-';

            if (a1.st_mode & S_IXUSR)
                per[3] = 'x';
            else
                per[3] = '-';

            // grp
            if (a1.st_mode & S_IRGRP)
                per[4] = 'r';
            else
                per[4] = '-';

            if (a1.st_mode & S_IWGRP)
                per[5] = 'w';
            else
                per[5] = '-';

            if (a1.st_mode & S_IXGRP)
                per[6] = 'x';
            else
                per[6] = '-';

            // others
            if (a1.st_mode & S_IROTH)
                per[7] = 'r';
            else
                per[7] = '-';

            if (a1.st_mode & S_IWOTH)
                per[8] = 'w';
            else
                per[8] = '-';

            if (a1.st_mode & S_IXOTH)
                per[9] = 'x';
            else
                per[9] = '-';

            printf("%s", per);
            struct passwd *usr = getpwuid(a1.st_uid);
            struct group *grp = getgrgid(a1.st_gid);

            printf("%3ld ", a1.st_nlink);
            printf("%s ", usr->pw_name);
            printf("%s", grp->gr_name);
            printf("%7ld ", a1.st_size);

            char *t;
            t = ctime(&a1.st_mtime);
            t[16] = '\0';

            printf("%s ", &t[4]);
            if (stat(w, &a1) == 0 && S_ISDIR(a1.st_mode))
            {
                if (!flag)
                {
                    printf("\033[1;34m");
                    printf("%s\n", q[j]);
                    printf("\033[0m");
                }

                else
                    printf("%s\n", q[j]);
            }

            else if (stat(w, &a1) == 0 && (a1.st_mode & S_IXUSR))
            {
                if (!flag)
                {
                    printf("\033[1;32m");
                    printf("%s\n", q[j]);
                    printf("\033[0m");
                }

                else
                    printf("%s\n", q[j]);
            }

            else
                printf("%s\n", q[j]);
        }
    }

    else
    {
        stat(p, &a1);
        per[0] = '-';

        // user
        if (a1.st_mode & S_IRUSR)
            per[1] = 'r';
        else
            per[1] = '-';

        if (a1.st_mode & S_IWUSR)
            per[2] = 'w';
        else
            per[2] = '-';

        if (a1.st_mode & S_IXUSR)
            per[3] = 'x';
        else
            per[3] = '-';

        // grp
        if (a1.st_mode & S_IRGRP)
            per[4] = 'r';
        else
            per[4] = '-';

        if (a1.st_mode & S_IWGRP)
            per[5] = 'w';
        else
            per[5] = '-';

        if (a1.st_mode & S_IXGRP)
            per[6] = 'x';
        else
            per[6] = '-';

        // others
        if (a1.st_mode & S_IROTH)
            per[7] = 'r';
        else
            per[7] = '-';

        if (a1.st_mode & S_IWOTH)
            per[8] = 'w';
        else
            per[8] = '-';

        if (a1.st_mode & S_IXOTH)
            per[9] = 'x';
        else
            per[9] = '-';

        printf("%s", per);
        struct passwd *usr = getpwuid(a1.st_uid);
        struct group *grp = getgrgid(a1.st_gid);

        printf("%3ld ", a1.st_nlink);
        printf("%s ", usr->pw_name);
        printf("%s", grp->gr_name);
        printf("%7ld ", a1.st_size);

        char *t;
        t = ctime(&a1.st_mtime);
        t[16] = '\0';

        printf("%s ", &t[4]);
        if (stat(p, &a1) == 0 && (a1.st_mode & S_IXUSR))
        {
            if (!flag)
            {
                printf("\033[1;32m");
                printf("%s\n", a[j]);
                printf("\033[0m");
            }

            else
                printf("%s\n", a[j]);
        }

        else
            printf("%s\n", a[j]);
    }
    chdir(ds);
}

int lsn(int *zz)
{
    int j = *zz;
    DIR *ptr;
    struct dirent *dr;
    if (strcmp(a[j], ".") == 0 || strcmp(a[j], "..") == 0)
    {
        if (strcmp(a[j], "..") == 0)
        {
            ptr = opendir("..");

            char *w = strrchr(p, '/');
            if (w != NULL)
                *w = '\0';
        }

        else
            ptr = opendir(".");

        if (ptr == NULL)
        {
            perror(p);
            return 0;
        }

        int i = 0;
        while ((dr = readdir(ptr)) && (dr != NULL))
        {
            if (strncmp(dr->d_name, ".", 1))
            {
                q[i] = dr->d_name;
                i++;
            }
        }

        qsort(q, i, sizeof(char *), comp);
        ls1(&i);
    }

    // ls ~
    else if (strcmp(a[j], "~") == 0)
    {
        ptr = opendir(c);
        chdir(c);
        getcwd(p, no);

        if (ptr == NULL)
        {
            perror(c);
            return 0;
        }

        int i = 0;
        while ((dr = readdir(ptr)) && (dr != NULL))
        {
            if (strncmp(dr->d_name, ".", 1))
            {
                q[i] = dr->d_name;
                i++;
            }
        }

        qsort(q, i, sizeof(char *), comp);
        ls1(&i);
    }
    chdir(ds);
}

int ls(int flag_ls)
{
    if (flag_ls)
        flag = 1;

    DIR *ptr;
    struct dirent *dr;
    getcwd(p, no);
    strcpy(ds, p);

    int flag = 0;
    int j = 1, nod = 0;
    int fl = 0, fa = 0, fla = 0;

    if (a[1] == NULL)
    {
        ptr = opendir(".");
        if (ptr == NULL)
        {
            perror(p);
            return 0;
        }

        int i = 0;
        while ((dr = readdir(ptr)) && (dr != NULL))
        {
            if (strncmp(dr->d_name, ".", 1))
            {
                q[i] = dr->d_name;
                i++;
            }
        }

        qsort(q, i, sizeof(char *), comp);
        ls1(&i);
    }

    else
    {
        while (a[j] != NULL)
        {
            if (!strcmp(a[j], "-l"))
                fl = 1;

            else if (!strcmp(a[j], "-a"))
                fa = 1;

            else if ((!strcmp(a[j], "-la")) || (!strcmp(a[j], "-al")))
                fla = 1;

            else if ((strcmp(a[j], ".")) && (strcmp(a[j], "..")) && (strcmp(a[j], "~")))
            {
                if (stat(a[j], &a1) == 0)
                    strcpy(p, a[j]);

                else
                {
                    getcwd(p, no);
                    strcat(p, "/");
                    strcat(p, a[j]);
                }

                if (stat(p, &a1) == 0 && S_ISDIR(a1.st_mode))
                    nod++;
            }

            else if ((!strcmp(a[j], ".")) || (!strcmp(a[j], "..")) || (!strcmp(a[j], "~")))
                nod++;

            if (fl && fa)
                fla = 1;

            j++;
        }

        getcwd(p, no);
        j = 1;
        int fg = 0;

        while (a[j] != NULL)
        {
            if ((strcmp(a[j], "-l")) && (strcmp(a[j], "-a")) && (strcmp(a[j], "-al")) && (strcmp(a[j], "-la")))
            {
                flag = 1;
                if (nod >= 2)
                {
                    if (!strcmp(a[j], "~"))
                    {
                        if (!fg)
                            printf("%s:\n", c);
                        else
                            printf("\n%s:\n", c);
                        fg = 1;
                    }

                    else
                    {
                        if (!fg)
                            printf("%s:\n", a[j]);
                        else
                            printf("\n%s:\n", a[j]);
                        fg = 1;
                    }
                }

                if ((strcmp(a[j], ".")) && (strcmp(a[j], "..")) && (strcmp(a[j], "~")))
                {
                    if (stat(a[j], &a1) == 0)
                        strcpy(p, a[j]);

                    else
                    {
                        getcwd(p, no);
                        strcat(p, "/");
                        strcat(p, a[j]);
                    }

                    if (stat(p, &a1) == 0 && S_ISDIR(a1.st_mode))
                        chdir(p);
                }

                if (fla)
                    ls_al(&j);
                else if (fl)
                    ls_l(&j);
                else if (fa)
                    ls_a(&j);

                else if ((!strcmp(a[j], ".")) || (!strcmp(a[j], "..")) || (!strcmp(a[j], "~")))
                    lsn(&j);

                else
                    ls_f(&j);
            }
            j++;
        }

        if (!flag)
        {
            j = 1;
            getcwd(p, no);

            if (fla)
                ls_al(&j);
            else if (fl)
                ls_l(&j);
            else if (fa)
                ls_a(&j);
        }
    }
}
