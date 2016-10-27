// tobase4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
void tobase4(char *c);
struct test {
	char input[20];
	char output[20];
} testDB[6] = { {"",""},
				{NULL,NULL},
				{"1001","21"},
                {"12345","12345"},
                {"-10","-10"},
                {"234^%$","234^%$"}
            };
int isBinary(char* s)
{
	int i=0;
	while(s[i]!=0)
	{
		if(s[i]=='1' || s[i]=='0')
		{
			i++;
		}
		else
		{
			return 0;
			break;
		}
	}
	return 1;
}
void testCases()
{
	for(int i=0; i<6; i++) {
		tobase4(testDB[i].input);
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
void tobase4(char *s)
{
	int l=strlen(s),k,i,j=0;
	k=i=(l%2==0)?0:1;
	if(isBinary(s))
	{
		while(i<l)
		{
			if(s[i]=='0' && s[i+1]=='0')
			s[k++]='0';
			else if(s[i]=='0' && s[i+1]=='1')
			s[k++]='1';
			else if(s[i]=='1'&& s[i+1]=='0')
			s[k++]='2';
			else
			s[k++]='3';
			i+=2;
		}
 		s[k]=NULL;
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}

