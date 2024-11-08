#include<stdio.h>
int main()
{
    long n,m;
    scanf("%ld%ld",&n,&m);
    int a[n+1],sum=0,cnt=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        sum+=a[i];
        //printf("sum=%d\n",sum);
        if(sum+a[i+1]>m){
            sum=0;
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}