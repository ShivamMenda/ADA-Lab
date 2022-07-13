#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int count=0;

int fact(int n)
{
 if(n==0 || n==1)
 {
  return 1;
 }
 else
 {
   count++;
   return n*fact(n-1);
 }
}
void main()
{
 FILE *fp1;
 int i,n,f;
 system("rm fact.txt");
 srand(time(0));
 for(n=1;n<=10;n++)
 {
 	count=0;
   fp1=fopen("fact.txt","a");
   f=fact(n);
   fprintf(fp1,"%d\t\t%d\n",n,count);
   fclose(fp1);
 }
}
    
