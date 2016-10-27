// swap_strings_call_by_reference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string.h>
struct test{
	char input1[20];
	char input2[20];
	char output1[20];
	char output2[20];
}testDB[6]={{"abcd","1234","1234","abcd"},
{"abcdef","12","12cdef","ab"},
{"zxyscd  5675","32  547","32  547 5675","zxyscd "},
{"123456789","         ","         ","123456789"},
{"!@#$%^&*()_+"," 1 2 3"," 1 2 3&*()_+","!@#$%^"}
};
void swap(char *input1,char *input2)
{
	char temp;int i=0,j=0;
	while(input1[i]!=0 && input2[j]!=0)
	{
		temp=input1[i];
		input1[i]=input2[j];
		input2[j]=temp;
		i++;
		j++;
	}

}
void testcases(){
	int i=0;
	for(i;i<5;i++){
		swap(testDB[i].input1,testDB[i].input2);
		if(strcmp(testDB[i].input1,testDB[i].output1)==0 && strcmp(testDB[i].input2,testDB[i].output2)==0)
			printf("PASSED\n");
		else
			printf("FAILED");
	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}

