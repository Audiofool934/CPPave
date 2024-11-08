#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
    char c,a[101],b[101];
    int l=0;
    while ((c = getchar()) != '\n'){
        l++;
        a[l]=c;
    }
    int k=0;
    while ((c = getchar()) != '\n'){
        k++;
        b[k]=c;
    }
    for(int i=1;i<=min(k,l);i++){
        //printf("%d %d\n",a[i],b[i]);
        if(a[i]==b[i]) continue;
        if(a[i]!=b[i]) {printf("%d",a[i]-b[i]); break;}
    }
    return 0;
}