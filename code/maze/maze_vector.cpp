#include <iostream>
#include <vector>

using namespace std;

void go(int x, int y, const int n, const int m, vector<vector<int>>& maze, vector<vector<int>>& fp, bool& yes) {
    if (yes == true || x < 0 || y < 0 || x > n-1 || y > m-1 || maze[x][y] == 0 || fp[x][y] == 1) return;
    
    if (x == n-1 && y == m-1) {
        yes = true;
        return;
    }

    fp[x][y] = 1;

    go(x+1, y, n, m, maze, fp, yes);
    go(x, y+1, n, m, maze, fp, yes);
    go(x-1, y, n, m, maze, fp, yes);
    go(x, y-1, n, m, maze, fp, yes);

    fp[x][y] = 0;

}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<int>> fp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    bool yes = false;

    go(0, 0, n, m, maze, fp, yes);

    if (yes) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}