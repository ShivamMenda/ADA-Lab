#include <stdio.h>
#include <stdlib.h>
#define INITIAL 10
#define FINAL 100
#define INCRE 10
int count = 0;

int naivestring(int *text, int *pattern, int n, int m)
{
    int i, j, pos;
    for (i = 0; i <= (n - m); i++)
    {
        j = 0;
        while (j < m)
        {
            count++;
            if (pattern[j] != text[(i + j)])
                break;
            j++;
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}

void main()
{
    int *text, pattern[4], n, i, pos;
    FILE *fp1, *fp2, *fp3;
    system("rm BEST_CASE_COUNT.txt");
    system("rm AVERAGE_CASE_COUNT.txt");
    system("rm WORST_CASE_COUNT.txt");
    for (n = INITIAL; n <= FINAL; n += INCRE)
    {
        text = (int *)malloc(n * sizeof(int));
        for (i = 0; i < (n - 1); i++)
        {
            text[i] = 0;
        }
        text[(n - 1)] = 1;
        // For Best Case
        for (i = 0; i < 4; i++)
        {
            pattern[i] = 0;
        }
        pos = naivestring(text, pattern, n, 4);
        fp1 = fopen("BEST_CASE_COUNT.txt", "a");
        fprintf(fp1, "%d\t", n);
        fprintf(fp1, " %d\n", count);
        count = 0;

        // For Worst Case
        pattern[3] = 1;
        pos = naivestring(text, pattern, n, 4);
        fp2 = fopen("WORST_CASE_COUNT.txt", "a");
        fprintf(fp2, "%d\t", n);
        fprintf(fp2, " %d\n", count);
        count = 0;

        // For Average Case
        for (i = 0; i < 4; i++)
        {
            pattern[i] = rand() % 2;
        }
        pos = naivestring(text, pattern, n, 4);
        fp3 = fopen("AVERAGE_CASE_COUNT.txt", "a");
        fprintf(fp3, "%d\t", n);
        fprintf(fp3, " %d\n", count);
        count = 0;
    }
}