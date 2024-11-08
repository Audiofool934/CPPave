#include<stdio.h>
int main()
{
    int a[100];
    for(int i=0;i<100;i++){
        a[i]=i+1;
    }
    for(int l=2;l<100;l+=4){
        a[l]*=-1;
    }
    for(int l=3;l<100;l+=4){
        a[l]*=-1;
    }
    int m,n,sum=0;
    scanf("%d%d",&m,&n);
    for(int i=m-1;i<=n-1;i++){
        sum+=a[i];
    }
    printf("%d\n",sum);
    return 0;
}
//注意开闭区间