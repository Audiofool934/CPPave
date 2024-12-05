#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<vector<int>>& fp, int row, int col) {
    // 有问题
    return true;
}

void pos(int n, int col, vector<vector<int>>& fp, int& mtd) {
    if (col == n) {
        mtd++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check(fp, i, col)) {
            fp[i][col] = 1;
            pos(n, col + 1, fp, mtd);
            fp[i][col] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> fp(n, vector<int>(n, 0));
    int mtd = 0;
    pos(n, 0, fp, mtd);
    cout << mtd << endl;
    return 0;
}