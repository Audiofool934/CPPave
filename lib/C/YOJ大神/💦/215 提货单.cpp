#include<stdio.h>
int main()
{
    char s[110];
    int n,a,b,sum=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s%d%d",s,&a,&b);
        sum+=a*b;
    }
    printf("%d",sum);
    return 0;
}