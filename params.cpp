#include <iostream>

using namespace std;

template <size_t row, size_t col>
void setArrayToIdentity(int (&a)[row][col]) {
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            a[i][j] = (i == j) ? 1 : 0;
        }
    }
}

void setArrayToIdentity2(int* a, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            a[i * col + j] = (i == j) ? 1 : 0;
        }
    }
}

int main() {
    int a[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // for (int i = 0; i < 3; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // setArrayToIdentity(a);
    setArrayToIdentity2(a[0], 3, 4);

    cout << "After setting to identity matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    int b[3] = {1, 2, 3};
    setArrayToIdentity2(b, 3, 1);
    // 退化：&b[0], b 都是一样的
    // &b 表示指向数组的指针，而不是指向数组首元素的指针
    for (int i = 0; i < 3; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}