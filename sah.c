#include <stdio.h>

void problemaDamelor(int N, int v[])
{
    if (N == 0 || N == 2 || N == 3)
    {
        printf("imposibil\n");
        return;
    }
    else if (N == 1)
    {
        v[1] = 1;
    }
    if (N % 2 == 0)
    {
        if (N % 6 != 2)
        {
            for (int i = 1; i <= N / 2; i++)
            {
                v[i] = 2 * i;
                v[N / 2 + i] = 2 * i - 1;
            }
        }
        else if (N % 6 != 0)
        {
            for (int i = 1; i <= N / 2; i++)
            {
                v[i] = 1 + (2 * i + N / 2 - 3) % N;
                v[N + 1 - i] = N - (2 * i + N / 2 - 3) % N;
            }
        }
        for (int i = 1; i <= N; i++)
            printf("(%d, %d)\n", i, v[i]);
        printf("\n");
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
                if (v[i] == j)
                    printf("X ");
                else
                    printf("O ");
            printf("\n");
        }
    }
    else
    {
        N--;
        if (N % 6 != 2)
        {
            for (int i = 1; i <= N / 2; i++)
            {
                v[i] = 2 * i;
                v[N / 2 + i] = 2 * i - 1;
            }
        }
        else if (N % 6 != 0)
        {
            for (int i = 1; i <= N / 2; i++)
            {
                v[i] = 1 + (2 * i + N / 2 - 3) % N;
                v[N + 1 - i] = N - (2 * i + N / 2 - 3) % N;
            }
        }
        N++;
        v[N] = N;
        for (int i = 1; i <= N; i++)
            printf("(%d, %d)\n", i, v[i]);
        printf("\n");
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
                if (v[i] == j)
                    printf("X ");
                else
                    printf("O ");
            printf("\n");
        }
    }
}

int main()
{
    // FILE *pFile = fopen("sah.in", "r"), *qFile = fopen("sah.out", "w");
    int N;
    // fscanf(pFile, "%d", &N);
    scanf("%d", &N);
    int v[N + 1];
    problemaDamelor(N, v);
    // fclose(pFile);
    // fclose(qFile);
}