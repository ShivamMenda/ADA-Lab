#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count;

void sort(int a[],int n)
{
	int swapped=0;
	count=0;
	int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			count++;
			if(a[j]>a[j+1])
			{
				swapped=1;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		if (!swapped)
		{
			return;
		}
		
	}
	
}

int main()
{
	FILE *fp1,*fp2,*fp3;
	int n;
	int a[1000],b[1000];
	system("rm bs_best.txt");
	system("rm bs_worst.txt");
	system("rm bs_avg.txt");
	fp1=fopen("bs_best.txt","a");
	fp2=fopen("bs_worst.txt","a");
	fp3=fopen("bs_avg.txt","a");
	srand(time(0));
	int i;
	for(n=10;n<100;n=n+10)
	{
		count=0;
		for (i = 0; i < n; i++)
		{
			a[i]=i+1;
		}
		sort(a,n);
		fprintf(fp1,"%d\t%d\n",n,count);

		count=0;
		for (i = 0; i < n; i++)
		{
			a[i]=n-i+1;
		}
		sort(a,n);
		fprintf(fp2,"%d\t%d\n",n,count);

		count=0;
		for (i = 0; i < n; i++)
		{
			a[i]=rand()%100;
		}
		sort(a,n);
		fprintf(fp3,"%d\t%d\n",n,count);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}
