#include<stdio.h>
int main()
{
    char str0[100],str1[100],str2[100];
    scanf("%s",str0);
    scanf("%s",str1);
    scanf("%s",str2);
    printf("%s\n%s %s\n",str0,str1,str2);
    return 0;
}
//不用gets()真的不能简单读一行吗？