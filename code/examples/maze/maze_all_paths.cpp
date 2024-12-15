#include <iostream>
#include <vector>

using namespace std;

void go(int x, int y, const int n, const int m, 
        vector<vector<int>>& maze, 
        vector<vector<int>>& fp, 
        vector<vector<int>>& path,
        vector<vector<vector<int>>>& paths) {

    if (x < 0 || y < 0 || x > n-1 || y > m-1 || maze[x][y] == 0 || fp[x][y] == 1)
        return;
    
    if (x == n-1 && y == m-1) {
        path.push_back({x, y});
        paths.push_back(path);
        path.pop_back();
        return;
    }

    fp[x][y] = 1;
    path.push_back({x, y});

    go(x+1, y, n, m, maze, fp, path, paths);
    go(x, y+1, n, m, maze, fp, path, paths);
    go(x-1, y, n, m, maze, fp, path, paths);
    go(x, y-1, n, m, maze, fp, path, paths);

    fp[x][y] = 0;
    path.pop_back();
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<int>> fp(n, vector<int>(m, 0));

    vector<vector<int>> path;
    vector<vector<vector<int>>> paths;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    go(0, 0, n, m, maze, fp, path, paths);

    for (auto p : paths) {
        for (auto c : p) {
            cout << "(" << c[0] << ", " << c[1] << ") ";
        }
        cout << endl;
    }
    
    return 0;
}