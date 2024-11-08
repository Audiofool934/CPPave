#include<stdio.h>
int digit(int n)
{
    int i=0;
    while(n>0)
    {
        n/=10;
        i++;
    }
    return i;
}
int up(int n)
{
    int t=1;
    for(int i=1;i<=n;i++)
    {
        t=t*10;
    }
    return t;
}
int main()
{
    int a,b,n=0;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++)
    {
        int m=digit(i);
        if((i*i)%up(m)==i)
        {
            n+=i;
        }
    }
    printf("%d\n",n);
    return 0;
}