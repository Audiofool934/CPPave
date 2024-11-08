#include<stdio.h>
#include<math.h>
int main()
{
    float x;
    scanf("%f",&x);
    if(x<0)
    {
        printf("%.2f\n",-x);
    }
    if(0<=x&&x<=1)
    {
        printf("%.2f\n",sqrt(x));
    }
    if(x>1)
    {
        printf("%.2f\n",x*x);
    }
    return 0;
}