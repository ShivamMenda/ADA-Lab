#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count;
void insertion(int a[],int n)
{
	count=0;
	int i,j,v;
	for(i=1,i<=n-1;i++)
	{
		v=a[i];
		j=i-1;
		while(j>=0 && a[j]<v)
		{
			a[j+1]=a[j];
			j--;
			count++;
		}
	if(j==1)
	{
		continue
	}
count++;
a[j+1]=v;
}
}
void insertmain(int ch)
{
	FILE *a;
	int i,j,*arr;
	srand(time(NULL));
	if(ch==1)
	{
		
