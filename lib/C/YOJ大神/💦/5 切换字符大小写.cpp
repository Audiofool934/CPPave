#include<stdio.h>
int main()
{
    char a, b;
    a=getchar();
    if(a >= 'a')
    {
        b=a-32;
        printf("%c\n", b);
    }
    else
    {
        b=a+32;
        printf("%c\n", b);
    }
    return 0;
}