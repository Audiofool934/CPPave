#include<stdio.h>
#include<math.h>
struct students{
    int nm;
    int sc;
    int n;
};
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int sl=floor(m*1.5);
    struct students stu[n+1];
    for(int i=1;i<=n;i++){
        scanf("%d %d",&stu[i].nm,&stu[i].sc);
    }
    struct students tmp;
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            if(stu[j].nm>stu[j+1].nm){
                tmp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=tmp;
            }
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=n-i;j++){
            if(stu[j].sc<stu[j+1].sc){
                tmp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=tmp;
            }
        }
    }

    int r=1;
    for(int i=1;i<=n;i++){
        stu[i].n=r;
        while(stu[i].sc==stu[i+1].sc){
            stu[i+1].n=r;
            i++;
        }
        r++;
    }
    int s=0;
    for(int i=1;stu[i].n<=sl&&stu[i].sc>=stu[sl].sc;i++){
        s++;
    }
    printf("%d %d\n",stu[sl].sc,s);
    for(int i=1;stu[i].n<=sl&&stu[i].sc>=stu[sl].sc;i++){
        printf("%d %d\n",stu[i].nm,stu[i].sc);
    }
    return 0;
}
//细节很多，值得注意！审题审题审题，边界值一定要搞清楚！