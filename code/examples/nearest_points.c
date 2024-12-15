#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

// 点
typedef struct Point {
    double x, y;
} Point;

// 按 x 坐标排序
int compareX(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->x > p2->x) - (p1->x < p2->x);
}

// 按 y 坐标排序
int compareY(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;
    return (p1->y > p2->y) - (p1->y < p2->y);
}

// 两点间欧式距离
double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// 计算最近点对（暴力）
double bruteForce(Point P[], int n) {
    double minDist = DBL_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double d = dist(P[i], P[j]);
            if (d < minDist) {
                minDist = d;
            }
        }
    }
    return minDist;
}

// 计算跨越分割线的最近点对距离
double stripNearest(Point strip[], int size, double d) {
    double min = d;

    // 按 y 坐标排序
    qsort(strip, size, sizeof(Point), compareY);

    for (int i = 0; i < size; ++i) {
        // 只检查 y 坐标差值小于当前最小距离的点
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min; ++j) {
            double distTmp = dist(strip[i], strip[j]);
            if (distTmp < min) {
                min = distTmp;
            }
        }
    }

    return min;
}

// 分治法计算最近点对
double nearestUtil(Point P[], int n) {
    // 当点数小于等于 3 时，使用暴力法
    if (n <= 3) {
        return bruteForce(P, n);
    }

    // 取中点
    int mid = n / 2;
    Point midPoint = P[mid];

    // 分别计算左右两部分的最近点对距离
    double dl = nearestUtil(P, mid);
    double dr = nearestUtil(P + mid, n - mid);

    // 当前的最近距离
    double d = fmin(dl, dr);

    // 构造跨越分割线的点集
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(P[i].x - midPoint.x) < d) {
            strip[j] = P[i];
            j++;
        }
    }

    // 返回三者中的最小值
    return fmin(d, stripNearest(strip, j, d));
}

// 主函数：计算最近点对距离
double nearest(Point P[], int n) {
    // 按 x 坐标排序
    qsort(P, n, sizeof(Point), compareX);
    return nearestUtil(P, n);
}

int main() {
    int n;
    scanf("%d", &n);
    Point P[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &P[i].x, &P[i].y);
    }
    int res = nearest(P, n);
    printf("%d", res*res);
    return 0;
}