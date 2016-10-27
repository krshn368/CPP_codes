// reverseLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
typedef struct ll node;
struct ll{
	int num;
	node *link;
};

struct test {
	int input[20];
	int output[20];
	int size;
} testDB[5] = {{{1,2,3,4,5},{5,4,3,2,1},5},
				{{1,2},{2,1},2},
				{{1},{1},1},
				{{10,11,12,13,14,15,16,17,18},{18,17,16,15,14,13,12,11,10},9},
				{{1,2,3},{3,2,1},3}
};

node *create(int *a,int n)
{
  int i=0;
  node *pointer=(node *)malloc(sizeof(node));
  node *p;
  p=pointer;
  pointer->link=NULL;
  for(i=0;i<n;i++){
  if(pointer->link==NULL){
	pointer->link=(node*)malloc(sizeof(node));
	pointer->num=a[i];
	pointer=pointer->link;
	pointer->link=NULL;
  }
  }
return p;
}
node * reverse(node *pointer)
{
    node *parent=head->link;
	node *current=head->link;
	if(current==NULL)
		return head;
	else
	{
		current=reverse(current);
		parent->link=head;
		head->link=NULL;
		return current;
	}
}
void testCases()
{
	int i=0,j=0,n;
	node *head,*rev_head,*q;
	for(i=0; i<5; i++) {
		n=testDB[i].size;
		head=create(testDB[i].input,n);
		if(testDB[i].size==1)
			rev_head=head;
		else
			rev_head=reverse(head);
		q=rev_head;
		j=0;
		while(q->link!=NULL) {
			if(q->num==testDB[i].output[j]){
				q=q->link;
				j++;
			}
			else
				break;
		}
		if(q->num==testDB[i].output[j]){
				j++;
			}
		if(j==n)
			printf("failed\n");
		else
			printf("passed\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}


