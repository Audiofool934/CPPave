#include<stdio.h>
int main(void)
{
    int n,m,temp;
    scanf("%d%d",&n,&m);
    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int l=1;l<=m;l++)
        {
            scanf("%d",&a[i][l]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m-1;j++)
        {
            for(int k=1;k<=m-j;k++)
            {
                if(a[i][k]<a[i][k+1])
                {
                    temp=a[i][k];
                    a[i][k]=a[i][k+1];
                    a[i][k+1]=temp;
                }
            }
        }
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int l=1;l<=n-i;l++)
        {
            if(a[l][1]>a[l+1][1])
            {
                temp=a[l][1];
                a[l][1]=a[l+1][1];
                a[l+1][1]=temp;
            }
        }
    }
    printf("%d\n",a[1][1]);
    return 0;
}
//爆内存？————不堪入目，数组、排序乱写