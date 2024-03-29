#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INI 10
#define MAX 100
#define JUMP 10
int count;
void Merge(int arr[], int l, int m, int r)
{
    int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	int arr1[n1], arr2[n2];
	
	for(i=0;i<n1;i++)
		arr1[i] = arr[l+i];
	for (i=0;i<n2;i++)
		arr2[i] = arr[m+i+1];
		
	i=0; j=0; k=l;
		
	while(i<n1 && j<n2){
		count++;
		if (arr1[i] <= arr2[j])
			arr[k++] = arr1[i++];
		else 
			arr[k++] = arr2[j++];
	}
	
	while(i<n1)
		arr[k++] = arr1[i++];
	while(j<n2)
		arr[k++] = arr2[j++];
}
void MergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(a, l, m);
        MergeSort(a, m + 1, r);
        Merge(a, l, m, r);
    }
}
int main()
{
    int n, arr[1000];
    FILE *bestms, *avgms,*worstms;
    system("rm bestms.txt");
    system("rm avgms.txt");
    system("rm worstms.txt");
    bestms = fopen("bestms.txt", "a");
    avgms = fopen("avgms.txt", "a");
    worstms = fopen("worstms.txt", "a");
    for (n = INI; n <= MAX; n = n + JUMP)
    {
        srand(time(NULL));
        count=0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = i + 1;
        }
        MergeSort(arr, 0, n - 1);
        fprintf(bestms, "%d %d\n", n, count);

        count=0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = rand()%1000;
        }
        MergeSort(arr, 0, n - 1);
        fprintf(avgms, "%d %d\n", n, count);

        count=0;
        for (int i = 0; i < n; i++)
        {
            arr[i] = i<n/2? rand()%10+1 : rand()%10+2;
        }
        MergeSort(arr, 0, n - 1);
        fprintf(worstms, "%d %d\n", n, count);
    }
    fclose(bestms);
    fclose(avgms);
    fclose(worstms);
    return 0;
}

