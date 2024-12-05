#include<stdio.h>
#include<iostream>
using namespace std;
int maxlen=-99999,maxmaxlen=-99999,r,c,map[50][50];
int ski(int x,int y,int len){
    //x r 行，y c 列
    if(x<1||y<1||x>r||y>c) return 0;
    
    len++;
    if(map[x+1][y]<map[x][y]) maxlen=max(maxlen,ski(x+1,y,len));
    if(map[x-1][y]<map[x][y]) maxlen=max(maxlen,ski(x-1,y,len));
    if(map[x][y+1]<map[x][y]) maxlen=max(maxlen,ski(x,y+1,len));
    if(map[x][y-1]<map[x][y]) maxlen=max(maxlen,ski(x,y-1,len));

    return len;
}
int main()
{
    scanf("%d%d",&r,&c);
    //r行 c列
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            ski(i,j,0);
            maxmaxlen=max(maxmaxlen,maxlen);    
        }
    }
    printf("%d",maxmaxlen);
    return 0;
}

/*//dp
using namespace std;
int r, c, map[50][50], dp[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int ski(int x, int y){
    if(dp[x][y] != 0) return dp[x][y];
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] < map[x][y]){
            dp[x][y] = max(dp[x][y], ski(nx, ny) + 1);
        }
    }
    if(dp[x][y] == 0) dp[x][y] = 1;
    return dp[x][y];
}

int main()
{
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d", &map[i][j]);
        }
    }
    int maxlen = -1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            maxlen = max(maxlen, ski(i, j));
        }
    }
    printf("%d\n", maxlen);
    return 0;
}
*/

//previously
#include<stdio.h>
#include<iostream>
using namespace std;
int n,m;//原来这样就能实现主函数输入、辅助函数调用啊
int map[52][52];//地图
int ski(int x, int y){
    int maxl=1;
    if(map[x][y]>map[x+1][y]&&x<m)
        maxl=max(maxl, ski(x+1,y)+1);
    if(map[x][y]>map[x-1][y]&&x>1)
        maxl=max(maxl, ski(x-1,y)+1);
    if(map[x][y]>map[x][y+1]&&y<n)
        maxl=max(maxl, ski(x,y+1)+1);
    if(map[x][y]>map[x][y-1]&&y>1)
        maxl=max(maxl, ski(x,y-1)+1);
    return maxl;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&map[i][j]);
    int maxL=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            maxL=max(maxL,ski(i,j));
    printf("%d\n",maxL);
    return 0;
}
/*#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 55;

int n, m;
int a[MAXN][MAXN];
int f[MAXN][MAXN];

int dfs(int x, int y) {
    if (f[x][y] > 0) {
        return f[x][y];
    }//优化
    int ans = 1;
    if (x > 1 && a[x][y] > a[x - 1][y]) {
        ans = max(ans, dfs(x - 1, y) + 1);
    }//精华，值得反复品味！
    if (x < n && a[x][y] > a[x + 1][y]) {
        ans = max(ans, dfs(x + 1, y) + 1);
    }
    if (y > 1 && a[x][y] > a[x][y - 1]) {
        ans = max(ans, dfs(x, y - 1) + 1);
    }
    if (y < m && a[x][y] > a[x][y + 1]) {
        ans = max(ans, dfs(x, y + 1) + 1);
    }
    f[x][y] = ans;
    return ans;
}

int main() {
    cin >> n >> m;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
    return 0;
}*/