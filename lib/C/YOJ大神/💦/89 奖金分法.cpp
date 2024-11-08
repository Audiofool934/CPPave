#include<stdio.h>
int main()
{
    int s,n,x,m1;
    scanf("%d",&n);
    if(n==0)
    {
        scanf("%d",&s);
        printf("0.00");
    }
    else{
    int a[n-2];
    double t_1=0,t_2=0,y_1,y_2,z,b[n-1];
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %lf",&a[i],&b[i]);
    }
    scanf("%d %lf",&m1,&z);
    scanf("%d",&x);
    if(x<0)
    {
        printf("NO\n");
    }
    else if(x>a[n-2])
    {
        for(int l=1;l<n-1;l++)
        {
            t_1=t_1+(a[l]-a[l-1])*b[l];
        }
        y_1=a[0]*b[0]+t_1+(x-a[n-2])*z;
        printf("%.2f\n",y_1);
    }
    else if(x<=a[0])
    {
        printf("%.2f\n",x*b[0]);
    }
    else if(x<=a[1])
    {
        printf("%.2f\n",a[0]*b[0]+(x-a[0])*b[1]);
    }
    else
    {
        for(int i=1;i<n-1;i++)
        {
            if(a[i]<x&&x<=a[i+1])
            {
                for(int i=1;i<i+1;i++)
                {
                    t_2=t_2+(a[i]-a[i-1])*b[i];
                }
                y_2=t_2+a[0]*b[0]+(x-a[i])*b[i+1];
                printf("%.2f\n",y_2);
                break;
            }
        }
    }    
    }
    return 0;
}
//注意特殊情况（全面性）e.g. n=0；是否有更简方法？
//和 7 类似，为什么用float 会有两个错？
//注意n个数求和的基本方法