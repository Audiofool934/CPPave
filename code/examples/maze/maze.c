#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void go(int x, int y, const int n, const int m, int** maze, int** fp, bool* yes)
{
    if (*yes == true || x < 0 || y < 0 || x > n-1 || y > m-1 || fp[x][y] == 1 || maze[x][y] == 0) {
        return;
    }
    if (x == n - 1 && y == m - 1){
        *yes = true;
        return;
    }
    fp[x][y] = 1;
    go(x + 1, y, n, m, maze, fp, yes);
    go(x, y + 1, n, m, maze, fp, yes);
    go(x - 1, y, n, m, maze, fp, yes);
    go(x, y - 1, n, m, maze, fp, yes);
}


int main()
{
    int n, m; //n行 m列
    scanf("%d%d", &n, &m);

    int** maze = (int**)malloc(n * sizeof(int*));
    int** fp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++){
        maze[i] = (int*)malloc(m * sizeof(int));
        fp[i] = (int*)calloc(m, sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    
    bool yes = false;
    go(0, 0, n, m, maze, fp, &yes);
    
    if(yes) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    for (int i = 0; i < n; i++){
        free(maze[i]);
        free(fp[i]);
    }
    free(maze);
    free(fp);

    return 0;
}
