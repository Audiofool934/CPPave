#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct{
    int nm;
    int sc[11];
    int fsc;
}student;
int cmp(const void* aa,const void* bb){
    student* a=(student*)aa;
    student* b=(student*)bb;
    if(a->fsc==b->fsc){
        return a->nm-b->nm;
    }
    return b->fsc-a->fsc;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int ssc[m+1];
    for(int i=1;i<=m;i++){
        scanf("%d",&ssc[i]);
    }
    student std[n+1];
    for(int i=1;i<=n;i++){
        std[i].fsc=0;
        scanf("%d",&std[i].nm);
        for(int j=1;j<=m;j++){
            scanf("%d",&std[i].sc[j]);
            if(std[i].sc[j]>=60)
                std[i].fsc+=ssc[j];
        }
    }
    qsort(std+1,n,sizeof(student),cmp);
    for(int i=1;i<=n;i++){
        printf("%d %d\n",std[i].nm,std[i].fsc);
    }
    return 0;
}