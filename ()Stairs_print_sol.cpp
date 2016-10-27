#include "stdafx.h"
#include<string.h>
#include<malloc.h>
void putPath(int n,char* c)
{
	int i=strlen(c);
	if(n==0)
	{
		c[i]=0;
		printf("%s\n",c);
		return;
	}
	if(n>=1)
	{
		putPath(n-1,strcat(c,"s"));
		c[i]=0;	
		if(n-2>=0)
				putPath(n-2,strcat(c,"d"));
		c[i-1]=0;
	}return;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	printf("Enter no. of stairs:");
	scanf("%d",&n);
	char* c=(char*)malloc(10);
	c[0]=0;
	putPath(n,c);
	return 0;
}

