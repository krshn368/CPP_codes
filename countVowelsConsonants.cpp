// testCountVowelsConsonants.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"


struct test {
	char input[20];
	int vowels,consonants;

} testDB[15] = {{"aaaa",4,0},
				{"aEiOOu",6,0},
                {"EOIAUUA",7,0},
                {"bcdddf",0,6},
                {"BBCDF",0,5},
                {"BcdFG",0,5},
                {"abcef",2,3},
                {"AbCEf",2,3},
                {"ABCDEF",2,4},
                {"ae12Bc@d",2,3},
                {"Ae1 bc@#def",3,4},
                {"#123*",0,0},
                {"",0,0}
            };
	

void countVowelsConsonants(char* input,int* v,int* c)
{
	int i=0;
	while(input[i]!=0)
	{
		if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z'))
		{
			if(input[i]=='a' ||input[i]== 'e' || input[i]=='i' || input[i]=='o' || input[i]=='u' || input[i]=='A' || input[i]=='E' || input[i]=='I' || input[i]=='O' || input[i]=='U')
			{
				*v=*v+1;
			}
			else
				*c=*c+1;
		}
		i++;
	}
}
void testCases()
{
	int v,c;
	v=0;c=0;
	for(int i=0; i<13; i++) {
		v=0;c=0;
		countVowelsConsonants(testDB[i].input,&v,&c);
		if(testDB[i].vowels==v && testDB[i].consonants==c) printf("PASSED\n"); else printf("FAILED\n");
	}
	
}
int _tmain(int argc, _TCHAR* argv[])
{
	testCases();
	return 0;
}

