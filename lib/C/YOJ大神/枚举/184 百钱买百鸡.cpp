#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
    int n,cnt=0,a[301][3];
    scanf("%d",&n);//n钱n鸡
    for(int i=0;i<=n/5+5&&i<=n;i++){//i鸡1
        for(int j=0;j<=n/3+3&&j<=n;j++){//j鸡2
            for(int k=0;k<=n;k+=3){//k鸡3
                //printf("%d\n",i*5+j*3+k/3);
                if(i*5+j*3+k/3==n&&i+j+k==n){
                    cnt++;
                    a[cnt][0]=i;
                    a[cnt][1]=j;
                    a[cnt][2]=k;
                }
                if(i*5+j*3+k/3>n){
                    break;
                }
            }
        }
    }
    if(cnt==0) printf("0\n");
    else{
    for(int i=1;i<=cnt;i++){
        printf("%d %d %d\n",a[i][0],a[i][1],a[i][2]);
    }
    printf("%d\n",cnt);
    }
    return 0;
}