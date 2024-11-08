#include<stdio.h>
#include<iostream>
using namespace std;
int main(void){
    int a[3],tmp;
    scanf("%d,%d,%d",&a[0],&a[1],&a[2]);
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1-i;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                /*tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;*/
            }
        }
    }
    printf("%d,%d,%d\n",a[0],a[1],a[2]);
    return 0;
}
//别忘了输入输出格式

/*
#include<stdio.h>
int main()
{
    int x,y,z,a,b,c,d,e,h;
    scanf("%d,%d,%d",&x,&y,&z);
    if(x>y)
    {
        a=x,y=x,x=a;
        if(x>z)
        {
            b=x,z=x,x=b;
            printf("%d,%d,%d\n",x,y,z);
        }
        else
        {
            if(y>z)
            {
                h=y,z=y,y=h;
                printf("%d,%d,%d\n",x,y,z);
            }
            else
            {
                printf("%d,%d,%d\n",x,y,z);
            }
        }
    }
    else
    {
        if(y>z)
        {
            h=y,z=y,y=h;
        }
        else
        {
            printf("%d,%d,%d\n",x,y,z);
        }
    }
    printf("%d,%d,%d\n",x,y,z);
    return 0;
}
*/