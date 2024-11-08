#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
int nm(const void* a,const void* b){
    return *(int*)b-*(int*)a;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int max=1,brk=0;
    qsort(a+1,n,sizeof(int),nm);
    for(int i=1;i<=n-2;i++){
        for(int j=i+1;j<=n-1;j++){
            for(int k=j+1;k<=n;k++){
                if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]>a[i]&&abs(a[i]-a[j])<a[k]&&(a[i]-a[k])<a[j]&&abs(a[j]-a[k])<a[i]){
                    //printf("%d %d %d\n",a[i],a[j],a[k]);
                    max=a[i]+a[j]+a[k];
                    printf("%d",max);
                    brk=1;
                    break;
                }
            }
            if(brk) break;
        }
        if(brk) break;
    }
    if(max==1) printf("0");
    return 0;
}