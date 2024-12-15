#include<stdio.h>
#include<limits.h>

const int MAXN = 10;
int maxt = INT_MIN, sumt, n, m;
int map[MAXN][MAXN] = {0}, fp[MAXN][MAXN] = {0};

void travel(int x, int y) {
    // 边界条件：是否越界或已经访问
    if (x < 1 || y < 1 || x > n || y > m || fp[x][y]) return;
    
    // 标记当前格子已访问
    fp[x][y] = 1;
    sumt += map[x][y];
    
    // 如果到达终点，更新最大宝物值
    if (x == n && y == m) {
        if (sumt > maxt) {
            maxt = sumt;
        }
    } else {
        // 尝试移动三个方向：右、下、左
        travel(x, y + 1); // 向右
        travel(x + 1, y); // 向下
        travel(x, y - 1); // 向左
    }
    
    // 回溯：撤销访问标记和当前宝物值
    fp[x][y] = 0;
    sumt -= map[x][y];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    travel(1, 1);
    printf("%d", maxt);
    return 0;
}