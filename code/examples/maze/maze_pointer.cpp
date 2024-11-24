#include <stdio.h>

void go(int x, int y, const int n, const int m, int** maze, int** fp, bool& yes)
{
    if (yes == 1 || x < 0 || y < 0 || x > n-1 || y > m-1 || fp[x][y] == 1 || maze[x][y] == 0) return;

    if (x == n - 1 && y == m - 1){
        yes = 1;
        return;
    }

    fp[x][y] = 1;
    
    go(x + 1, y, n, m, maze, fp, yes);
    go(x, y + 1, n, m, maze, fp, yes);
    go(x - 1, y, n, m, maze, fp, yes);
    go(x, y - 1, n, m, maze, fp, yes);
    
    fp[x][y] = 0;
}



int main()
{
    int n, m; //n行 m列
    scanf("%d%d", &n, &m);

    int** maze = new int*[n];
    int** fp = new int*[n];
    for (int i = 0; i < n; i++){
        maze[i] = new int[m];
        fp[i] = new int[m]{0};
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &maze[i][j]);
        }
    }
    
    bool yes = false;
    go(0, 0, n, m, maze, fp, yes);
    
    if(yes) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    for (int i = 0; i < n; i++){
        delete[] maze[i];
        delete[] fp[i];
    }
    delete[] maze;
    delete[] fp;

    return 0;
}
