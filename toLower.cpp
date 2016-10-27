// toLower.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

struct test {
	char input[15];
	char output[15];
} testDB[7] = {	{"",""},
				{NULL,NULL},
				{"hEllO123","hello123"},
				{"HellO!@#","hello!@#"},
				{"HELLO","hello"},
				{"hello","hello"},
				{"Hello w  orld","hello w  orld"}
            };

void toLower(char* input)
{
	int i=0;
	while(input[i]!=0)
	{
		if(input[i]>='A' && input[i]<='Z')
		{
		input[i]=input[i]+('a'-'A');
		}
		i++;
	}
}

void testCases()
{
	for(int i=0; i<7; i++) {
		toLower(testDB[i].input);
		if(strcmp((testDB[i].input), testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}



