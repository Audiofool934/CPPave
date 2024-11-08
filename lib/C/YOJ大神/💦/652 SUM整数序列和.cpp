#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n>=1){
        printf("%d",(1+n)*n/2);
    }
    if(n<1){
        printf("%d",(1+n)*(-n+2)/2);
    }
    return 0;
}