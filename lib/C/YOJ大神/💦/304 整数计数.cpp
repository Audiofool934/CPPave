#include<stdio.h>
int digit(int n)
{
    int digit=0;
    while(n>0)
    {
        n/=10;
        digit+=1;
    }
    return digit;
}
int main()
{
    int a,b,n,i,m,l=0;
    scanf("%d%d%d%d%d",&a,&b,&n,&i,&m);
    for(int i=a;i<=b;i++)
    {
        if(i%10==n&&i%i==0&&digit(i)==m)
        {
            l=l+1;
        }
        else
        {
            continue;
        }
    }
    printf("%d",l);
    return 0;
}
//函数的使用