#include <stdio.h>
int table[100][100];
int v[100],w[100];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int mknap(int i,int j)
{
    int value;
    if(table[i][j]<0)
    {
        if(j<w[i])
        {
            
            value=mknap(i-1,j);
        }
        else
        {
            value=max(mknap(i-1,j),v[i]+mknap(i-1,(j-w[i])));
        }
        table[i][j]=value;
        
    }
    return table[i][j];
}

int main()
{
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity: ");
    scanf("%d", &capacity);
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter value and weight for %d item: ", i + 1);
        scanf("%d %d", &v[i], &w[i]);
    }
    for (int j = 0; j <=capacity; j++)
        table[0][j] = 0;
    for (int i = 0; i <=n; i++)
        table[i][0] = 0;
    for (int i = 1; i <=n; i++)
        for (int j = 1; j <=capacity; j++)
            table[i][j] = -1;
    
    printf("Max value: %d", mknap(n-1, capacity));
    return 0;
}