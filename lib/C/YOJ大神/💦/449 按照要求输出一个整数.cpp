#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    printf("%15d\n",a);
    printf("%15u\n",a);
    printf("%15o\n",a);
    printf("%15x\n",a);    
    return 0;
}
//为什么用long long a时负数会报错？