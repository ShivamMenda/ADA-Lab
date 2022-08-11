#include<stdio.h>
#include<stdlib.h>

int count = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int first, int last){
    int i = first, j = last;
    int p = i;

    while ( i<j ){
        while (arr[i]<=arr[p]){
            ++i;
            ++count;
        }
        while (arr[j]>arr[p]){
            --j;
            ++count;
        }
        if ( i<j )
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[p], &arr[j]);
    return j;
}

void divide(int arr[], int first, int last){
    if (first < last){
        int pi = partition(arr, first, last);

        divide(arr, first, pi - 1);
        divide(arr, pi + 1, last);
    }
}

void best(int arr[], int first, int last){
    if ( first < last ){
        int mid = (first+last)/2;

        best(arr, first, mid - 1);
        swap(&arr[first], &arr[mid]);
        best(arr, mid + 1, last);
    }
}

void main(){
    FILE *a, *b, *w;
    system("rm best.txt;    rm worst.txt;   rm avg.txt");
    a = fopen("avg.txt", "a");
    b = fopen("best.txt", "a");
    w = fopen("worst.txt", "a");

    for(int n = 10; n<=100; n+=10){
        int arr[n];

        // worst case
        for(int i = 0; i<n; ++i)
            arr[i] = n - i;
        divide(arr, 0, n-1);
        fprintf(w, "%d  %d\n", n, count);
        count = 0;

        // avg case
        for(int i = 0; i<n/2; ++i)
            arr[i] = rand()%100;
        divide(arr, 0, n-1);
        fprintf(a, "%d  %d\n", n, count);
        count = 0;

        // best case
        best(arr, 0, n-1);
        divide(arr, 0, n-1);
        fprintf(b, "%d  %d\n", n, count);
        count = 0;
    }
    fclose(a);  
    fclose(b);  
    fclose(w);
}