#include<stdio.h>
int main()
{
    int n,i=0,b[50],c[50],tempb,tempc,s=0;
    scanf("%d",&n);
    int x1[n],x2[n],x3[n],x4[n];
    for(int i=0;i<n;i++)
        scanf("%d",&x1[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&x2[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&x3[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&x4[i]);
    for(int i=0;i<n;i++){
        if(x2[i]+(x3[i]/10.0)*x4[i]>0){
            b[i]=x1[i];
            c[i]=i;
            i++;
            s++;
        }
    }
    for(int i=0;i<s-1;i++){
        for(int l=0;l<s-1-i;l++){
            if(b[l]>b[l+1]){
                tempb=b[l];
                b[l]=b[l+1];
                b[l+1]=tempb;
                tempc=c[l];
                c[l]=c[l+1];
                c[l+1]=tempc;
            }
        }
    }
    if(s==0) printf("0");
    else printf("%d",c[0]+1);
    return 0;
}

//二维数组是横着的还是竖着的...注意排序别排反了...绕弯实现结构体...审题（注意题目标注的特殊情况处理）