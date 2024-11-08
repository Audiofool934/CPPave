#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_W 75
#define MAX_H 75
#define MAX_SEGMENTS 10

typedef struct {
    int x, y, seg; // seg 表示线段数
} Node;

char board[MAX_H][MAX_W];
int visited[MAX_H][MAX_W][MAX_SEGMENTS + 1];
int w, h;

int is_valid(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h && board[y][x] != 'X';
}

int bfs(int x1, int y1, int x2, int y2) {
    memset(visited, 0, sizeof(visited));

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    Node queue[MAX_W * MAX_H * (MAX_SEGMENTS + 1)];
    int front = 0, rear = 0;

    // 初始节点
    queue[rear++] = (Node){x1, y1, 0};
    visited[y1][x1][0] = 1;

    while (front < rear) {
        Node current = queue[front++];

        if (current.x == x2 && current.y == y2) {
            return current.seg;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = current.x, ny = current.y, nseg = current.seg;

            while (is_valid(nx + dx[i], ny + dy[i])) {
                nx += dx[i];
                ny += dy[i];

                if (visited[ny][nx][nseg]) continue;

                visited[ny][nx][nseg] = 1;
                queue[rear++] = (Node){nx, ny, nseg};

                if (nx == x2 && ny == y2) {
                    return nseg;
                }
            }

            // 转弯
            if (nseg < MAX_SEGMENTS && !visited[current.y][current.x][nseg + 1]) {
                visited[current.y][current.x][nseg + 1] = 1;
                queue[rear++] = (Node){current.x, current.y, nseg + 1};
            }
        }
    }

    return -1; // 找不到路径
}

int main() {
    scanf("%d %d", &w, &h);
    getchar(); // 吸收换行符
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            board[i][j] = getchar();
        }
        getchar(); // 吸收换行符
    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1--; y1--; x2--; y2--; // 转换为数组下标

        int result = bfs(x1, y1, x2, y2);
        if (result == -1 || result > MAX_SEGMENTS) {
            printf("impossible\n");
        } else {
            printf("%d\n", result);
        }
    }

    return 0;
}