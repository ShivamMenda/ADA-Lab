#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count=0;

void heapify(int a[],int n,int i)
{
    count++;
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[largest])
    {
        largest=left;
    }
    if (right<n && a[right]>a[largest])
    {
        largest=right;
    }
    if (largest!=i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;

        heapify(a,n,largest);
        
    }  
}

void sort(int a[],int n)
{
    for (int i = n/2-1; i>=0; i--)
    {
        heapify(a,n,i);
    }
    for (int i = n-1; i >=0; i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    } 
}
int main()
{
    int heap[100],n,i;
    FILE *fp1,*fp2,*fp3;
    system("rm besth.txt");
    system("rm avgh.txt");
    system("rm worsth.txt");
    srand(time(NULL));
    fp1=fopen("besth.txt","a");
    fp2=fopen("avgh.txt","a");
    fp3=fopen("worsth.txt","a");
    for (n = 0; n <=25; n=n+5)
    {
        for (i = 0; i < n; i++)
        {
            heap[i]=i+1;
        }
        sort(heap,n);
        fprintf(fp1,"%d\t %d\n",n,count);
        for (i = 0; i < n; i++)
        {
            heap[i]=rand()%n;
        }
        sort(heap,n);
        fprintf(fp2,"%d\t %d\n",n,count);

        for (i = 0; i < n; i++)
        {
            heap[i]=n-i+1;
        }
        sort(heap,n);
        fprintf(fp3,"%d\t %d\n",n,count);
        
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}