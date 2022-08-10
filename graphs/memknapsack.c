#include<stdio.h>
 
#include<stdlib.h>
 
 
int n,table[100][100],cap,wt[100]={0},val[100]={0};
 
 
int max(int a,int b){
 
    return (a>b)?a:b;
 
}
 
 
int knapsack(int i,int j){
 
    int value;
 
 
    if(table[i][j]== -1){
 
        if(j<wt[i])
 
            value = knapsack(i-1,j);
 
 
        else{
 
            value = max(knapsack(i-1,j),val[i]+knapsack(i-1,j-wt[i]));
 
        }
 
        table[i][j]=value;
 
    }
 
    return table[i][j];
 
}
 
 
void main(){
 
    printf("Enter the number of items: ");
 
    scanf("%d",&n);
 
 
    printf("Enter capacity of sack: ");
 
    scanf("%d",&cap);
 
 
    for(int i=1;i<=n;i++){
 
        printf("Enter the weight of item %d: ",i);
 
        scanf("%d",&wt[i]);
 
 
        printf("Enter the value of item %d: ",i);
 
        scanf("%d",&val[i]);
 
    }
 
 
    for(int i=0;i<=n;i++){
 
        for(int j=0;j<=cap;j++){
 
            if(i==0 || j==0)
 
                table[i][j]=0;
 
            else
 
                table[i][j]=-1;
 
        }
 
    }
 
 
    printf("Maximum value of knapsack is : %d",knapsack(n,cap));
 
}