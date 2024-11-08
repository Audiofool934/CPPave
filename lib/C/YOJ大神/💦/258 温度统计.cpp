#include<stdio.h>
double T(double a)
{
    return 32+a*1.8;
}
int main()
{
    int n,l=0,i=0;
    double h,l;
    char c,d,e;
    scanf("%d",&n);
    double a[n],sum=0;
    scanf("%lf%c%lf%c",&h,&c,&l,&d);
    if(c=='C'){
        h=T(h);
    }
    if(d=='C'){
        l=T(l);
    }
    for(int i=0;i<n;i++){
        scanf("%lf%c",&a[i],&e);
        if(e=='C'){
            a[i]=T(a[i]);
        }
        sum+=a[i];
        if(a[i]>=h){
            l++;
        }
        if(a[i]<=l){
            i++;
        }
    }
    printf("%.3fF\n%d %d",sum/(double)n,l,i);
    return 0;
}
//注意函数返回值的数据类型