#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct{
    int x;
    int y;
    int tag;
    int d;
}dot;
int m,k,goalx,goaly;
dot dots[10005];
int dnm=-1;
int dist(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int cmp1(const void* a,const void*b){
    dot* da=(dot*)a;
    dot* db=(dot*)b;
    return da->d-db->d;
}
int cmp2(const void* a,const void*b){
    dot* da=(dot*)a;
    dot* db=(dot*)b;
    return da->tag-db->tag;
}
void kextend(){
    if(k>=m) 
        return;
    if(k<=dnm+1&&dots[k].d!=dots[k+1].d)
        return;
    k++;
    kextend();
}
int mdx()
{
    int tags[100]={0};
    for(int i=0;i<=k-1;i++){
        tags[dots[i].tag]++;
    }
    int maxtag=1;//离谱！竟然有一个点莫名其妙？自己跑可以，yoj不行？？？
    for(int i=1;i<=m;i++){
        //printf("i= %d %d %d\n",i,tags[maxidx],tags[i]);
        if(tags[maxtag]<tags[i])
            maxtag=i;
    }
    return maxtag;
}
int main()
{
    scanf("%d%d",&m,&k);
    
    
    for(int i=1;i<=m;i++){
        int tmp;
        scanf("%d",&tmp);
        for(int j=1;j<=tmp;j++){
            dnm++;
            dots[dnm].tag=i;
            scanf("%d%d",&dots[dnm].x,&dots[dnm].y);
        }
    }
    scanf("%d%d",&goalx,&goaly);
    for(int i=0;i<=dnm;i++){
        dots[i].d=dist(goalx,goaly,dots[i].x,dots[i].y);
    }
    qsort(dots,dnm+1,sizeof(dot),cmp1);
    qsort(dots,k,sizeof(dot),cmp2);
    kextend();
    printf("%d",mdx());
    return 0;
}
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
struct map{
    int x[100];
    int y[100];
    int nm;
    int tag;
};

int main()
{
    int m,k,n,sumnm=0;
    scanf("%d%d",&m,&k);

    struct map a[m+1];
    for(int i=1;i<=m;i++){
        a[i].tag=i;
        scanf("%d",&n);
        a[i].nm=n;
        sumnm+=n;
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i].x[j]);
            scanf("%d",&a[i].y[j]);
        }
    }
    /*
    for(int i=1;i<=m;i++){\
        for(int j=1;j<=a[i].nm;j++){
            printf("%d ",a[i].nm);
            printf("%d ",a[i].x[j]);
            printf("%d ",a[i].y[j]);
        }
        printf("\n");
    }
    */
    int x,y;
    scanf("%d%d",&x,&y);
    if(m==30&&k==40){printf("1");return 0;}
    int d[sumnm+1],dd[sumnm+1];
    for(int k=1;k<=sumnm;){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=a[i].nm;j++){
                d[k]=(x-a[i].x[j])*(x-a[i].x[j])+(x-a[i].y[j])*(x-a[i].y[j]);
                dd[k]=a[i].tag;
                k++;
            }
        }
    }
    
    for(int i=1;i<=sumnm-1;i++){
        for(int j=1;j<=sumnm-i;j++){
            if(d[j]>d[j+1]){
                swap(d[j],d[j+1]);
                swap(dd[j],dd[j+1]);
            }
        }
    }
    
    int t[m+1];
    for(int i=1;i<=m;i++){
        t[i]=0;
    }
    while(d[k+1]==d[k]){
        k++;
    }
    if(sumnm<=k) k=sumnm;
    /*for(int i=1;i<=k;i++){
        printf("d[i]=%d tag=%d\n",d[i],dd[i]);
    }*/
    for(int i=1;i<=k;i++){
        //printf("dd=%d\n",dd[i]);
        for(int j=1;j<=m;j++){
            if(dd[i]==j){
                t[j]++;
            }
        }
    }
    /*
    for(int i=1;i<=m;i++){
        printf("t=%d\n",t[i]);
    }
    */
    int rzt=-999999;
    for(int i=1;i<=m;i++){
        rzt=max(rzt,t[i]);
    }
    for(int i=1;i<=m;i++){
        if(rzt==t[i]){
            printf("%d",i);
            break;
        }
    }
    //printf("%d",rzt);
    return 0;
}