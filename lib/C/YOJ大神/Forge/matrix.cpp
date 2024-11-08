#include <stdio.h>
int n;
int a[100][100];
int b[100][100];
int min = 10000;
int cnt =1;

void search(int x, int y) {
    //printf("%d %d\n",x,y);
    if (x<0||y<0)
        return;
    if (x == n && y == n) { 
        //printf("%d\n",cnt);
        if (cnt < min) {
            min = cnt;
        }
        return;
    }
    if (a[x][y] <= 0||b[x][y]==1)
        return;
    int tmp = a[x][y];
    for (int i = 1; i <= tmp; i++) {
        cnt++;
        b[x][y]=1;
        search(x, y + i);
        b[x][y]=0;
        cnt--;
    }
    for (int i = 1; i <= tmp; i++) {
        cnt++;
        b[x][y]=1;
        search(x + i, y);
        b[x][y]=0;
        cnt--;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            a[i][j] = -1;
            b[i][j]=0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    search(1, 1);
    printf("%d", min-1);
    return 0;
}