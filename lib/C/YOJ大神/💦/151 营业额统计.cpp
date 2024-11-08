#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,m,sum=0;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int delta[n];
    m=a[1];
    for(int i=1;i<=n;i++){
        //printf("i=%d\n",i);
        for(int j=1;j<=i-1;j++){
            delta[j]=abs(a[i]-a[j]);
            //printf("delta[%d]=%d\n",j,delta[j]);
            m=delta[1];
        }//第i个数和前面所有数的差组成的数列s
        for(int j=1;j<=i-1;j++){
            m=min(m,delta[j]);
            if(m>delta[j]){
                //printf("if\ndelta[%d]=%d\ndelta[%d]=%d\n",j,delta[j],j+1,delta[j+1]);
                m=delta[j];
                //printf("m=%d\n",m);
            }
        }
        //printf("\n");
        //找到最小值
        sum+=m;
        //printf("m=%d\nsum=%d\n",m,sum);
    }
    printf("%d\n",sum);
    return 0;
}