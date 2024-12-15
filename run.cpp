#include <stdio.h>
#include <cstring>

#define MAXN 100 // 树的最大层数

int tree[MAXN][MAXN]; // 存储树上每层的桃子数
int dp[MAXN][MAXN];   // 动态规划数组，dp[i][j] 表示从第 i 层的第 j 个位置开始能摘到的最多桃子数

int main() {
    int n; // 树的层数
    scanf("%d", &n);

    // 输入树上的桃子数
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &tree[i][j]);
        }
    }

    // 初始化 dp 数组为 0
    memset(dp, 0, sizeof(dp));

    // 动态规划：从树的最后一层开始往上推
    for (int i = 1; i <= n; i++) {
        dp[n][i] = tree[n][i]; // 最底层的最大桃子数就是该层的桃子数本身
    }

    for (int i = n - 1; i >= 1; i--) { // 从倒数第二层开始向上计算
        for (int j = 1; j <= i; j++) {
            // 状态转移方程：dp[i][j] = tree[i][j] + max(dp[i+1][j], dp[i+1][j+1])
            dp[i][j] = tree[i][j] + (dp[i + 1][j] > dp[i + 1][j + 1] ? dp[i + 1][j] : dp[i + 1][j + 1]);
        }
    }

    // dp[1][1] 即为从树顶开始摘到的最多桃子数
    printf("%d\n", dp[1][1]);

    return 0;
}