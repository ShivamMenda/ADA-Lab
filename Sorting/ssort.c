#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int count;

void selectionSort(int arr[], int n){
	int small;
	for(int i=0;i<n-1;i++){
		small=i;
		for(int j=i+1;j<n;j++){
			count++;	
			if (arr[j]<arr[small])
				small=j;
		}
		if (small!=i){
			int temp = arr[i];
			arr[i] = arr[small];
			arr[small]=temp;
		}
	}
}

int main(){
	int i,n;
	int arr[100];
	
	FILE *fp;
	system("rm a.txt");
	fp = fopen("a.txt","a");
	
	for(n=10;n<=100;n+=10){
		//Operation Count is the same for all cases
		count=0;
		for(i=0;i<n;i++){
			arr[i] = rand()%100;
		}
		selectionSort(arr,n);
		fprintf(fp,"%d\t%d\n", n, count);
	}
	
	fclose(fp);
}