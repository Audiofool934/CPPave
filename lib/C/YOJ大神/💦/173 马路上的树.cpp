#include<stdio.h>
int road[10000]={0};
void plt(int bg,int ed){
    for(int i=bg;i<=ed;i++){
        road[i]=1;
    }
}
int main()
{
    int l,m,bg,ed;
    scanf("%d%d",&l,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&bg,&ed);
        plt(bg,ed);
    }
    int cnt=0;
    for(int i=0;i<=l;i++){
        if(!road[i]){
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}