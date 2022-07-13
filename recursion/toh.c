#include<stdio.h>
#include<stdlib.h>

int count=0;

void move(int n,char a,char b,char c)
{
	if(n==1)
	{
		printf("Move from %c to %c\n",a,c);
		count++;
	}
	else
	{
	move(n-1,a,c,b);
	printf("move from %c to %c\n",a,c);
	count++;
	move(n-1,b,a,c);
	}
}

int main()
{
	int i;
	FILE *fp;
	for(i=1;i<=10;i++)
	{
		count=0;
		printf("Disk number %d\n",i);
		fp=fopen("hanoi.txt","a");
		move(i,'a','b','c');
		fprintf(fp,"%d\t\t%d\n",i,count);
		fclose(fp);
	}
}
