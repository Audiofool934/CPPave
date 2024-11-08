#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n+1][m+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int mi[m],one[m],cnt=0;
    for(int i=1;i<=m;i++){
        if(a[1][i]==1){
            cnt++;
            one[cnt]=i;
        }
    }
    one[cnt+1]=m+1;
    int sum=0;
    one[0]=0;
    for(int i=1;i<=cnt+1;i++){
        if((one[i]-one[i-1]-1)%2==0){
            sum+=n*(one[i]-one[i-1]-1)/2;
        }
        else{
            if(n%2==0){
                sum+=n*((one[i]-one[i-1]-1)-1)/2+n/2;
            }
            else{
                sum+=n*((one[i]-one[i-1]-1)-1)/2+(n+1)/2;
            }
            
        }
        //printf("%d ",one[i]-one[i-1]-1);//这么多行是0
    }
    printf("%d",sum);
    return 0;
}