#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=i*j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=(i-1)*2;j++){
            printf(" ");
        }
        for(int j=1;j<=n;j++){
            printf("%d",&a[i][j]);
        }
        printf("\n");
    }
    return 0;
}