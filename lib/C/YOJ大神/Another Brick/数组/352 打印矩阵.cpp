/*#include <stdio.h>
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= m; l++) {
            printf("%d ", i * l);
        }
        printf("\n");
    }
    return 0;
}*/
#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int l=0;l<m;l++)
        {
            a[i][l]=(l+1)*(i+1);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int l=0;l<m;l++)
        {
            printf("%d ",a[i][l]);
        }
        printf("\n");
    }
    return 0;
}
//为什么a[n][m]行，a[n-1][m-1]不行，数组到底有几位？