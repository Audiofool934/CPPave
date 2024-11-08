#include <stdio.h>
#include<iostream>
using namespace std;
int main() 
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    int b[10000];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int l=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            l++;
            for(int k=1;k<=i;k++){
                b[l]+=a[j-1+k];
            }
            //如果把l++放在这儿，前面改成l=1，l就加多了！一定注意端点
        }
    }
    for(int i=1;i<=l-1;i++){
        for(int j=1;j<=l-i;j++){
            if(b[j]<b[j+1]){
                swap(b[j],b[j+1]);
            }
        }
    }
    printf("%d",b[1]);
    return 0;
}