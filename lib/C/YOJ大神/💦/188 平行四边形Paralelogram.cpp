#include<stdio.h>
int main()
{
    double x[3],y[3],vx[3],vy[3],d[3];
    for(int i=0;i<3;i++)
        scanf("%lf%lf",&x[i],&y[i]);
    for(int i=0;i<2;i++){
        vx[i]=x[i+1]-x[i];
        vy[i]=y[i+1]-y[i];
    }
    vx[2]=x[0]-x[2];
    vy[2]=y[0]-y[2];
    printf("3\n");
    printf("%.0f %.0f\n",x[1]+vx[2],y[1]+vy[2]);
    printf("%.0f %.0f\n",x[0]+vx[1],y[0]+vy[1]);
    printf("%.0f %.0f\n",x[2]+vx[0],y[2]+vy[0]);
    return 0;
    //小题大做的循环...
}