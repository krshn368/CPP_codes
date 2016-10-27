#include "stdafx.h"
#include<malloc.h>
void TwoDBoxes(char **b,int *a,int o,int j)
{
	int i=0,k,l=0;
	for(i=0;i<o;i++)
	{
		b[i]=(char*)malloc(j*sizeof(char));
		for(k=0;k<j;k++)
		{
			if(i%2==0)
				b[i][k]='-';
			else
			{
				if(k%4==0)
					b[i][k]='|';
				else if(k%4==1 || k%4==3)
					b[i][k]=' ';
				else
				{
					if(a[l]==1)
						b[i][k]='1';
					else
						b[i][k]='0';
					l++;
				}
			}
		}
	}
}
void display(char **b,int o,int j)
{
	int i=0,k;
	for(i=0;i<o;i++)
	{
		for(k=0;k<j;k++)
			printf("%c",b[i][k]);
		printf("\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
int *a;int n,m,i,j,k,o,l=0;char **b;
printf("enter rows");
scanf("%d",&n);
printf("enter cols");
scanf("%d",&m);
a=(int*)malloc((n*m)*sizeof(int));
for(i=0;i<(n*m);i++)
	scanf("%d",&a[i]);
o=2*n+1;
b=(char**)malloc(o*sizeof(char*));
j=m*4+1;
TwoDBoxes(b,a,o,j);
display(b,o,j);
	return 0;
}

