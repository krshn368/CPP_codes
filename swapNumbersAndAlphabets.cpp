// swapNumbersAndAlphabets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
#include<string.h>
struct test {
	char input[20];
	char output[20];
} testDB[10] = {
					{"123456","123456"},
					{"abc321","abc321"},
					{"231acb","acb231"},
					{"A12Bc4","ABc124"},
					{"abc%*123","abc%*123"},
					{"aaaa","aaaa"},
					{"111111","111111"},
					{"",""},
					{"abc 1%^&","abc %^&1"},
					{"    ","    "}
            };
void convertToAlpha_Numeric2(char *input){
	int i=0,j=0;char temp;
	while(input[i]!=0)
	{
			if(!(input[i]>='0' && input[i]<='9'))
			{
				temp=input[i];
				input[i]=input[j];
				input[j]=temp;
				j++;
			}
		i++;
	}
}
void testCases()
{
	for(int i=0; i<10; i++)
	{
		convertToAlpha_Numeric2(testDB[i].input);
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}

