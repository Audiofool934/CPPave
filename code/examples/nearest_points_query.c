// YOJ #791 平面最近点查询

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    int x, y;
} Point;

typedef struct KDNode {
    Point p;
    struct KDNode *left, *right;
    int axis; // 0 表示分割轴为 x，1 表示分割轴为 y
} KDNode;

// 全局变量，用于存储点集的指针数组
Point *points;

// 按照指定坐标轴进行排序的比较函数
int cmp_x(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if (p1->x == p2->x) return p1->y - p2->y;
    return p1->x - p2->x;
}

int cmp_y(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if (p1->y == p2->y) return p1->x - p2->x;
    return p1->y - p2->y;
}

// 构建 KD-Tree，参数：点集起始位置、结束位置（包含）、分割轴
KDNode *buildKDTree(Point *pts, int start, int end, int axis) {
    if (start > end) return NULL;
    int n = end - start + 1;
    // 中间点作为根
    int mid = start + n/2;

    // 根据当前轴进行排序
    if (axis == 0) {
        qsort(pts + start, n, sizeof(Point), cmp_x);
    } else {
        qsort(pts + start, n, sizeof(Point), cmp_y);
    }

    KDNode *node = (KDNode *)malloc(sizeof(KDNode));
    node->p = pts[mid];
    node->axis = axis;
    node->left = buildKDTree(pts, start, mid - 1, 1 - axis);
    node->right = buildKDTree(pts, mid + 1, end, 1 - axis);
    return node;
}

// 计算两点距离平方
static inline long long dist_sq(Point a, Point b) {
    long long dx = (long long)(a.x - b.x);
    long long dy = (long long)(a.y - b.y);
    return dx*dx + dy*dy;
}

// 最近邻搜索
void nearestNeighbor(KDNode *root, Point query, Point *best, long long *bestDist) {
    if (root == NULL) return;
    // 当前节点距离
    long long d = dist_sq(root->p, query);
    if (d < *bestDist) {
        *bestDist = d;
        *best = root->p;
    }

    // 根据当前分割轴决定先走哪一边
    int axis = root->axis;
    long long diff;
    if (axis == 0) {
        diff = (long long)(query.x - root->p.x);
    } else {
        diff = (long long)(query.y - root->p.y);
    }

    KDNode *first = (diff <= 0) ? root->left : root->right;
    KDNode *second = (diff <= 0) ? root->right : root->left;

    // 先访问首选子树
    nearestNeighbor(first, query, best, bestDist);

    // 检查另一侧子树是否有必要访问
    // 如果 diff^2 < bestDist，则另一侧子树有可能存在更近的点
    if (diff * diff < *bestDist) {
        nearestNeighbor(second, query, best, bestDist);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    points = (Point *)malloc(sizeof(Point)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // 构建 KD-Tree
    KDNode *root = buildKDTree(points, 0, N-1, 0);

    int Q;
    scanf("%d", &Q);
    while (Q--) {
        Point q;
        scanf("%d %d", &q.x, &q.y);
        Point best;
        long long bestDist = 0x7fffffffffffffffLL; // 设为很大的数
        nearestNeighbor(root, q, &best, &bestDist);
        printf("%lld\n", bestDist);
    }

    // 内存释放（此处略，根据需要添加释放树的函数）
    free(points);
    // 请根据需要增加 KD 树的释放代码
    return 0;
}