// countLettersa3b2c1.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include<string.h>
#include<malloc.h>
struct Test{
	char input[30],output[30];
} testDB[6] = {{"aaabbc","3a2b1c"},
				{"zzzzzz","6z"},
				{"aazzzykkkk45", "2a4k1y3z"},	//ignore numbers and special characters
				{"a","1a"},
				{"abc", "1a1b1c"},
				{"AaaABbCC","4a2b2c"}
};
void number_of_chars(char *s){
	int i=0,j=0;
	int count[26]={0};
	while(s[i]!=0)
	{
		if(s[i]>='A' && s[i]<='Z')
		{
			s[i]=s[i]+('a'-'A');
		}
		if(s[i]>='a' && s[i]<='z')
			count[s[i]-'a']++;
		i++;
	}
	i=0;
	while(j<26)
	{
		if(count[j]!=0)
		{
			s[i]=count[j]+48;
			s[i+1]='a'+j;														
			i=i+2;
		}
		j++;
	}
	s[i]=0;
}
void testcases(){
	int i=0;
	for(i;i<6;i++){
		number_of_chars(testDB[i].input);
		if(strcmp(testDB[i].input,testDB[i].output)==0)
			printf("PASSED\n");
		else printf("FAILED\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();		
	return 0;
}

