#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);//你能想象第一次的时候把n,m写反了、并调试了半天？？？
    int a[n+1][m+1],b[m+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[j][i]=a[i][j];
        }
        printf("\n");
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}