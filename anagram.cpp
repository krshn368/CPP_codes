#include "stdafx.h"
#include <string.h>
struct test2{
	char string1[20];
	char string2[20];
}testDB[10]={
	{{"cat"},{"act"}},
	{{"pit"},{"tip"}},
	{{"!@#$%^&*()_+"},{"+_)(*&!@#$%^"}},
	{{"123456789"},{"987654321"}},
	{{"peri sir and kc sir"},{"Kc SIR AND peRI sir"}},
	{{NULL},{NULL}},
	{{"a1b2c3d5!@# f6"},{"A1B2C3D5!@# F6"}},
	{{"apple"},{"ApPle"}},
	{{"mam"},{"amm"}}
};
int anagram(char *string1,char *string2){
	int count1=0,count2=0,i=0,j=0;
	while(string1[i]!=0 && string2[j]!=0){
		count1=count1+string1[i];
		count2=count2+string2[j]; 
		i++;
		j++;
	}
	if((count1==count2 || (count2-count1)%('a'-'A')==0) && (strlen(string1)==strlen(string2)))
		return 1;
	else
		return 0;
}
void testcases(){
	int i=0;
	for(i;i<10;i++){
		if(anagram(testDB[i].string1,testDB[i].string2))
			printf("PASSED\n");
		else
			printf("FAILED\n");

	}

}
int _tmain(int argc, _TCHAR* argv[])
{
	testcases();	//calling anagram testin function
	return 0;
}