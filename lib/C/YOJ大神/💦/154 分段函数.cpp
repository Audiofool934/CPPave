#include<stdio.h>
#include<math.h>
int main()
{
    double x;
    scanf("%lf",&x);
    if(x<0)
    {
        printf("%.2f\n",-x);
    } 
    else if(0<=x&&x<=1)
    {
        printf("%.2f\n",sqrt(x));
    }
    else
    {
        printf("%.2f\n",x*x);
    }
    return 0;
}