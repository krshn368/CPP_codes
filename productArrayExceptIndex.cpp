#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
struct test {
	int input[20];
	int output[20];
	int size_of_array;
} testDB[8] = {{NULL,NULL,0},
				{{1,2,3,4,5},{120,60,40,30,24},5},
				{{-1,-2,-3,-4,-5},{120,60,40,30,24},5},
				{{-1,2,-3,-4,5},{120,-60,40,30,-24},5},
				{{0,0,0,0,0},{0,0,0,0,0},5},
				{{1,2,3,0,4},{0,0,0,24,0},5},
				{{5,5,5,5,5},{625,625,625,625,625},5},
				{{0x12,0x45,0x50},{5520,1440,1242},3}
            };
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
int * productArray(int *input,int m)
{
	int* r=(int*)malloc(m*sizeof(int));int i,k;
		r[m-1]=1;
	for(i=m-1;i>=0;i--){
		r[i]=r[i]*input[i];
		r[i-1]=r[i];
	}k=1;
	for(i=0;i<m-1;i++){
		r[i]=r[i+1]*k;
		k=k*input[i];
	}r[m-1]=k;
	return r;
}
void testCases()
{
	int *output;
	for(int i=0; i<11; i++) {
		output = productArray(testDB[i].input,testDB[i].size_of_array);
		if(compareArrays(output,testDB[i].size_of_array,i) == 1) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}