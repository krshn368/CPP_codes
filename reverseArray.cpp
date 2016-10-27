// reverseArray.cpp : Defines the entry point for the console application.
//

// testReverseArray.cpp : Defines the entry point for the console application.
//program to reverse the given integer array. inputs are: input array and length of the array


/* SPEC: ACCEPTS POSITIVE AND NEGATIVE NUMBERS
ACCEPTS FLOATING POINT NUMBERS
DOESNT ACCEPT NEGATIVE LENGTH OR LENGTH = 0
*/
#include "stdafx.h"

struct test {
	int input[20];
	int len;
	int output[20];
} testDB[9] = {{{0,1,2,3},0,{0,1,2,3}},        // when the length is 0
{{0,1,2,3},-2,{0,1,2,3}},                       //when the length is negative
{{0,1,2,3},4,{3,2,1,0}},                       // when the length of input array is even
{{5,3,4,2,1},5,{1,2,4,3,5}},                  // the length of input array is odd
{{1,1,1,1},4,{1,1,1,1}},                     // all input array elements are same
{{-3,-4,-2,-8,-1},5,{-1,-8,-2,-4,-3}},		//all input elements are negative numbers
{{1.2,3.4,5},3,{5,3,1}},			       // input contains floating point numbers
{{1,-2,6,-3,-1},5,{-1,-3,6,-2,1}},         // input contains both +ve and -ve numbers
{{},0,{}},
            };
int* reverseArray(int* input,int len)
{
	int i,index=len-1,temp;
	if((!input) || len<=0)
		return input;
	for(i=0;i<=index/2;i++)
	{
		temp=input[i];
		input[i]=input[index-i];
		input[index-i]=temp;
	}
	return input;

}
int compareArrays(int* input,int* output,int len)
{
	
	for(int i=0;i<len;i++)
	{
		if(input[i]!=output[i])
			return 0;
	}
	return 1;
}
void testCases()
{
	
	for(int i=0; i<9; i++) {
		if(compareArrays(testDB[i].output,reverseArray(testDB[i].input,testDB[i].len),testDB[i].len) == 1) printf("%d  PASSED\n",i+1); else printf("%d  FAILED\n",i+1);
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}


