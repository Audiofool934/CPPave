//DP×DFS



//DP AC

#include <stdio.h>
#include <limits.h>

#define MAX_N 100

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, A[MAX_N][MAX_N], dp[MAX_N][MAX_N];

    // 读取矩阵大小
    scanf("%d", &n);

    // 初始化动态规划数组
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    dp[0][0] = 0; // 起始点的移动次数为0

    // 读取输入矩阵并进行动态规划
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
            if (A[i][j] > 0 && dp[i][j] != INT_MAX) {
                for (int step = 1; step <= A[i][j]; step++) {
                    // 检查四个方向
                    if (i + step < n) dp[i + step][j] = min(dp[i + step][j], dp[i][j] + 1);
                    if (i - step >= 0) dp[i - step][j] = min(dp[i - step][j], dp[i][j] + 1);
                    if (j + step < n) dp[i][j + step] = min(dp[i][j + step], dp[i][j] + 1);
                    if (j - step >= 0) dp[i][j - step] = min(dp[i][j - step], dp[i][j] + 1);
                }
            }
        }
    }

    // 输出从(1,1)到(n,n)的最少移动次数
    printf("%d\n", dp[n-1][n-1]);

    return 0;
}

//BFS AC
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 100

typedef struct {
    int x, y, step;
} Node;

int n;
int matrix[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

// 队列实现
typedef struct {
    Node items[MAX_N * MAX_N];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

bool isQueueEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, Node item) {
    q->items[q->rear++] = item;
}

Node dequeue(Queue *q) {
    return q->items[q->front++];
}

// 检查新位置是否有效
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && matrix[x][y] != 0;
}

// 执行 BFS 搜索
int bfs() {
    Queue q;
    initQueue(&q);

    enqueue(&q, (Node){0, 0, 0});
    visited[0][0] = true;

    while (!isQueueEmpty(&q)) {
        Node current = dequeue(&q);

        // 到达终点
        if (current.x == n - 1 && current.y == n - 1) {
            return current.step;
        }

        // 尝试所有可能的移动
        for (int i = 1; i <= matrix[current.x][current.y]; i++) {
            // 向四个方向移动
            int dx[] = {i, -i, 0, 0};
            int dy[] = {0, 0, i, -i};

            for (int j = 0; j < 4; j++) {
                int newX = current.x + dx[j];
                int newY = current.y + dy[j];

                if (isValid(newX, newY)) {
                    visited[newX][newY] = true;
                    enqueue(&q, (Node){newX, newY, current.step + 1});
                }
            }
        }
    }

    return -1; // 如果没有路径，则返回 -1
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 初始化访问矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    int result = bfs();
    if (result >= 0) {
        printf("%d\n", result);
    } else {
        printf("No path found\n");
    }
    return 0;
}





//DFS 40/100

//my dfs
#include<stdio.h>
#include<iostream>
using namespace std;
int n,matrix[12][12],fp[12][12]={0},minlen=10000000;
int check(int x,int y,int dist){
    if(dist<=matrix[x][y]){
        return 1;
    }
    
    if(x-1>=1)
    return check(x-1,y,dist+1);
    if(y-1>=1)
    return check(x,y-1,dist+1);
    if(x+1<=n)
    return check(x+1,y,dist+1);
    if(y+1<=n)
    return check(x,y+1,dist+1);

    return 0;
}
void go(int x,int y,int len)//x行 y列
{

    if(x==n&&y==n){
        minlen=min(len,minlen);
        return;
    }
    fp[x][y]=1;
    //for(int i=1;i<=matrix[x][y];i++){
        if(check(x+1,y,1)&&!fp[x+1][y]&&x+1<=n){
            go(x+1,y,len+1);
        }
        if(check(x-1,y,1)&&!fp[x-1][y]&&x-1>=1){
            go(x-1,y,len+1);
        }
        if(check(x,y+1,1)&&!fp[x][y+1]&&y+1<=n){
            go(x,y+1,len+1);
        }
        if(check(x,y-1,1)&&!fp[x][y-1]&&y-1>=1){
            go(x,y-1,len+1);
        }
    //}
    fp[x][y]=0;
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }
    //go(1,1,0);
    printf("%d",check(2,2,1));
    return 0;
}



//gpt dfs

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 100

int n;
int matrix[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
int minSteps = INT_MAX;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n && matrix[x][y] != 0 && !visited[x][y];
}

void dfs(int x, int y, int steps) {
    if (x == n - 1 && y == n - 1) {
        if (steps < minSteps) {
            minSteps = steps;
        }
        return;
    }

    visited[x][y] = true;

    for (int i = 1; i <= matrix[x][y]; i++) {
        // 尝试四个方向的移动
        
        if (isValid(x, y - i)) dfs(x, y - i, steps + 1);
        if (isValid(x, y + i)) dfs(x, y + i, steps + 1);
        if (isValid(x - i, y)) dfs(x - i, y, steps + 1);
        if (isValid(x + i, y)) dfs(x + i, y, steps + 1);
        
    }

    visited[x][y] = false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    dfs(0, 0, 0);

    if (minSteps != INT_MAX) {
        printf("%d\n", minSteps);
    } else {
        printf("No path found\n");
    }

    return 0;
}
