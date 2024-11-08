#include<stdio.h>
int main()
{
    float p;
    int n;
    scanf("%f %d",&p,&n);
    if(n==0)
    {
        printf("0");
    }
    if(n==1)
    {
        printf("%.2f",p);
    }
    if(n==2)
    {
        printf("%.2f\n",n*p*0.8);
    }
    if(3<=n&&n<=5)
    {
        printf("%.2f\n",n*p*0.7);
    }
    if(5<n)
    {
        printf("%.2f\n",5*p*0.7+(n-5)*p*1.1);
    }
    return 0;
}