#include<stdio.h>
#include<string.h>
int reverse(char* s, int i, int j){
    if(s[i]!=s[j]||i>j){
        return 0;
    }
    reverse(s,i+1,j-1);
    return 1;
}
int main()
{
    char s[100];
    scanf("%s",s);
    if(reverse(s,0,strlen(s)-1)){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}