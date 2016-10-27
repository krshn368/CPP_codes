// 39. standard phonemapping.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
#include<string.h>
 
struct test{
	char input[20];
	char result[20];
}teststub[10]={ {NULL, NULL},
				{"abc","222"},
				{"am-0d-wa","26103192"},
				{"ItRocks","4876257"},
				{"adg","234"},
				{"   1","0001"},
				{"1GB","142"},		
				{" m o m ","0606060"},
				{"(RnD@#$%)","176311111"},
				{" ", "0"}
};
void phoneMap(char *input)
{
	int rem=0,quo=0,i=0;
	while(input[i]!=0)
	{
		if (input[i]>='a' && input[i]<='z')
		{
			rem=input[i]%'a';
			quo=(rem/3)+2;
		}
		else if(input[i]>='A' && input[i]<='Z')
		{
			rem=input[i]%'A';
			quo=(rem/3)+2;
		}
		else if(input[i]>='0' && input[i]<='9')
		{
			quo=input[i]-'0';
		}
		else if(input[i]==' ')
			quo=0;
		else
			quo=1;
		if(rem==18 || rem==21 || rem==24 || rem==25)
			quo=quo-1;
		input[i]=quo+'0';
		i++;
	}
}
void testcases();

int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}
void testcases()
{
	int index;
	for(index=0; index<10; index++)
	{
		phoneMap(teststub[index].input);
		if(strcmp(teststub[index].input,teststub[index].result)==0)
			printf("Passed\n");
		else 
			printf("Failed\n");
	}
}

