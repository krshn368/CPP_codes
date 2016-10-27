// testconvertbinarytointeger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
//for NULL,any character input considering the output as zero.
struct testDB {
	char input[20];
	int output;
} 
testDB[15] = {
	{NULL,0},
	            {"",0},
				{"1111",15},
                {"0000",0},
                {"1010",10},
                {"  ",0},
                {"1",1},
                {"0",0},
                {"asda123",0},
                {"@#!1001",0},
			 };
void convertbinarytointeger(char* input,int *n)
{
	int i=0;
	while (input[i]!=0)
	{
		if(input[i]=='0' || input[i]=='1')
		{
		 *n=*n * 2;
		 if (input[i] == '1') 
			{
				 *n=*n+1;
			}
		}
		else
			break;
		i++;
	}
}
void testCases()
{
    int i,n;
	for(i=0; i<10; i++) 
	{
		n=0;
		convertbinarytointeger(testDB[i].input,&n);
		if(n==testDB[i].output) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}
