#include<stdio.h>
int n,m,maze[11][11]={0},fp[11][11]={0},yes=0;
void go(int x,int y)
{
    //x行 y列
    //printf("%d %d\n",x,y);
    if(fp[x][y]||maze[x][y]==0||x<1||y<1||x>n||y>m) return;
    fp[x][y]=1;
    if(x==n&&y==m){
        yes=1;
        return;
    }
    go(x+1,y);
    go(x-1,y);
    go(x,y+1);
    go(x,y-1);
    fp[x][y]=0;
    return;
}
int main()
{
    //n行 m列
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    go(1,1);
    if(yes) printf("YES\n");
    else printf("NO\n");
    return 0;
}



#include <iostream>
#include <cstring>
using namespace std;
const int N = 10;
int n, m;
int maze[N][N];
bool st[N][N];

bool dfs(int x, int y)
{
    if (x == n && y == m) return true;  // 到达终点，返回 true
    if (x < 1 || x > n || y < 1 || y > m) return false;  // 越界，返回 false
    if (maze[x][y] == 0 || st[x][y]) return false;  // 遇到墙壁或已经走过，返回 false

    st[x][y] = true;  // 标记为已经走过

    // 按照上下左右的顺序依次尝试
    if (dfs(x - 1, y)) return true;
    if (dfs(x + 1, y)) return true;
    if (dfs(x, y - 1)) return true;
    if (dfs(x, y + 1)) return true;

    st[x][y] = false;  // 回溯到上一个，取消标记
    
    return false;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> maze[i][j];

    memset(st, false, sizeof st);

    if (dfs(1, 1)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
/*
//好像可以遍历——“贴着边儿走”
#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,ways,knotx,knoty;
int maze[11][11];
int dend[11][11];
int run(int x,int y)
{
    //记住节点（？）一条路不通就回溯到节点
    ways=0;
    if(maze[x-1][y]==1&&dend[x-1][y]==0) ways++;
    if(maze[x+1][y]==1&&dend[x+1][y]==0) ways++;
    if(maze[x][y-1]==1&&dend[x][y-1]==0) ways++;
    if(maze[x][y+1]==1&&dend[x][y+1]==0) ways++;
    if(ways>=2){knotx=x;knoty=y;}
    if(maze[x-1][y]==1&&dend[x][y]==0) {dend[knotx][knoty]=0;dend[x][y]=1;run(x-1,y);}
    if(maze[x+1][y]==1&&dend[x][y]==0) {dend[knotx][knoty]=0;dend[x][y]=1;if(x+1==m&&y==n) return 1;run(x+1,y);}
    if(maze[x][y-1]==1&&dend[x][y]==0) {dend[knotx][knoty]=0;dend[x][y]=1;run(x,y-1);}
    if(maze[x][y+1]==1&&dend[x][y]==0) {dend[knotx][knoty]=0;dend[x][y]=1;if(x==m&&y+1==n) return 1;run(x,y+1);}
    run(knotx,knoty);//只能返回一次节点，如果两次就不行了
    return 0;
}
int main()
{
    memset(dend,0,sizeof(dend));
    memset(maze,0,sizeof(maze));
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            maze[i][j]=0;
            dend[i][j]=0;
        }
    }
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            printf("%d",maze[i][j]);
        }
        printf("\n");
    }        
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&maze[i][j]);
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            printf("%d",maze[i][j]);
        }
        printf("\n");
    }     
    if(run(1,1)) printf("YES");
    else printf("NO");
    return 0;
}
*/