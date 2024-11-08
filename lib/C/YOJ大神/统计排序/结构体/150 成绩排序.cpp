#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int n,s;
}students;

int cmp(const void* stda,const void* stdb){
    students* a=(students*)stda;
    students* b=(students*)stdb;
    if(a->s!=b->s)
        return b->s-a->s;
    else
        return a->n-b->n;
}

int main()
{
    int N;
    scanf("%d",&N);
    students stu[N+1],tmp;
    for(int i=1;i<=N;i++){
        scanf("%d%d",&stu[i].n,&stu[i].s);
    }
    
    qsort(stu+1,N,sizeof(students),cmp);

    for(int rank=1,tmp=-1,i=1;i<=N;i++){
        if(stu[i].s!=tmp){
            tmp=stu[i].s;
            rank=i;
        }
        printf("%d %d %d\n",rank,stu[i].n,stu[i].s);
    }
    return 0;
}





#include<stdio.h>
struct table{
    int num;
    int l[100];
};
int main(void)
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    int a[k+1];
    for(int i=1;i<=k;i++)
        scanf("%d",&a[i]);
    struct table tab[n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&tab[i].l[j]);
        }
    }
    struct table tmp;
    /*for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",tab[j].l[a[i]]);
        }
        printf("\n");
    }*/
    int l=0;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n-1;j++){
            for(int k=1;k<=n-j;k++){
                if(tab[k].l[a[i]]>tab[k+1].l[a[i]]){
                    tmp=tab[k];
                    tab[k]=tab[k+1];
                    tab[k+1]=tmp;
                }
            }
        }
        //for(int j=1;j<=n;j++){
        //    printf("%d ",tab[j].l[a[i]]);
        for(int j=1;j<=n-1;j++){
            if(tab[j].l[a[i]]==tab[j+1].l[a[i]]){
                l++;
                printf("l=%d",l);
            }
        }
    }
    printf("\n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ",tab[i].l[j]);
        }
        printf("\n");
    }
}
