#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    char s[n+1][n+1];
    for(int i=1;i<=n-1;i++) printf(" ");
    for(int i=1;i<=n;i++) printf("*");printf("\n");
    for(int i=2;i<=n-1;i++){
            for(int j=1;j<=n-i;j++)
                printf(" ");
            printf("*");
            for(int j=1;j<=n+2*(i-2);j++)
                printf(" ");
            printf("*\n");
    }
    printf("*");
    for(int i=1;i<=3*n-4;i++) printf(" ");
    printf("*\n");
    for(int i=n-1;i>=2;i--){
            for(int j=1;j<=n-i;j++)
                printf(" ");
            printf("*");
            for(int j=1;j<=n+2*(i-2);j++)
                printf(" ");
            printf("*\n");
    }
    for(int i=1;i<=n-1;i++) printf(" ");
    for(int i=1;i<=n;i++) printf("*");printf("\n");
    return 0;   
}