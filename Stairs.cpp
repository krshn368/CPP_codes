// fib.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
struct test
{
	int input;
	int output;
}testDB[7]={
	{1,1},
	{2,2},
	{3,3},
	{5,8}
};
int NoOfPossiblewaysForStairs(int n)
{
	if(n==1)
	{
		return 1;
	}
	else if(n==2)
	{
		return 2;
	}
	else
		return NoOfPossiblewaysForStairs(n-1)+NoOfPossiblewaysForStairs(n-2);
}
void testcases()
{
	int i,sum1,sum2;
	for(i=0;i<4;i++)
	{
		sum1=NoOfPossiblewaysForStairs(testDB[i].input);
		if(sum1==testDB[i].output) printf("PASSED\n"); else printf("FAILED\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}
