#include "stdafx.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"
struct test {
	int input[20];
	int size_of_array;
} testDB[6] = { {NULL,0},
				{{1,2,3,4},4},
				{{0,0,0,0,0,0,0,0,0,0},10},
				{{},0},
				{{1},1},
				{{1,2,3,4,5},5}
};

bool checkBoxing1DArray(char **box1Darray,int *input,int size_of_input_array)
{
	int box_array_size = (size_of_input_array * 4)+1,index=0;
	for(int i=0;i<3;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<box_array_size;j++)
			{
				if(box1Darray[i][j]!='-')
					return false;
			}
		}
		else
		{
			for(int j=0;j<box_array_size;j++)
			{
				if(j%4 == 0)
				{
					if(box1Darray[i][j] != '|')
						return false;
				}
				else if(j%2!=0)
				{
					if(box1Darray[i][j] != ' ')
						return false;
				}
				else
				{
					if(box1Darray[i][j] != input[index++]+'0')
						return false;
				}
			}
		}
	}
	return true;
}
char ** boxing1DArray(int *input,int size_of_array)
{
	int i=0,k,l=0;char **b;
	b=(char**)malloc(3*sizeof(char*));
	int j=4*size_of_array+1;
	for(i=0;i<3;i++)
	{
		b[i]=(char*)malloc(j*sizeof(char));
		for(k=0;k<j;k++)
			{
				if(i%2==0)
				b[i][k]='-';
				else
				{
					if(k%4==0)
						b[i][k]='|';
					else if(k%4==1 || k%4==3)
						b[i][k]=' ';
					else
					{
						b[i][k]=input[l]+'0';
						l++;
					}
				}
		}
}
	return b;
}
void testCases()
{
	char **output;
	for(int i=0; i<6; i++) {
		output = boxing1DArray(testDB[i].input,testDB[i].size_of_array);
		if(testDB[i].input == NULL)
		{
			if(output == NULL)
				printf("PASSED");
			else
				printf("FAILED");
			continue;
		}
		if(checkBoxing1DArray(output,testDB[i].input,testDB[i].size_of_array)) printf("PASSED\n"); else printf("FAILED\n");
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}