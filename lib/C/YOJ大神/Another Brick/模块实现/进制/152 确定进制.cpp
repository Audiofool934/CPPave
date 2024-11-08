#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int ten;
int dvd(int n,int a){
    int b[10];
    int k=1;
    ten=0;
    while(n>0){
        b[k]=n%10;
        if(b[k]>=a) return -1;
        //printf("b[%d]=%d\n",k,b[k]);
        ten+=(int)pow(a,k-1)*b[k];
        k++;
        n/=10;
    }
    return 0;
}//把一个 a 进制的数字 n 改写成十进制
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
    int p,q,r;
    scanf("%d%d%d",&p,&q,&r);

    int no=1;
    for(int i=2;i<=16;i++){
        if(dvd(p,i)==-1) continue;
        int a=ten;
        if(dvd(q,i)==-1) continue;
        int b=ten;
        if(dvd(r,i)==-1) continue;
        int c=ten;
        if((a*b)==c){
            printf("%d\n",i);
            no=0;
            break;
        }
    }
    if(no) printf("0\n");
    }
    return 0;
}