// ChangingCase.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

struct test {
	char input[20];
	char output[20];
} testDB[12] = {{"ABC","abc"},
				{"abc","ABC"},
                {"AbC","aBc"},
                {"123","123"},
                {"",""},
                {"a1B2c","A1b2C"},
                {"a b c","A B C"},
                {"!@#$","!@#$"},
                {"A!@b","a!@B"},
                {"    ","    "},
            };
void changeCase(char* s)
{
	int i=0;
	while(s[i]!=0)
	{
		if(s[i]>='a' && s[i]<='z')
		{
			s[i]=s[i]-('a'-'A');
		}
		else if(s[i]>='A' && s[i]<='Z')
		{
			s[i]=s[i]+('a'-'A');
		}
		i++;
	}
}
void testCases()
{
	for(int i=0; i<10; i++) {
		changeCase(testDB[i].input);
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}

