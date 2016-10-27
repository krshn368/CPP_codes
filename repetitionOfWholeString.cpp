// repetitionOfWholeString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
#include<string.h>
struct tests
{
	char  input[100];
	int n ;
	char  result[100];
}test[12]={
			{"abc",3,"abcabcabc"}, //input contains lowercase letters
			{"ABC",3,"ABCABCABC"}, //contains uppercase letters
			{"ABc",4,"ABcABcABcABc"}, //both upper and lower case letters
			{"123",3,"123123123"}, //contains numbers
			{"!@#$",2,"!@#$!@#$"}, //special characters
			{"A12d",2,"A12dA12d"}, //combination of alphabet and letters
			{NULL,3,NULL},
			{"a s d" ,2 ,"a s da s d"},
			{ " " , 3 ,"   "}
}; 

void ImagingString(char *input , int n)
{
	int len=strlen(input),j,k=0,i=0;
	while(k<n)
	{
		j=0;
		while(j<len)
		{
			input[i++]=input[j++];
		}
		k++;
	}
	input[i]=0;
}
void teststub()
{
	for(int index=0 ;index<9;index++)
	{
		ImagingString(test[index].input , test[index].n );
		if(strcmp(test[index].input,test[index].result)==0)
           printf("passed\n");
		else
			printf("failed\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	teststub();
	return 0;
}

