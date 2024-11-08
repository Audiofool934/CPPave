#include<stdio.h>
#include<iostream>
using namespace std;
int ten(int a){
    int tent=1;
    for(int i=1;i<=a;i++){
        tent*=10;
    }
    return tent;
}
int main()
{
    int x,a[5];
    scanf("%d",&x);
    for(int i=1;i<=4;i++){
        a[i]=(x/ten(4-i))%10;
    }
    /*for(int j=1;j<=4;j++)
        printf("%d ",a[j]);
    printf("\n");*/
    for(int i=1;i<=4;i++){
        a[i]=(a[i]+5)%10;
    }
    /*for(int j=1;j<=4;j++)
        printf("%d ",a[j]);
    printf("\n");*/
    swap(a[1],a[4]);
    swap(a[2],a[3]);
    /*for(int j=1;j<=4;j++)
        printf("%d ",a[j]);
    printf("\n");*/
    for(int i=1;i<=4;i++){
        if(a[i]!=0){
            for(int j=i;j<=4;j++)
            printf("%d",a[j]);
            break;
        }
    }
    return 0;
}