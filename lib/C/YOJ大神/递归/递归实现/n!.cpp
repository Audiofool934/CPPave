#include<stdio.h>
int ns(int n){
    if(n==0){
        return 1;
    }
    return n*ns(n-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",ns(n));
    return 0;
}