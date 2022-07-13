// Fibonacci Numbers
#include <stdio.h>
#include <stdlib.h>

int count=0;

int fib(int n)
{
  if (n==0 || n==1)
  	return n;
  else
  {
  	count++;
  	return fib(n-1)+fib(n-2);
  }
}

void main()
{
  FILE *fp1;
  int n,f;
  for (n=1;n<=10;n++)
  {
    fp1=fopen("fib.txt","a");
    count=0;
    f=fib(n);
    fprintf(fp1,"%d\t%d\t\n",n,count);
    fclose(fp1);
  }
}
