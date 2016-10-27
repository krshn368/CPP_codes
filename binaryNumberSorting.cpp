// testsortedbinary.cpp : Defines the entry point for the console application.
//returning same string if its invalid.

#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

struct test {
	char input[20];
	char output[20];
} testDB[12] = {{NULL,NULL},
				{"000","000"},
                {"1111","1111"},
                {"10101","00111"},
                {"  ","  "},
                {"hgkj123","hgkj123"},
                {"&^*!@hs","&^*!@hs"},
                {"!@#$1010","!@#$1010"},
                {"1232","1232"},
                {"",""},
                {"00011","00011"},
                {"111110","011111"}
                
            };
void sortedbinary(char*input)
{
	int i=0,j=0;char temp;
	while(input[i]!=0)
	{
		if(input[i]=='1' || input[i]=='0')
		{
			if(input[i]=='0')
			{
				temp=input[i];
				input[i]=input[j];
				input[j]=temp;
				j++;
			}
		}
		else
			break;
		i++;
	}
}
void testCases()
{
	for(int i=0; i<12; i++) {
		sortedbinary(testDB[i].input);
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}


