#include<stdio.h>
#include<stdlib.h>
int a[1000010];
int compare(const void* aa,const void* bb){
    int* a=(int*)aa;
    int* b=(int*)bb;
    return *a-*b;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    qsort(a+1,n,sizeof(int),compare);
    for(int i=1;i<=n;i++)
        printf("%d\n",a[i]);
    return 0;
}