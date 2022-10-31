#include "global.h"

void his(int *k)
{
    strcpy(path, c);
    strcat(path, "/history.txt");
    FILE *fp = fopen(path, "w");
    int j = 0;

    if (*k == 0)
    {
        while (j != strlen(h))
        {
            ht[*k][j] = h[j];
            j++;
        }
        ht[*k][j] = '\0';

        *k = *k + 1;
        for (int i = 0; i < *k; i++)
            fprintf(fp, "%s\n", ht[i]);

        fclose(fp);
    }

    else if ((*k > 0) && (*k < 20))
    {
        if (strcmp(h, ht[*k - 1]))
        {
            while (j != strlen(h))
            {
                ht[*k][j] = h[j];
                j++;
            }
            ht[*k][j] = '\0';

            *k = *k + 1;
        }

        for (int i = 0; i < *k; i++)
            fprintf(fp, "%s\n", ht[i]);

        fclose(fp);
    }

    else if (*k == 20)
    {
        if (strcmp(h, ht[*k - 1]))
        {
            while (j != strlen(h))
            {
                ht[*k][j] = h[j];
                j++;
            }
            ht[*k][j] = '\0';

            for (int i = 1; i <= *k; i++)
                fprintf(fp, "%s\n", ht[i]);

            fclose(fp);
            *k = 0;
            FILE *fp1 = fopen(path, "r");

            while (1)
            {
                int r = fscanf(fp1, "%[^\n]%*c", ht[*k]);
                if ((r == 0) || (r == -1))
                    break;

                *k = *k + 1;
            }
            fclose(fp1);
        }

        else
        {
            for (int i = 0; i < *k; i++)
                fprintf(fp, "%s\n", ht[i]);

            fclose(fp);
        }
    }
}

void print(int *k)
{
    if (*k <= 10)
    {
        for (int j = 0; j < *k; j++)
            printf("%s\n", ht[j]);
    }

    else if ((*k > 10) && (*k <= 20))
    {
        for (int j = *k - 10; j < *k; j++)
            printf("%s\n", ht[j]);
    }

    else
    {
        for (int j = *k - 20; j <= *k; j++)
            printf("%s\n", ht[j]);
    }
}
