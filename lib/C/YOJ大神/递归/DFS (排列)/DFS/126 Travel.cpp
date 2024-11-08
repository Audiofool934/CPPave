#include<stdio.h>
#include<iostream>
using namespace std;
int maxt=-99999,sumt,tresure,n,m,map[10][10]={0},fp[10][10]={0};
void travel(int x,int y){
    if(fp[x][y]||x==0||y==0||x==n+1||y==m+1) return;
    
    fp[x][y]=1;
    sumt+=map[x][y];
   
    if(x==n&&y==m){
        maxt=max(maxt,sumt);
    }//对比下面的错误，递归没有特例！！
    travel(x,y+1);
    travel(x+1,y);
    travel(x,y-1);
    
    fp[x][y]=0;
    sumt-=map[x][y];
    
    return;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&map[i][j]);
        }
    }
    travel(1,1);
    printf("%d",maxt);
    return 0;
}
/*
void travel(int x,int y){
    if(fp[x][y]||x==0||y==0||x==n+1||y==m+1) return;
    if(x==n&&y==m){
        maxt=max(maxt,sumt);
        sumt-=map[x][y];
        return;
    }
    fp[x][y]=1;
    sumt+=map[x][y];
    travel(x,y+1);
    travel(x+1,y);
    travel(x,y-1);
    fp[x][y]=0;
    sumt-=map[x][y];
    return;
}
*/
