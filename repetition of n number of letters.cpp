// repetition of n number of letters.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<string.h>
#include<malloc.h>
struct test{
	char input[20];
	char output[20];
	int repetition;
}testDB[10]={
				{{"abc"},{"aabbcc"},2},
				{{"a"},{"aaaaa"},5},
				{{"wxyz"},{"wwwwxxxxyyyyzzzz"},4},
				{{"xyz"},{"xyz"},1},
				{{"Rnd"},{"RRnndd"},2},
				{{NULL},{NULL}}
};
void repetitionOfLetters(int len,int r,char *input)
{
	int i=r*len-1,k=0,j=len-1;
	input[i+1]=0;
	while(j>=0)
	{
		for(k=0;k<r;k++)
			input[i--]=input[j];
		j--;
	}
}

void testcases()
{
	int i=0;
	for(i=0;i<5;i++)
	{
		repetitionOfLetters(strlen(testDB[i].input),testDB[i].repetition,testDB[i].input);
		if(strcmp(testDB[i].input,testDB[i].output)==0)
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


