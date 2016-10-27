// prependChar.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<string.h>

/*
	Specs
	-------
	1.string can contain any characters
	2.prepend character can contain any characters
	3.prepend character should not be empty character '\0'
*/
struct test{
	char input[30];
	char prependchar;
	char output[30];
}testDB[13] = {{NULL,'a',NULL},
{"",'z',"z"},
{"abcdefgh",'q',"qabcdefgh"},
{"abcdefgh",'!',"!abcdefgh"},
{"12345",'0',"012345"},
{"@@#$#%",'*',"*@@#$#%"},
{"12345@#$%",'!',"!12345@#$%"},
{"abcdef123^&*",'w',"wabcdef123^&*"},
{"",'\0',""},
{"abcdefgh",' '," abcdefgh"},
{"        ",' ',"         "},
{"         ",'z',"z         "},
{"ADSFGJU",'B',"BADSFGJU"}
};

void prependChar(char *input,char char_to_be_prepended)
{
	int i=0,j=0;
	int k=strlen(input)+1;
	for(i=k;i>=0;i--)
	{
		input[i+1]=input[i];		
	}
	
	input[0]=char_to_be_prepended;
}
void testCases()
{
	for(int i=0; i<13; i++) {
		prependChar(testDB[i].input,testDB[i].prependchar);
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}

