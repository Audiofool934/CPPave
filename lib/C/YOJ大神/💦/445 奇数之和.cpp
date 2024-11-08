#include<stdio.h>
int main()
{
    int m,n,s=0;
    scanf("%d,%d",&m,&n);
    if(m%2==0&&n%2==0)
    {
        for(int i=m+1;i<=n-1;i+=2)
        {
            s+=i;
        }
        printf("%d\n",s);
    }
    if(m%2==0&&n%2!=0)
    {
        for(int i=m+1;i<=n-2;i+=2)
        {
            s+=i;
        }
        printf("%d\n",s);
    }
    if(m%2!=0&&n%2==0)
    {
        for(int i=m+2;i<=n-1;i+=2)
        {
            s+=i;
        }
        printf("%d\n",s);
    }
    if(m%2!=0&&n%2!=0)
    {
        for(int i=m+2;i<=n-2;i+=2)
        {
            s+=i;
        }
        printf("%d\n",s);
    }
    return 0;
}