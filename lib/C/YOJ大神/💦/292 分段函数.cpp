#include<stdio.h>
#include<math.h>
double f(double x)
{
    if (fabs(x)<=1){
        return fabs(x-1)-2;
    }
    else{
        return fabs(1/(1+x*x));
    }
}
int main()
{
    double x;
    scanf("%lf",&x);
    printf("%.2f",f(f(x)));
    return 0;
}