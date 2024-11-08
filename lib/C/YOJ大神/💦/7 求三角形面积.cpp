#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,q,S;
    scanf("%lf%lf%lf",&a,&b,&c);
    q=(a+b+c)/2;//如果a,b,c定义为整型，需要除以2.0
    S=sqrt(q*(q-a)*(q-b)*(q-c));
    printf("%.2f\n",S);
    return 0;
}
//为什么用float会有两个错？———经验：浮点都用double