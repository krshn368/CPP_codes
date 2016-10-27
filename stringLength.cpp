// lengthofstring.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include<malloc.h>
int length(char *);
struct teststub
{
	char *input;
	int length;
	int returnlength;
}test[7]={{"abcd",4},//the string contains only letters
		  {"hello hi",8}, //the string contains spaces
          {"1234",4}, //the string contains numbers
          {"@#$%",4}, //the string contains spaecial characters
          {"",0}, //if is a null string
          {"\"'",2}}; //if the string contains double quotes and single quotes

int length(char *s)
{
	int i=0;
	if(s[0]!=0)
	{
		while(s[i]!=0)
			i++;
		return i;
	}
	else
		return 0;	
}
int _tmain(int argc, _TCHAR* argv[])
{
    for(int i=0;i<6;i++)
	{
		test[i].returnlength=length(test[i].input);
		if(test[i].returnlength==test[i].length)
			printf("passed\n");
		else
			printf("failed\n");
	}
	return 0;
}
