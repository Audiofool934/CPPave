/* 冒泡排序
    for (int i = 0; i < n - 1; i++) {
        for (int l = 0; l < n - i - 1; l++) {
            if (arr[l] > arr[l + 1]) {
                temp = arr[l];
                arr[l] = arr[l + 1];
                arr[l + 1] = temp;
            }
        }
    }
    0,1,2,...,n-1
    
    0,1,2,...,n-4,n-3,n-2//把最大的排到最后
    0,1,2,...,n-4,n-3//把第二大的排到最后
    0,1,2,...,n-4//...
    ...
    0,1
*/ 

#include<stdio.h>
int main()
{
    int n,h;
    scanf("%d",&n);
    int a[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int l=0;l<n-i-1;l++)
        {
            if(a[l]>a[l+1])
            {
                h=a[l];
                a[l]=a[l+1];
                a[l+1]=h;
            }//这里记得加括号啊。。。
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
//关于数组的细节? 0,1,2,...,n-1|1,2,3,...,n