// singleSpace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
#include<string.h>
char* readinput();
int counttok(char *);
void insspc(char *);
struct test{
	char string1[100];
	char string2[100];
}testDB[9]={{{"a=b"},{"a = b"}},
{{"a=b+c"},{"a = b + c"}},
{{"a=  100+c"},{"a = 100 + c"}},
{{"a=10+20"},{"a = 10 + 20"}},
{{"a=     b -2+454/1    +c-1000"},{"a = b - 2 + 454 / 1 + c - 1000"}},
{{NULL},{NULL}},
{{"a=(b+c)"},{"a = ( b + c )"}},
{{"a=(100+200)*   (10/c) -(  d%2)"},{"a = ( 100 + 200 ) * ( 10 / c ) - ( d % 2 )"}},
{{"a =   4%2*3+4-5"},{"a = 4 % 2 * 3 + 4 - 5"}}
};
void testcases(){
	int i=0;
	for(i;i<9;i++){
		counttok(testDB[i].string1);
		if(strcmp(testDB[i].string1,testDB[i].string2)==0)
			printf("PASSED\n");
		else
			printf("FAILED\n");
	}
}
void removespace(char* input){
	int i=0,j=0;
	while(input[i]!=0){
		if(input[i]==' '){
			i++;
			continue;
		}
		else{
			input[j]=input[i];
			j++;
			i++;
		}
	}
input[j]=0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}
int counttok(char *s)
{
	int i=0,j=0;
	int tok=0,cnt=0;
	while(s[i]!='\0')
	{
		if((s[i]>='a' && s[i]<='z') || (s[i]=='+' || s[i]=='-'|| s[i]=='%' || s[i]=='*' || s[i]=='/' || s[i]=='=') || s[i]=='(' || s[i]==')')
		{
			tok++;cnt++;
			i++;
		}
		else if(s[i]>='0' && s[i]<='9')
		{
			while(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='=' && s[i]!='%' && s[i]!='\0' && s[i]!=' ' && s[i]!='(' && s[i]!=')')
			{
				i++;cnt++;
			}
			tok++;
		}
		else if(s[i]==' ')
		{
			i++;
		}
	}
	removespace(s);
	j=cnt+(tok-1);
	i=strlen(s)-1;j--;
	while(i>0)
	{
		if(s[i]>='0' && s[i]<='9')
		while(s[i]!='+' && s[i]!='-' && s[i]!='*' && s[i]!='/' && s[i]!='=' && s[i]!=' ' && s[i]!='%' && s[i]!='(' && s[i]!=')')
		{
			s[j]=s[i];
			i--;
			j--;
		}
		else if((s[i]>='a' && s[i]<='z')|| s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='%' || s[i]=='/' || s[i]=='='|| s[i]=='(' || s[i]==')' )
		{
			if(s[i]==' ')
			{
				i--;
			}
			else
			{
				s[j]=s[i];
				i--;
				j--;
			}
		}
	if(s[j+1]!=' ')
	{ 
	s[j]=' ';
	j--;
	}
	else i--;
}
return tok;
}

