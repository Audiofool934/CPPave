#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int min=10000;
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            if(min>=abs(a[i]-a[j])){
                min=abs(a[i]-a[j]);
            }
        }
    }
    printf("%d",min);
    return 0;
}