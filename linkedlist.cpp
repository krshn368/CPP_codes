// linkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
#include<string.h>

struct ll{
  int num;
  struct ll *next;
};
typedef struct ll node;
struct teststub
{
	int input;
	int length_of_the_input;
	int output[10];
}testDB[4]={
			{1234,4,{1,2,3,4}},
			{1,1,{1}},
			{0,1,0},
			{-123,3,NULL}
};

node *create(int n,node *h)
{
	node *temp;
  int rem,i=1,input=n;
  if(n>0)
  {
	  while(input!=0)
	  {
		  rem=input % 10;
		  input=input / 10;
		   if(i==1){ 
		  h->num=rem;
		  h->next=0;
		  i++;
		  continue;
		   }
		  temp=(node *)malloc(sizeof(node));
		  temp->num=rem;
		  temp->next=h;
		  h=temp;
	  }
  }
  else if(n==0)
  {
	  temp=(node *)malloc(sizeof(node));
		  temp->num=0;
		  temp->next=NULL;
		  h=temp;
  }
  else
  {
	  temp=(node *)malloc(sizeof(node));
	  temp=NULL;
	  h=temp;
  }
return h;
}
int* compare(node * list, int * expectedvalues, int length)
{
	int i=0;
	if(list!=0)
	{
	while(list!=NULL)
	{
		expectedvalues[i]=list->num;
		list=list->next;
		++i;
	}
	}
	else
		expectedvalues=NULL;
	return expectedvalues;
}
int compareArrays(int *output,int size,int index)
{
	if(output!=NULL)
	{
		for(int i=0;i<size;i++)
		{
			if(output[i] != testDB[index].output[i])
				return 0;
		}
		return 1;
	}
	else
	{
		if(output==NULL)
			return 1;
	}
}

void testCases()
{
	int *expectedvalues;
	node *head,*p;
	for(int i=0; i<4; i++)
	{
		  head=(node *)malloc(sizeof(node));
		  head->next=NULL;
		  p=head;
		  p=create(testDB[i].input,p);
		  expectedvalues=(int*)malloc((testDB[i].length_of_the_input+1)*sizeof(int));
		  expectedvalues=compare(p,expectedvalues,testDB[i].length_of_the_input);
		if(compareArrays(expectedvalues,testDB[i].length_of_the_input,i) == 1) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
  testCases();
  return 0;
}


