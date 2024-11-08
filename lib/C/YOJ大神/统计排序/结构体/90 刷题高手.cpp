#include<stdio.h>
struct students{
    int nm;
    int p;
    int qs[105];
    int ac;
    int rank;
};
int main()
{
    int n,m,k;
    scanf("%d",&n);
    int q[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&q[i]);
    scanf("%d %d",&m,&k);
    students stu[m+1];
    for(int i=1;i<=m;i++){
        scanf("%d %d",&stu[i].nm,&stu[i].p);
        for(int j=1;j<=stu[i].p;j++){
            scanf("%d",&stu[i].qs[j]);
        }
    }
    struct students tmp;
    for(int i=1;i<=m-1;i++){
        for(int j=1;j<=m-i;j++){
            if(stu[j].nm>stu[j+1].nm){
                tmp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=tmp;
            }
        }
    }
    for(int i=1;i<=m;i++){
        stu[i].ac=0;
        for(int j=1;j<=stu[i].p;j++){
            for(int k=1;k<=n;k++){
                if(stu[i].qs[j]==q[k]){
                    stu[i].ac++;
                }
            }
        }
    }
    for(int i=1;i<=m-1;i++){
        for(int j=1;j<=m-i;j++){
            if(stu[j].ac<stu[j+1].ac){
                tmp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=tmp;
            }
        }
    }
    int rank=1;
    for(int i=1;i<=m;i++){
        stu[i].rank=rank;
        while(stu[i].ac==stu[i+1].ac){
            stu[i+1].rank=rank;
            i++;
        }
        rank++;
    }
    //for(int i=1;i<=m;i++){
        //printf("stu[%d].nm = %d stu[%d].ac = %d stu[%d].rank = %d\n",i,stu[i].nm,i,stu[i].ac,i,stu[i].rank);
    //}
    int s=1;
    while(stu[s].rank<=k){
        printf("%d ",stu[s].nm);
        if(s==m) break;//细节once aginnnnn
        s++;
    }
    //printf("s=%d\n",s);
    //printf("nm=%d\n",stu[k].nm);
    return 0;
}
/*#include<stdio.h>
#include<stdlib.h>
struct students{
    int nm;
    int p;
    int qs[101];
    int ac;
    int rank;
};
int cmp(const void *a, const void *b) {
    struct students *s1 = (struct students *)a;
    struct students *s2 = (struct students *)b;
    if (s1->ac != s2->ac) {
        return s2->ac - s1->ac;
    } else {
        return s1->nm - s2->nm;
    }
}
int main()
{
    int n,m,k;
    scanf("%d",&n);
    int q[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&q[i]);
    scanf("%d %d",&m,&k);
    students stu[m+1];

    for(int i=1;i<=m;i++){
        scanf("%d %d",&stu[i].nm,&stu[i].p);
        for(int j=1;j<=stu[i].p;j++){
            scanf("%d",&stu[i].qs[j]);
        }
    }

    for(int i=1;i<=m;i++){
        stu[i].ac=0;
        for(int j=1;j<=stu[i].p;j++){
            for(int k=1;k<=n;k++){
                if(stu[i].qs[j]==q[k]){
                    stu[i].ac++;
                }
            }
        }
    }
    qsort(stu+1, m, sizeof(struct students), cmp);

    int rank=1;
    for(int i=1;i<=m;i++){
        stu[i].rank=rank;
        while(stu[i].ac==stu[i+1].ac){
            stu[i+1].rank=rank;
            i++;
        }
        rank++;
    }
    int s=1;
    while(stu[s].rank<=k){
        printf("%d ",stu[s].nm);
        s++;
    }
    return 0;
}*/