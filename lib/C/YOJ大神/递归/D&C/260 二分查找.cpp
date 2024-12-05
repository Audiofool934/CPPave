#include <stdio.h>
#include <stdlib.h>
using namespace std;
int goal,cnt=0,pos=-1;
int compare(const void* a, const void* b) {
    return (*(long long*)a - *(long long*)b);
}
void ds(long long arr[],int bg,int ed){
    if(bg>ed) return;
    cnt++;
    //printf("cnt=%d bg=%d ed=%d mid=%d %lld\n",cnt,bg,ed,(bg+ed)/2,arr[(bg+ed)/2]);
    if(arr[(bg+ed)/2]==goal) {
        pos=(bg+ed)/2;
        return;
    }
    if(arr[(bg+ed)/2]>goal) ds(arr,bg,(bg+ed)/2-1);
    if(arr[(bg+ed)/2]<goal) ds(arr,(bg+ed)/2+1,ed);
    return;
}
int main() {
    int n;
    scanf("%d%d",&n,&goal);
    long long arr[n];
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    qsort(arr, n, sizeof(long long), compare);
    ds(arr,0,n-1);
    if(pos==-1){
        printf("-1\n%d",cnt);
    }
    else{
        printf("%d\n%d",pos,cnt);
    }
    return 0;
}
/* 90->100 基线条件不仅要找对，还要放对位置，尤其是有计数要求
这个代码实现的是二分查找算法，但是在处理查找目标goal不在数组arr中的情况时，存在一些问题。

在函数ds中，如果arr[(bg+ed)/2]等于goal，则更新pos的值。然后，如果bg>=ed，则返回。这意味着，如果bg等于ed，并且arr[(bg+ed)/2]不等于goal，函数会直接返回，而不会再进行查找。这可能会导致在goal不在数组arr中的情况下，函数返回错误的结果。

为了解决这个问题，您可以将检查bg>=ed的条件放在更新pos的前面，如下所示：

void ds(long long arr[],int bg,int ed){
    if(bg > ed) return;
    int mid = (bg + ed) / 2;
    cnt++;
    if(arr[mid] == goal) {
        pos = mid;
        return;
    }
    if(arr[mid] > goal) ds(arr, bg, mid - 1);
    else ds(arr, mid + 1, ed);
}

在这个修改后的版本中，如果bg大于ed，函数会立即返回，而不会尝试访问arr[mid]。这可以防止在goal不在数组arr中的情况下访问无效的数组元素。此外，如果找到goal，函数会立即返回，而不会进行不必要的递归调用。
*/