// stringWithTwoIndices.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

struct test {
	char input[20];
	int index1;
	int index2;
	char output[20];
} testDB[13] = {{"hello",2,3,"heo"},
				{"",2,3,""},
				{"hello world",0,0,"ello world"},
				{"hello",3,2,"hello"},
				{"!%$$$%$",2,4,"!%%$"},
				{"123$$ he",3,4,"123 he"},
				{"hello",-1,-2,"hello"},
				{"hello",-1,2,"hello"},
				{"",0,0,""},
				{"hello",2,6,"he"},
				{"hello",6,8,"hello"},
				{"HEllO WOrlD",2,5,"HEWOrlD"},
				{"hello",0,4,""}
            };

void stringWithTwoIndices(char* input,int index1,int index2)
{
	int p=0,q=0;
	if(index1>=0 && index2>=0 && index1<=index2)
	{
		while(input[p]!=0)
		{
			if(p<index1 || p>index2)
			{
				input[q]=input[p];
				++p;
				++q;
			}
			else
				++p;
		}
		input[q]='\0';
	}

}


void testCases()
{
	for(int i=0; i<13; i++) {
		stringWithTwoIndices(testDB[i].input,testDB[i].index1,testDB[i].index2);
		if(strcmp(testDB[i].input, testDB[i].output) == 0) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}

