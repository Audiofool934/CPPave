#include<stdio.h>
int main()
{
    int a=1;
    for(int i=1;i<=10;i++)
    {
        a*=i;
    }
    printf("%d\n",a);
    return 0;
}