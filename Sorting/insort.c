#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INITIAL 10
#define FINAL 100
#define INCRE 10
int count = 0;

void insertionsort(int *arr, int n)
{
  int i;
  for (i = 1; i < n; i++)
  {
    int v = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j]>v)
    {
      count++;
      // if (arr[j] < v)
      //   break;
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = v;
  }
  return;
}
void main()
{
  int *arr, n, i;
  FILE *fp1, *fp2, *fp3;
  system("rm BEST_CASE_COUNT.txt");
  system("rm AVERAGE_CASE_COUNT.txt");
  system("rm WORST_CASE_COUNT.txt");

  srand(time(NULL));
  for (n = INITIAL; n <= FINAL; n += INCRE)
  {
    arr = (int *)malloc(n * sizeof(int));

    count = 0;
    for (i = 0; i < n; i++)
      arr[i] = i + 1;
    insertionsort(arr, n);
    fp1 = fopen("best.txt", "a");
    fprintf(fp1, "%d\t", n);
    fprintf(fp1, "%d\n", count);
    count = 0;

    for (i = 0; i < n; i++)
      arr[i] = rand() % n;
    insertionsort(arr, n);
    fp2 = fopen("avg.txt", "a");
    fprintf(fp2, "%d\t", n);
    fprintf(fp2, "%d\n", count);
    count = 0;

    for (i = 0; i < n; i++)
      arr[i] =n-i+1;
    insertionsort(arr, n);
    fp3 = fopen("worst.txt", "a");
    fprintf(fp3, "%d\t", n);
    fprintf(fp3, "%d\n", count);
  }
}