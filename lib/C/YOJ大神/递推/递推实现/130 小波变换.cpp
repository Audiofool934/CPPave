#include<stdio.h>
int xx(int x)
{
    int a=1;
    for(int i=0;i<x;i++)
        a*=2;
    return a;
}
int main(void)
{
    int n,i=2;
    scanf("%d",&n);
    int a[n+1][n+1],m=n;
    while(m/2!=1) {i++;m=m/2;}
    for(int i=1;i<=n;i++){
        scanf("%d",&a[1][i]);//第一行是输入
    }
    for(int i=1;i<=n-1;i++)//初始化
        for(int l=1;l<=n;l++)
            a[i+1][l]=a[i][l];
    for(int i=2;i<=i;i++){//从第二行开始处理
        int l=1;
        for(int l=1;l<=xx(i-1);l+=2){//i行l列
            //printf("i:%d\nl:%d\n",i,l);
            //printf("xx(i-1):%d\n",xx(i-1));
            //printf("a[i-1][l]:%d\n",a[i-1][l]);
            //printf("a[i-1][xx(i-1)/2+l]:%d\n",a[i-1][xx(i-1)/2+l]);
            a[i][l]=(a[i-1][l]+a[i-1][xx(i-1)/2+l])/2;
            a[i][l+1]=(a[i-1][l]-a[i-1][xx(i-1)/2+l])/2;
            //printf("a[i][l]:%d\n",a[i][l]);
            //printf("a[i][l+1]:%d\n",a[i][l+1]);
            l++;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i][i]);
    return 0;
}
//注意：审题，审题，审题；细节，细节，细节
//每一个+1 -1都要过脑子！不然就是成倍的时间花费
//第一个手挫的代码，从算法到调试，竟然花了几个小时，不过没事儿，最后一遍AC就值了！