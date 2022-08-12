#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;

void insertionsort(int arr[], int n,int isBest)
{
  int i,j;
  for (i = 1; i < n; i++)
  {
    int v = arr[i];
    int j = i - 1;
    if (isBest==1)
    {
      count++;
    }
    
    while (j >= 0 && arr[j]>v)
    {
      count++;
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = v;
  }
  return;
}
int main()
{
  int arr[100], n, i;
  FILE *fp1, *fp2, *fp3;
  system("rm in_best.txt");
  system("rm in_avg.txt");
  system("rm in_worst.txt");

  srand(time(NULL));
  for (n = 10; n <= 100; n += 10)
  {
    count = 0;
    for (i = 0; i < n; i++)
      arr[i] = i ;
    insertionsort(arr, n,1);
    fp1 = fopen("in_best.txt", "a");
    fprintf(fp1, "%d\t", n);
    fprintf(fp1, "%d\n", count);
    count = 0;

    for (i = 0; i < n; i++)
      arr[i] = rand() % n;
    insertionsort(arr, n,0);
    fp2 = fopen("in_avg.txt", "a");
    fprintf(fp2, "%d\t", n);
    fprintf(fp2, "%d\n", count);
    count = 0;

    for (i = 0; i < n; i++)
      arr[i] =n-i+1;
    insertionsort(arr, n,0);
    fp3 = fopen("in_worst.txt", "a");
    fprintf(fp3, "%d\t", n);
    fprintf(fp3, "%d\n", count);
  }
}