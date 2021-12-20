#include <stdio.h>

void stergeLinie(int a[][64], int len, int x)
{
    for (int i = 0; i < len; i++)
        for (int j = x - 1; j < len - 1; j++)
            a[i][j] = a[i][j + 1];
    for (int i = x - 1; i < len - 1; i++)
        for (int j = 0; j < len; j++)
            a[i][j] = a[i + 1][j];
}

int compareMatrix(int a[][64], int len, int b[][64])
{
    int OK = 1;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
            if (a[i][j] != b[i][j])
            {
                OK = 0;
                break;
            }
        if (OK == 0)
            break;
    }
    return OK;
}

int main()
{
    FILE *pFile = fopen("graf.in", "r"), *qFile = fopen("graf.out", "w");
    int K, K2, V[4], E[4];
    fscanf(pFile, "%d", &K);
    fscanf(pFile, "%d", &K2);
    fscanf(pFile, "%d%d", &V[0], &E[0]);
    int a[64][64];
    for (int j = 0; j < V[0]; j++)
        for (int k = 0; k < V[0]; k++)
            a[j][k] = 0;
    for (int j = 0; j < E[0]; j++)
    {
        int x, y;
        fscanf(pFile, "%d%d", &x, &y);
        a[x - 1][y - 1] = 1;
        a[y - 1][x - 1] = 1;
    }
    for (int k = 0; k < V[0]; k++)
        fprintf(qFile, "%d ", k + 1);
    fprintf(qFile, "\n");
    for (int i = 1; i < K; i++)
    {
        fscanf(pFile, "%d%d", &V[i], &E[i]);
        int b[64][64];
        for (int j = 0; j < V[i]; j++)
            for (int k = 0; k < V[i]; k++)
                b[j][k] = 0;
        for (int j = 0; j < E[i]; j++)
        {
            int x, y;
            fscanf(pFile, "%d%d", &x, &y);
            b[x - 1][y - 1] = 1;
            b[y - 1][x - 1] = 1;
        }
        int noduriEliminate = V[i] - K2;
        if (noduriEliminate < 0)
        {
            fprintf(qFile, "-1\n");
            break;
        }
        int liniiInitiale[8];
        for (int j = 0; j < V[i]; j++)
            liniiInitiale[j] = j + 1;
        if (noduriEliminate == 0)
        {
            int b1[64][64];
            for (int k = 0; k < V[i]; k++)
                for (int l = 0; l < V[i]; l++)
                    b1[k][l] = b[k][l];
            if (compareMatrix(a, K2, b1))
            {
                for (int k = 0; k < V[i]; k++)
                    fprintf(qFile, "%d ", liniiInitiale[k]);
            }
        }
        else if (noduriEliminate == 1)
        {
            for (int j1 = 0; j1 < V[i]; j1++)
            {
                int b1[64][64];
                for (int k = 0; k < V[i]; k++)
                    for (int l = 0; l < V[i]; l++)
                        b1[k][l] = b[k][l];
                stergeLinie(b1, V[i], liniiInitiale[j1]);
                if (compareMatrix(a, K2, b1))
                {
                    for (int k = 0; k < V[i]; k++)
                        if (k != j1)
                            fprintf(qFile, "%d ", liniiInitiale[k]);
                    fprintf(qFile, "\n");
                }
            }
        }
        else if (noduriEliminate == 2)
        {
            for (int j1 = 0; j1 < V[i]; j1++)
                for (int j2 = j1 + 1; j2 < V[i]; j2++)
                {
                    int b1[64][64];
                    for (int k = 0; k < V[i]; k++)
                        for (int l = 0; l < V[i]; l++)
                            b1[k][l] = b[k][l];
                    if (j2 < j1)                                    // }
                    {                                               // }
                        stergeLinie(b1, V[i], liniiInitiale[j1]);   // }
                        stergeLinie(b1, V[i], liniiInitiale[j2]);   // }
                    }                                               // } O(k *
                    else                                            // } V[i]^4)
                    {                                               // }
                        stergeLinie(b1, V[i], liniiInitiale[j2]);   // }
                        stergeLinie(b1, V[i], liniiInitiale[j1]);   // }
                    }                                               // }
                    if (compareMatrix(a, K2, b1))
                    {
                        for (int k = 0; k < V[i]; k++)
                            if (k != j1 && k != j2)
                                fprintf(qFile, "%d ", liniiInitiale[k]);
                        fprintf(qFile, "\n");
                    }
                }
        }
    }
    fclose(pFile);
    fclose(qFile);
    return 0;
}