#include <stdio.h>

int main()
{
    FILE *pFile = fopen("graf.in", "r");
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
    printf("Matricea de adiacenta a celui de-al %d-lea graf:\n", 1);
    for (int j = 0; j < V[0]; j++)
    {
        for (int k = 0; k < V[0]; k++)
            printf("%d ", a[j][k]);
        printf("\n");
    }
    printf("\n");

    
    for (int i = 1; i < K; i++)
    {
        fscanf(pFile, "%d%d", &V[i], &E[i]);
        int a[64][64];
        for (int j = 0; j < V[i]; j++)
            for (int k = 0; k < V[i]; k++)
                a[j][k] = 0;
        for (int j = 0; j < E[i]; j++)
        {
            int x, y;
            fscanf(pFile, "%d%d", &x, &y);
            a[x - 1][y - 1] = 1;
            a[y - 1][x - 1] = 1;
        }
        printf("Matricea de adiacenta a celui de-al %d-lea graf:\n", i + 1);
        for (int j = 0; j < V[i]; j++)
        {
            for (int k = 0; k < V[i]; k++)
                printf("%d ", a[j][k]);
            printf("\n");
        }
        printf("\n");
    }
    fclose(pFile);
    return 0;
}