// ReverseStructure.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<string.h>
struct values{
	char name[20];
	int age;
};
struct test{
	struct values input[20];
	struct values output[20];
	int len;

}testDB[10]={
	{{{"peri",43},{"abhay",37},{"hari",30}},{{"hari",30},{"abhay",37},{"peri",43}},3},
	{{{"abc",43},{"def",37},{"ghi",30},{"ijk",57}},{{"ijk",57},{"ghi",30},{"def",37},{"abc",43}},4},
	{{{"a1",100},{"b2",100}},{{"b2",100},{"a1",100}},},
	{{{"a",1},{"b",2},{"c",3},{"d",4},{"e",5},{"f",6}},{{"f",6},{"e",5},{"d",4},{"c",3},{"b",2},{"a",1}},6},
	{{{"nithin",20}},{{"nithin",20}},1}
};
void reverse(struct values *s,int len)
{
	int i=len-1,j=0;
	struct values temp;
	while(i>=j)
	{
	temp=s[j];
	s[j]=s[i];
	s[i]=temp;
	j++;
	i--;
	}
}
void testcases()
{
	int i=0,j,n;
	for(i=0;i<5;i++)
	{
		n=testDB[i].len;
		reverse(testDB[i].input,n);
		j=0;
		while(j<n)
		{
			if(strcmp(testDB[i].input[j].name,testDB[i].output[j].name)==0 && testDB[i].input[j].age==testDB[i].output[j].age)
				j++;
			else
				break;
		}
		if(j==n)
			printf("PASSED\n");
		else
			printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}



