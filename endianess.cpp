// endainess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct test{
	int num;
	int out;
}testDB[5]={
	{0x1234,0x12},
	{0x0001,0x00},
	{123,123}
};
bool endian(int num,int i)
{
	char* end=(char*) &num;
	if(end[0]==testDB[i].out)
		return true;
	else
		return false;
}
void testcases(){
	int i=0;
	char *out;
	for(i;i<3;i++){
		if(endian(testDB[i].num,i))
			printf("big endian\n");
		else
			printf("little endian\n");
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();
	return 0;
}

