// encodedString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

struct test {
	char input[30];
	char output[30];
} testDB[8] = {{NULL,NULL},
				{"",""},
				{"abc","123"},
				{"ABCD","1234"},
				{"aBcD","1234"},
				{"a@bc$","123"},
                {"a1@b2c$","123"},
                {"a 1@A$","11"}
				};


void encode(char* s)
{
	int i=0,j=0;
	while(s[i]!=0)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			s[j]=s[i]-'a'+'1';
			i++;
			j++;
		}
		else if(s[i]>='A' && s[i]<='Z')
		{
			s[j]=s[i]-'A'+'1';
			i++;
			j++;
		}
		else
			i++;
	}
	s[j]='\0';
}

void testCases()
{
	for(int i=0; i<8; i++) {
		encode(testDB[i].input);
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}

