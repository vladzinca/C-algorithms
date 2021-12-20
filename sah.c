#include <stdio.h>

void problemaDamelor(int N, int v[])
{
    if (N == 1)
        v[1] = 1;
    else if (N % 2 == 0)
    {
        if (N % 6 != 2)
            for (int i = 1; i <= N / 2; i++)    // }
            {                                   // }
                v[i] = 2 * i;                   // } O(n)
                v[N / 2 + i] = 2 * i - 1;       // }
            }                                   // }
        else if (N % 6 != 0)
            for (int i = 1; i <= N / 2; i++)                    // }
            {                                                   // }
                v[i] = 1 + (2 * i + N / 2 - 3) % N;             // } O(n)
                v[N + 1 - i] = N - (2 * i + N / 2 - 3) % N;     // }
            }                                                   // }
    }
    else
    {
        N--;
        if (N % 6 != 2)
            for (int i = 1; i <= N / 2; i++)    // }
            {                                   // }
                v[i] = 2 * i;                   // } O(n)
                v[N / 2 + i] = 2 * i - 1;       // }
            }                                   // }
        else if (N % 6 != 0)
            for (int i = 1; i <= N / 2; i++)                // }
            {                                               // }
                v[i] = 1 + (2 * i + N / 2 - 3) % N;         // } O(n)
                v[N + 1 - i] = N - (2 * i + N / 2 - 3) % N; // }
            }                                               // }
        N++;
        v[N] = N;
    }
}

int main()
{
    FILE *pFile = fopen("sah.in", "r");
    FILE *qFile = fopen("sah.out", "w");
    int N;
    fscanf(pFile, "%d", &N);
    int v[N + 1];
    if (N == 0 || N == 2 || N == 3)
    {
        fprintf(qFile, "imposibil\n");
        goto end;
    }
    problemaDamelor(N, v);                      // } O(n)
    for (int i = 1; i <= N; i++)                            // } O(n)
        fprintf(qFile, "(%d, %d)\n", i, v[i]);              // }
end:
    fclose(pFile);
    fclose(qFile);
    return 0;
}