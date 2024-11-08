#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	char code[15],decode[10];
	//for(int i=1;i<=8;i++) scanf("%c",&code[i]);
	scanf("%s",code);
	//gets(code);
	int len=strlen(code);
	for(int i=0;i<len;i++){
		decode[i]=code[i];
		for(int j=i+1;j<len-1;j++){
			swap(code[j],code[j+1]);
		}
		/*for(int i=1;i<=len;i++){
			printf("%c",code[i]);
		}
		printf("\n");*/
	}
	for(int i=0;i<len;i++){
		printf("%c",decode[i]);
	}
	return 0;
}