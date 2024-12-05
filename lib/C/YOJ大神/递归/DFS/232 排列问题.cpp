#include<stdio.h>
#include<iostream>
using namespace std;
int n,mtd=0,abc[27]={0},output[505];
void A(int pos)
{
    if(pos==n+1){
        for(int j=1;j<=n;j++){
            printf("%c",output[j]+'a'-1);
        }
        printf("\n");
        mtd++;
        return;
    }
    for(int i=1;i<=26;i++){
        if(abc[i]>0){
            output[pos]=i;
            abc[i]--;
            A(pos+1);
            abc[i]++;
        }
    }
    return;
}
int main()
{
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++){
        abc[getchar()-'a'+1]++;
    }
    A(1);
    printf("%d\n",mtd);
    return 0;
}