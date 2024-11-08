#include<stdio.h>
int main()
{
    int a,b,sum=0;
    scanf("%d%d",&a,&b);
    for(int i=a;i<=b;i++){
        if(i/1000!=0){
            if((i*i)%10000==i)
                sum+=i;
        }
        if(i/100!=0){
            if((i*i)%1000==i)
                sum+=i;
        }
        if(i/10!=0){
            if((i*i)%100==i)
                sum+=i;
        }
        else{
            if((i*i)%10==i)
                sum+=i;
        }
        //i*i<10的不可能是同构数..
    }
    printf("%d",sum);
}