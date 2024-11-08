#include<stdio.h>
#include<math.h>
int main(void)
{
    int sum=0;
    double a;
    scanf("%lf",&a);
    double x=a/2;
    while(1)
    {
        double tmp=x;
        x=0.5*(x+a/x);
        sum++;
        if(fabs(x-tmp)<0.00001) break;
    }
    printf("%.6f\n%d",x,sum);
    return 0;
}