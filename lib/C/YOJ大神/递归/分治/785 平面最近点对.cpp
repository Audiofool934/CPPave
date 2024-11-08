#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_W 75
#define MAX_H 75

int w, h;
char board[MAX_H][MAX_W + 2];
int visited[MAX_H][MAX_W];
int min_segments;

int is_valid(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h && board[y][x] == ' ';
}

void dfs(int x, int y, int tx, int ty, int dir, int segments) {
    if (segments > 10) return;
    if (x == tx && y == ty) {
        if (min_segments > segments) min_segments = segments;
        return;
    }

    visited[y][x] = 1;

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (is_valid(nx, ny) && !visited[ny][nx]) {
            dfs(nx, ny, tx, ty, i, dir == -1 || dir == i ? segments : segments + 1);
        }
    }

    visited[y][x] = 0;
}

int main() {
    scanf("%d %d", &w, &h);
    for (int i = 0; i < h; i++) {
        scanf("%s", board[i]);
    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        x1--; y1--; x2--; y2--;

        memset(visited, 0, sizeof(visited));
        min_segments = 11;
        dfs(x1, y1, x2, y2, -1, 0);

        if (min_segments <= 10) {
            printf("%d\n", min_segments);
        } else {
            printf("impossible\n");
        }
    }

    return 0;
}
