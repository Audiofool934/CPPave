#include<stdio.h>
int main()
{
    double i,i=0,Sn=0;
    scanf("%lf",&i);
    while(i>=Sn){
        i++;
        Sn+=(1/i);
    }
    printf("%.0f",i);
    return 0;
}
//while注意条件方向