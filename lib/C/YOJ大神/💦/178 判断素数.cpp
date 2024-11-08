#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        int bl=0;
        if(a[i]==1) printf("NO ");
        else if(a[i]==2) printf("YES ");
        else{
        for(int j=2;j<=a[i]-1;j++){
            if(a[i]%j==0){
                printf("NO ");
                break;
            }
            else bl++;
        }
        if(bl==a[i]-2){
            printf("YES ");
        }
        }
    }
    return 0;
}