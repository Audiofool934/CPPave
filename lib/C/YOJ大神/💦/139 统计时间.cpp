#include<stdio.h>
int main()
{
    int n,temp,sum=0;
    scanf("%d",&n);
    int a[200];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    for(int i=0;i<n-1;i++){
        for(int l=0;l<n-1-i;l++){
            if(a[l]>a[l+1]){
                temp=a[l];
                a[l]=a[l+1];
                a[l+1]=temp;
            }
        }
    }
    double s=sum,m=n;
    printf("%d %d %.0lf\n",a[n-1],a[0],s/m);
    return 0;
}
//注意四舍五入输出，小数除法