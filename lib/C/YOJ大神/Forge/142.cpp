#include<stdio.h>
#include<stdlib.h>
int m,n,k;
int sortclm[101];

int cmp(const void* a,const void* b){
    int *row1=*(int**)a;
    int *row2=*(int**)b;
    for(int i=1;i<=k;i++){
        if(row1[sortclm[i]]!=row2[sortclm[i]]){
            return row1[sortclm[i]]-row2[sortclm[i]];
        }
    }
    return row1[1]-row2[1];
}

int main()
{
    
    scanf("%d%d%d",&m,&n,&k);
    // m行 n列
    int table[m+1][n+1];
    int* a[m+1];
    for(int i=1;i<=k;i++)
        scanf("%d",&sortclm[i]);
    for(int i=1;i<=m;i++){
        a[i]=table[i];
        for(int j=1;j<=n;j++){
            scanf("%d",&table[i][j]);
        }
    }

    qsort(a+1,m,sizeof(int *),cmp);

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}