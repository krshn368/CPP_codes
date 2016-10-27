// removeDigits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
void removeDigits(char *c);
struct test {
	char input[20];
	char output[20];
} testDB[12] = {{"ABC123","ABC"},
				{"12a34b56c","abc"},
                {"1Ab C2","Ab C"},
                {"123",""},
                {"",""},
                {"a1B2c","aBc"},
                {"a b c","a b c"},
                {"!@#$","!@#$"},
                {"A!1@2b","A!@b"},
                {"    ","    "},
				{"1a2b345CDef&8(&*","abCDef&(&*"}
            };
void testCases()
{
	for(int i=0; i<11; i++) {
		removeDigits(testDB[i].input);
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
void removeDigits(char *c)
{
	int i=0,j=0;
	while(c[i]!=0)
	{
		if(c[i]>='0' && c[i]<='9')
		{
			i++;
		}
		else
		{
			c[j]=c[i];
			i++;
			j++;
		}
	}
	c[j]='\0';
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}
