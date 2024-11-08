#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int xx(int x){
    int xx=1;
    for(int i=1;i<=x;i++)
        xx*=10;
    return xx;
}
int main()
{
    long N,n;
    scanf("%ld",&N);
    /*
    if(N/100000000!=0) n=9;
    else if(N/10000000!=0) n=8;
    else if(N/1000000!=0) n=7;
    else if(N/100000!=0) n=6;
    else if(N/10000!=0) n=5;
    else if(N/1000!=0) n=4;
    else if(N/100!=0) n=3;
    else if(N/10!=0) n=2;
    //这里用循环，不断除10，到0为止
    else n=1;
    */
    n=1;
    long NN=N;
    while(NN/10){
        NN/=10;
        n++;
    }
    int a[n+1];
    for(int i=1;i<=n;i++){
        a[i]=abs((N/(xx(i)/10))%10);
    }

    if(N<0) printf("-");
    int j=0;
    for(int i=1;i<=n-1;i++){
        if(a[i]==0&&a[i+1]!=0){j=i;break;}
    }
    for(int i=j+1;i<=n;i++){
        printf("%d",a[i]);
    }   
    return 0;
}