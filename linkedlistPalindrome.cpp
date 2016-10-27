// linkedlistPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>
typedef struct ll node;
struct ll{
	int num;
	node *link;
};
node *h1;
struct test {
	int input[20];
	int output[11];
	int size;
} testDB[8] = {
	{{1000,400,569,723,723,569,400,1000},{1000,400,569,723},8},
	{{1,2,3,3,2,1},{1,2,3},6},
	{{1,2,3,2,1},{1,2,3},5},
				{{1,1},{1},2},
				{{1},{1},1},
				{{10,11,12,13,14,13,12,11,10},{10,11,12,13,14},9},
				{{1,2,1},{1,2},3},
	{{11,12,13,14,15,15,14,13,12,11},{11,12,13,14,15},10}
	
				
};

node *create(int *a,int n)
{
  int i=0;
  node *pointer=(node *)malloc(sizeof(node));
  node *p;
  p=pointer;
  pointer->link=NULL;
  for(i=0;i<n;i++)
  {
  if(pointer->link==NULL)
  {
	pointer->link=(node*)malloc(sizeof(node));
	pointer->num=a[i];
	pointer=pointer->link;
	pointer->link=NULL;
  }
  }
return p;
}
void testCases()
{
	int i=0,j=0,n;
	node *head,*rev_head,*p;
	for(i=0; i<8; i++) {
		n=testDB[i].size;
		head=create(testDB[i].input,n);
		n=testDB[i].size/2;
		p=head;
		j=0;
		while(j<n){
			if(p->num==testDB[i].output[j]){
				j++;
				p=p->link;
			}
			else{
				break;
			}
		}
		if(testDB[i].size%2==0){
			j--;
		}
		while(j>=0){
			if(p->num==testDB[i].output[j]){
				j--;
				p=p->link;
			}
			else{
				break;
			}
		}
		if(j<=0)
			printf("PASSED\n");
		else
			printf("FAILED\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}

