#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 105;
int dp[MAXN][MAXN];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++)
            cin >> dp[i][j];

    for(int i = n-2; i >= 0; i--)
        for(int j = 0; j <= i; j++)
            dp[i][j] += max(dp[i+1][j], dp[i+1][j+1]);

    cout << dp[0][0] << endl;

    return 0;
}

/*#include<stdio.h>
#include<iostream>
using namespace std;
int n,sum=0,maxs=-1,tree[110][110],fp[110][110];
//第0行0列都是墙
int clm(int x,int y){
    if(x==0||x==y+1||fp[x][y]){
        return 0;
    }
    if(x==1&&y==1){
        maxs=max(maxs,sum);
        sum=0;
    }
    fp[x][y]=1;
    if(clm(x-1,y-1)){
        sum+=tree[x][y];
        return 1;
    }
    if(clm(x,y-1)){
        sum+=tree[x][y];
        return 1;
    }
    fp[x][y]=0;
    return 0;
}
void ini()
{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            fp[i][j]=0;
        }
    }
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&tree[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        ini();
        clm(i,n);
    }
    printf("%d",maxs);
    return 0;
}
*/