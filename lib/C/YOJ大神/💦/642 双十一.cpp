#include<stdio.h>
int main()
{
    int i=0;
    double a,b,c,d;
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
    double sum=a*c+b*d;
    if((c+d)==2) sum*=0.9;
    if((c+d)==3||(c+d)==4) sum*=0.8;
    if((c+d)==5) sum*=0.7;
    double sum2=a*c+b*d;
    while((sum2-500)>=0){
        sum2-=500;
        i++;
    }
    if(sum<=(a*c+b*d-100*i)) printf("1 %.1f",sum);
    else printf("2 %.1f",a*c+b*d-100*i);
    return 0;
}
//全用double是否妥当？