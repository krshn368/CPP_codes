// stairs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>

bool FindPath(char** a,int i,int j)
{
	a[1][0]=' ';
	if((i<0 || i>(2*n)) || (j<0 || j>(4*m)))
		return false;
	if(i==(2*n-1) && j==(4*m-2))
	{
		a[i][j]=' ';
		a[i][j+2]=' ';
		return true;
	}
	if(a[i][j]!='1')
		return false;
	a[i][j]=' ';
	if(FindPath(a,i,j-4)==true)
	{
		a[i][j-2]=' ';
		return true;
	}
	if(FindPath(a,i-2,j)==true)
	{
		a[i-1][j-1]=' ';
		a[i-1][j]=' ';
		a[i-1][j+1]=' ';
		return true;
	}
	if(FindPath(a,i,j+4)==true)
	{
		a[i][j+2]=' ';
		return true;
	}
	if(FindPath(a,i+2,j)==true)
	{
		a[i+1][j-1]=' ';
		a[i+1][j]=' ';
		a[i+1][j+1]=' ';
		return true;
	}
	a[i][j]='+';
	return false;	
}
char** arrangeMaze(char **b,int* a)
{int i,j,k,o,l=0;
j=(4*m)+1;
o=(2*n)+1;
for(i=0;i<o;i++)
{
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
return b;
}
char* readinput(int *rows,int *col)
{
	int maxlen;
	printf("enter maxlength:");
	scanf("%d",&maxlen);
	fflush(stdin);
	char* s=(char*)malloc(maxlen+1);
	printf("Enter String:");
	gets(s);
	return s;
}

int _tmain(int argc, _TCHAR* argv[])
{int *a;int i,j,k,o,l=0,rows,cols;char **b;bool path;
printf("enter rows");
scanf("%d",&rows);
printf("enter cols");
scanf("%d",&cols);
a=(int*)malloc((rows*cols)*sizeof(int));
for(i=0;i<(n*m);i++)
	scanf("%d",&a[i]);
o=2*rows+1;
b=(char**)malloc(o*sizeof(char*));
j=cols*4+1;
for(i=0;i<o;i++)
	b[i]=(char*)malloc(j*sizeof(char));
b=arrangeMaze(b,a);	
for(i=0;i<o;i++)
{
	for(k=0;k<j;k++)
		printf("%c",b[i][k]);
	printf("\n");
}
path=FindPath(b,1,2);
for(i=0;i<o;i++)
{
	for(k=0;k<j;k++)
		printf("%c",b[i][k]);
	printf("\n");
}
	return 0;
}

