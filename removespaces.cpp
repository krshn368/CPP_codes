// removespaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

struct test {
	char input[30];
	char output[25];
} testDB[7] = {{NULL,NULL},
				{"",""},
				{" ",""},
				{"HelloWorld","HelloWorld"},
				{"Hello world","Helloworld"},
				{"Hello 123","Hello123"},
				{"H   e l l o w o r l d 1 !","Helloworld1!"}
				};


void stringRemoveSpaces(char* input)
{
	int i=0,j=0;
	while(input[i]!=0)
	{
		if(input[i]==' ')
		{
			i++;
			continue;
		}
		else
		{
			input[j]=input[i];
			j++;
			i++;
		}
	}
input[j]=0;
}

void testCases()
{
	for(int i=0; i<7; i++) {
		stringRemoveSpaces(testDB[i].input);
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}

