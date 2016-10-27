// 4different_swap_functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct test{
	int input;
	int output;
}testDB[10]={
	{1234,4321},
	{12,34},
	{0,0},
	{1,0},
	{123456,1},
	{32765,32765},
	{-234,-3},
	{-123,1},
	{0,-4567}
};
void swap1(int a,int b,int i){
	a=a+b;
	b=a-b;
	a=a-b;
	if(a==testDB[i].output && b==testDB[i].input)
		printf("PASSED");
	else
		printf("FAILED");
}
void swap2(int a,int b,int i){
	int temp;
	temp=a;
	a=b;
	b=temp;

	if(a==testDB[i].output && b==testDB[i].input)
		printf("\tPASSED");
	else
		printf("\tFAILED");
}
void swap3(int a,int b,int i){
	a=a ^ b;
	b=a ^ b;
	a=a ^ b;
	if(a==testDB[i].output && b==testDB[i].input)
		printf("\tPASSED");
	else
		printf("\tFAILED");

}
void swap4(int *a,int *b,int i){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	if(*a==testDB[i].output && *b==testDB[i].input)
		printf("\tPASSED\n");
	else
		printf("\tFAILED\n");
}
void testcases(){
	int i=0;
	int a,b;
	bool swapval[4];
	printf("swap1");
	printf("\tswap2");
	printf("\tswap3");
	printf("\tswap4\n\n");
	for(i;i<9;i++){
		a=testDB[i].input;
		b=testDB[i].output;
		swap1(a,b,i);
		swap2(a,b,i);	
		swap3(a,b,i);
		swap4(&a,&b,i);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}