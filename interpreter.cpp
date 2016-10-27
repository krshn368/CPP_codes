// interpreter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

char* removespaces(char* ch)
{ int i=0;int j=0;
	while(ch[i]!='\0')
	{
		if(ch[i]!=' ')
		{
			ch[j]=ch[i];
			j++;
		}
		++i;
	}
	ch[j]=NULL;
	return ch;
}
void printtoken(char** p,int l)
{
	int i=0,j;
	for(i=0;i<5;i++)
	printf("%s",p[i]);
	printf("\n");
	
}
int skipdigit(char* s,int p)
{
	int count=0;
	while((s[p]>='0' && s[p]<='9'))
	{count++;
	p++;
	}
	return count;
}
bool isdigit(char s)
{
int i=0;bool flag=false;
	if(s>='0' && s<='9')
		    flag=true;
return flag;
}
bool callstring(char s)
{
bool flag=false;
		if(s>='a' && s<='z')
			flag=true;
	return flag;
}
char** parsetable(char* s)
{
	void printtoken(char**,int);
	int i=0,j=0,k,l;char **p;
	p=(char**)malloc(5*sizeof(char* ));
	for(i=0;i<5;i++)
		p[i]=0;
	if(s[0]>='a' && s[0]<='z')
		{
			p[0]=s;
			printf("%c\n",p[0][0]);
		}
		else
		{
			printf("invalid input");
		}
		if(s[1]=='=')
		{
			p[1]=s+1;
			printf("%c\n",p[1][0]);
		}
		else
			printf("input invalid");
		i=2;l=skipdigit(s,i);
		while(s[i]!=0)
		{
			if(isdigit(s[i]) || callstring(s[i]))
			{
				p[2]=s+2;
			}
			else
			{
				printf("invalid input");
				break;
			}
			i++;
		}
		printf("%c\n",p[2][0]);
		if(s[i]!=0)
		{
			if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='=')
			{
			p[3]=s+3;
			printf("%c\n",p[3][0]);
			}
			else
			{
				printf("input invalid");
			}
		i=i+1;j=0;
		while(s[i]!=0)
		{l=skipdigit(s,i);
			if(isdigit(s[i]) || callstring(s[i]))
			{
				p[4]=s+4;				
			}
			else
			{
				printf("invalid input");
				break;
			}
			i++;
		}
		for(k=0;k<l;k++)
			printf("%c",p[4][l]);
		}
	return p;
}


int interpreter(char **p)
{
	int a[27],i,j,k,m;
	for(i=0;i<26;i++)
		a[i]=-1;
	i=0;
	while(p[i]!=NULL)
	{
		for(m='a';m<='z';m++)
			if(p[0][0]==m)
				a[m-'a']=atoi(p[2]);
	}
	printf("%d",a[0]);
	return 0;
}
char* readinput(){
	int maxlen;
	printf("enter maxlength:");
	scanf("%d",&maxlen);
	fflush(stdin);
	char* s=(char*)malloc(maxlen+1);
	printf("Enter String:");
	gets(s);
	return s;
}


int _tmain(int argc, _TCHAR* argv[])
{char *newinput,*newinput2,*newinput3;int i;
char **p;
bool flag;
newinput=readinput();
newinput2=removespaces(newinput);
p=parsetable(newinput2);
//i=interpreter(p);
	return 0;
}

