#include<stdio.h>
#include<iostream>
using namespace std;
int a[105][105],sorted[105],cnt=0;
int minidx(int bg,int ed,int a[]){
    int minm=a[bg],idx=bg;
    for(int i=bg;i<=ed;i++){
        if(minm>a[i]){
            minm=a[i];
            idx=i;
        }
    }
    return idx;
}
int compare(int a[],int b[],int len){
    for(int i=1;i<=len;i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}
void copy(int a[],int b[],int len){
    for(int i=1;i<=len;i++)
        b[i]=a[i];
    return;
}
void ssort(int bg,int ed,int j){
    if(bg>=ed||compare(a[j],sorted,ed)) return;
    
    int idx=minidx(bg,ed,a[j]);

    while (bg==idx){
        bg++;
        idx=minidx(bg,ed,a[j]);
    }
    swap(a[j][bg],a[j][idx]);
    copy(a[j],a[j+1],ed);
    cnt++;
    ssort(bg+1,ed,j+1);

    printf("%d<->%d:",bg,idx);
    for(int i=1;i<=ed;i++)
        printf("%d ",a[j][i]);
    printf("\n");

    return;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[1][i]);
        sorted[i]=a[1][i];
    }
    
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            if(sorted[j]>sorted[j+1])
                swap(sorted[j],sorted[j+1]);
        }
    }

    ssort(1,n,1);
    printf("Total steps:%d\nRight order:",cnt);
    for(int i=1;i<=n;i++)
        printf("%d ",sorted[i]);
    return 0;
}