#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
struct students{
    int y,nm;
    char xing[65],m[65];
};
int main()
{
    int n;
    char goal[65];
    scanf("%d%s",&n,&goal);
    struct students std[n+1];
    int year[105];
    int ycnt=0;
    for(int i=1;i<=n;i++){
        scanf("%d %s %s",&std[i].y,&std[i].xing,&std[i].m);
        if(!strcmp(std[i].xing,goal)){
            ycnt++;
            year[ycnt]=std[i].y;
        }
    }
    if(ycnt==0) {printf("NONE");return 0;}
    for(int i=1;i<=ycnt-1;i++){
        for(int j=1;j<=ycnt-i;j++){
            if(year[j]>year[j+1]){
                swap(year[j],year[j+1]);
            }
        }
    }
    //for(int i=1;i<=ycnt;i++) printf("%d\n",year[i]);
    int size=1,cnt[ycnt],rzt[ycnt];
    for(int i=1;i<=ycnt;i++) cnt[i]=0;
    //统计次数这里有个错！！！！
    for(int i=1;i<=ycnt-1;i++){
        rzt[size]=year[i];
        cnt[size]++;
        if(year[i]!=year[i+1]){
            size++;
            if(i+1==ycnt){
                rzt[size]=year[ycnt];
                cnt[size]++;
            }
            //cnt[size]++;
        }
        if(year[i]==year[i+1]){
            //cnt[size]++;
            if(i+1==ycnt){
                //rzt[size]=year[ycnt];
                cnt[size]++;
            }
            continue;
            
        }
    }
    for(int i=1;i<=size;i++) printf("%d %d\n",rzt[i],cnt[i]);
    return 0;
}
