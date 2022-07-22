#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, j;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (j - wt[i - 1] >=0)
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]],
                              K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    }

    return K[n][W];
}

int main()
{
    int n, val[100], wt[100], capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity: ");
    scanf("%d", &capacity);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter value and weight for %d item: ", i + 1);
        scanf("%d %d", &val[i], &wt[i]);
    }
    printf("maximum value: %d\n", knapSack(capacity, wt, val, n));
    return 0;
}