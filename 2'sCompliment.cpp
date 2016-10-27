// 2'scomliment.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<malloc.h>
#include<string.h>
struct test{
	int input;
	char output[17];
}testDB[5]={
	{-126,"1111111110000010"},
	{-1,"1111111111111111"},
	{-100,"1111111110011100"},
	{1,""},
	{-999,"1111110000011001"}
};
void complement(int n,char *s)
{
	int i=15;
	char carry='1';
	while(i>=0)
	{
		s[i]=-(n%2)+'0';
		n=n/2;
		if(s[i]=='0')
		{
			s[i]='1';
		}
		else
		{
			s[i]='0';
		}
		i--;
	}
	s[16]=0;
	i=15;
	while(carry-'0' && i>=0){
		if(s[i]=='1')
		{
			s[i]='0';
			carry='1';
		}
		else
		{
			s[i]=carry;
			carry='0';
		}
		i--;
	}
}
void testcases(){
	int i=0;
	char *result=(char *)malloc(sizeof(char)*16);
	for(i=0;i<5;i++){
		if(testDB[i].input>=0){
			printf("invalid input\n");
			continue;
		}
		complement(testDB[i].input,result);
		if(strcmp(result,testDB[i].output)==0)
			printf("PASSED\n");
		else
			printf("FAILED\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}