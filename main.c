#include "global.h"

int pro = 0;
int count = 0;

void ctrl_z()
{
    printf("\n");

    if (count % 2 != 0)
        printf("%s> ", e);
    else
        printf("%s> ", b);
    fflush(stdout);
}

void ctrl_c()
{
    int ret;

    if (pro_pid > 0)
    {
        ret = kill(pro_pid, SIGKILL);
        printf("\n");
    }
    
    else
        ctrl_z();
}

int main()
{
    h = (char *)malloc(no * sizeof(char));
    u = (char *)malloc(no * sizeof(char));
    e = (char *)malloc(no * sizeof(char));
    m = (char *)malloc(no * sizeof(char));
    mum = (char *)malloc(no * sizeof(char));
    ne = (char **)malloc(no * sizeof(char *));

    for (int z = 0; z < no; z++)
        ne[z] = (char *)malloc(no * sizeof(char));

    strcpy(u, "<");
    strcat(u, getlogin());
    strcat(u, "@");
    gethostname(h, no);

    strcat(u, h);
    strcat(u, ":~");
    printf("%s> ", u);

    ds = (char *)malloc(no * sizeof(char));
    d = (char *)malloc(no * sizeof(char));
    p = (char *)malloc(no * sizeof(char));
    path = (char *)malloc(no * sizeof(char));
    b = (char *)malloc(no * sizeof(char));
    x = (char *)malloc(no * sizeof(char));
    strcpy(b, u);

    c = (char *)malloc(no * sizeof(char));
    nik = (char *)malloc(no * sizeof(char));
    pg = (char *)malloc(no * sizeof(char));

    getcwd(c, no);

    int cd = 0;
    int k = 0;

    FILE *fp = fopen("history.txt", "r");
    if (fp == NULL)
    {
        FILE *fp1 = fopen("history.txt", "w");
        fclose(fp1);
        fp = fopen("history.txt", "r");
    }

    while (1)
    {
        int r = fscanf(fp, "%[^\n]%*c", ht[k]);
        if ((r == 0) || (r == -1))
            break;

        k++;
    }

    fclose(fp);
    int *so;
    int temp = 1;
    so = &temp;
    strcpy(c1[0].name, "");

    signal(SIGINT, ctrl_c);
    signal(SIGTSTP, ctrl_z);

    while (1)
    {
        int i = 0, ret;
        int floo = 0, flow = 0;
        if (scanf("%[^\n]%*c", h) == -1)
        {
            while (strcmp(c1[i].name, ""))
            {
                ret = kill(c1[i].index, SIGKILL);
                i++;
            }

            printf("\n");
            return 0;
        }

        kes(so);
        jas = (char *)malloc(no * sizeof(char));
        strcpy(jas, h);
        int kom = strlen(h);
        his(&k);

        str = (char *)malloc(no * sizeof(char));
        n = (char **)malloc(no * no * sizeof(char));
        char del[] = ";";

        str = strtok_r(h, del, &h);
        if (str != NULL)
            n[0] = str;

        i = 0;

        while (str != NULL)
        {
            str = strtok_r(h, del, &h);
            i++;

            if (str != NULL)
                n[i] = str;
        }

        n[i] = "";

        i = 0;
        char met[] = "\t ";

        int l = 0;
        while (strcmp(n[l], "") != 0)
        {
            strcpy(ne[l], n[l]);
            l++;
        }
        strcpy(ne[l], "");

        while (strcmp(n[i], "") != 0)
        {
            a = (char **)malloc(no * no * sizeof(char));
            int length = strlen(n[i]);

            int loop = 0;
            while (loop < length)
            {
                if (n[i][loop] == '|')
                {
                    pip(ne[i], &count, &cd, &k);
                    flow = 1;
                    break;
                }
                loop++;
            }

            if (!flow)
            {
                loop = 0;
                while (loop < length)
                {
                    if (n[i][loop] == '>' || n[i][loop] == '<')
                    {
                        io(ne[i], &count, &cd, &k);
                        floo = 1;
                        break;
                    }
                    loop++;
                }
            }

            strcpy(pg, n[i]);
            int j = 0;

            if (!floo && !flow)
            {
                str = strtok_r(ne[i], met, &ne[i]);

                while (str != NULL)
                {
                    a[j] = str;
                    str = strtok_r(ne[i], met, &ne[i]);
                    j++;
                }

                a[j] = NULL;

                if (strcmp(a[0], "echo") == 0)
                    echo();

                else if (strcmp(a[0], "pwd") == 0)
                    pwd();

                else if (strcmp(a[0], "cd") == 0)
                    cdf(&count, &cd);

                else if (strcmp(a[0], "history") == 0)
                    print(&k);

                else if (strcmp(a[0], "ls") == 0)
                    ls(0);

                else if (strcmp(a[0], "pinfo") == 0)
                    pin();

                else if (strcmp(a[0], "discover") == 0)
                    dis();

                else if (strcmp(a[0], "exit") == 0)
                    exit(0);

                else if (strcmp(a[0], "jobs") == 0)
                    jobs();

                else if (strcmp(a[0], "sig") == 0)
                    sig();

                else if (strcmp(a[0], "fg") == 0)
                    fg();

                else if (strcmp(a[0], "bg") == 0)
                    bg();

                else
                    fbg(kom, so, &count, &cd, &pro);
            }
            i++;
        }

        if (count % 2 != 0)
            printf("%s> ", e);
        else
            printf("%s> ", b);
    }

    return 0;
}