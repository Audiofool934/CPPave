#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,num=0,maxsize0=0,fp[110][110]={0};
int size0;
char map[110][110];
void islandboy(int x,int y){
    fp[x][y]=1;
    size0++;
    if(map[x+1][y+1]=='I'&&!fp[x+1][y+1]){islandboy(x+1,y+1);}
    if(map[x+1][y]=='I'&&!fp[x+1][y]){islandboy(x+1,y);}
    if(map[x+1][y-1]=='I'&&!fp[x+1][y-1]){islandboy(x+1,y-1);}
    if(map[x-1][y+1]=='I'&&!fp[x-1][y+1]){islandboy(x-1,y+1);}
    if(map[x-1][y]=='I'&&!fp[x-1][y]){islandboy(x-1,y);}
    if(map[x-1][y-1]=='I'&&!fp[x-1][y-1]){islandboy(x-1,y-1);}
    if(map[x][y+1]=='I'&&!fp[x][y+1]){islandboy(x,y+1);}
    if(map[x][y-1]=='I'&&!fp[x][y-1]){islandboy(x,y-1);}
    //printf("size0=%d\n",size0);
    return;
}
int main()
{
    int cnt=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",map[i]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]=='I'&&!fp[i][j]){
                cnt++;
                size0=0;
                //printf("i=%d j=%d\n",i,j);
                islandboy(i,j);
                maxsize0=max(maxsize0,size0);
                
            }
            
        }
    }
    printf("%d %d",cnt,maxsize0);
    return 0;
}

//为啥iostream之后int size0会报错？