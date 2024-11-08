#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

const int ARRSIZE = 10100; //定义数组大小
const int DISPCNT = 3140; // 显示位数，减少以便于观看

int main() {
    char x[ARRSIZE], z[ARRSIZE]; // 数组x和z
    int a = 1, b = 3, c, d, Run = 1, Cnt = 0;

    // 初始化数组
    memset(x, 0, ARRSIZE);
    memset(z, 0, ARRSIZE);
    x[1] = 2;
    z[1] = 2;

    clock_t t0 = clock();

    while (Run && (++Cnt < 200000000)) {
        // z *= a;
        d = 0;
        for (int i = ARRSIZE - 1; i > 0; i--) {
            c = z[i] * a + d;
            z[i] = c % 10;
            d = c / 10;
        }
        // z /= b;
        d = 0;
        for (int i = 0; i < ARRSIZE; i++) {
            c = z[i] + d * 10;
            z[i] = c / b;
            d = c % b;
        }
        // x += z;
        Run = 0;
        for (int i = ARRSIZE - 1; i > 0; i--) {
            c = x[i] + z[i];
            x[i] = c % 10;
            x[i - 1] += c / 10;
            Run |= z[i];
        }
        a++;
        b += 2;
    }

    clock_t t1 = clock();
    double elapsed_secs = double(t1 - t0) / CLOCKS_PER_SEC;

    cout << "计算次数：" << Cnt << " 次" << endl;
    cout << "计算时间：" << elapsed_secs << " 秒" << endl;
    cout << "Pi= " << (int)x[0] << (int)x[1] << ".";
    for (int i = 0; i < DISPCNT; i++) {
        if (i && ((i % 10) == 0))
            cout << " ";
        cout << (int)x[i + 2];
    }
    cout << endl;

    return 0;
}
