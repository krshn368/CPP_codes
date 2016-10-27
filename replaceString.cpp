// replacing1stringwithanotherstring.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<malloc.h>
#include<string.h>
void testcase();
void replace(char *,char *,int );

struct tests
{
	char input1[20];  //input string 1
	char input2[10]; //input string 2
	int index;  //index from where string2 to be inserted in string1
	char output[20]; //result
	
}test[7]={{"hello","hii hi",2,"hehii hi"},  //string2 contains spaces
{"how r u","hello",6,"how r hello"},//index starts at end of string1
{"hello","hii",0,"hiilo"}, //index starts at 0
{"hello","hiii",-1,"hello"},  //the invalid index
{"hello","hiii",5,"hello"},  //the invalid index
{"1234","567",2,"12567"},  //string contains integer input
{"1*%^@","!##*",0,"!##*@"}
};  //string contain special characters

void replace(char *input1,char *input2,int index){
	int p=0,j=0;
	if(index<=strlen(input1))
	{
		while(input1[p]!=0)
		{
			if(p==(index))
			{
				while(input2[j]!=0)
				{
					input1[p]=input2[j];
					++j;
					++p;
				}
			}
			else
			{
				++p;
			}
		}
		input1[p]='\0';
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcase();
	return 0;
}
void testcase()
{
	for(int i=0;i<7;i++)
	{
		replace(test[i].input1,test[i].input2,test[i].index);//calling function which replaces the string
		if(strcmp(test[i].input1,test[i].output)==0)
			printf("passed\n");
		else
			printf("failed\n");
	}
}


