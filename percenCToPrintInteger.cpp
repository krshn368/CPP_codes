// percenCToPrintInteger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<math.h>
#include<malloc.h>
#include<string.h>
struct tests
{
	int  input;
	char result[10];
	int length;
}testDB[7]={{-12345,{"-12345"},5},
{12,{"12"},2},
{9,{"9"},1},
{98765012,{"98765012"},8},
{0,{"0"},1},
{-2345,{"-2345"},4},
{-123,{"-123"},3}
};
void intfromc(int n,int len,char *c)
{
	int i=0,j=0,div;
	int r;
	if(n==0)
	{
		printf("0");
		c[i]='0';
		c[i+1]=0;
		return ;
	}
	else if(n<0)
	{
		printf("-");
		n=-n;
		c[i]='-';
		i++;
	}
	while(n>0)
	{
		len--;
		div=(int)pow(10.0,len);
		r=n/div;
		c[i]=r+'0';
		printf("%c",r+'0');
		n=n%div;
		i++;
	}
	c[i]=0;
}
void testcases()
{
	int i=0;
	for(i;i<7;i++)
	{
		char *in=(char *)malloc(sizeof(char)*10);
		intfromc(testDB[i].input,testDB[i].length,in);
		if(strcmp(testDB[i].result,in)==0)
			printf(" PASSED\n");
		else
			printf(" FAILED\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}