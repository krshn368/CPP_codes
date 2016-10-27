// SumofTuples.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<malloc.h>

void sos(int sum,int j,int tot,int *a,int *x,int n)
{
   int i;
   x[j]=1;
   if(sum+a[j]==n)
    {
       for(i=0; i<=j; i++)
       {
			if(x[i]==1)
			{
				printf("%d ",a[i]);
			}
       }
       printf("\n");
     }
	else if(sum+a[j]+a[j+1] <=n)
	sos(sum+a[j],j+1,tot-a[j],a,x,n);
    if((sum+tot-a[j]>=n)&&(sum+a[j+1])<=n)
    {               
      x[j]=0;
      sos(sum,j+1,tot-a[j],a,x,n);
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
	 int sum=0,i,num;
	 int *a,n,*x,k=0;
    printf("enter no of elements:");
    scanf("%d",&num);
	a=(int*)malloc(num*sizeof(int));
	x=(int*)malloc(num*sizeof(int));
    printf("Enter the elements in sorted order:");
    for(i=0; i<num; i++)
    scanf("%d",&a[i]);
    printf("Enter the required sum:");
    scanf("%d",&n);
    for(i=0; i<num; i++)
    sum +=a[i];
    if(sum < n)
    {
	printf("no solution exits\n");
    }
	else
	{
    printf("The solution is\n");
    sos(0,0,sum,a,x,n);
	}
	return 0;
}

