#include <stdio.h>
#include <math.h>

#define MAX_SAMPLES 10000

typedef struct {
    int x;
    int y;
    int category;
    double distance;
} Sample;

double calculate_distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void bubble_sort(Sample samples[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (samples[j].distance > samples[j + 1].distance) {
                Sample temp = samples[j];
                samples[j] = samples[j + 1];
                samples[j + 1] = temp;
            }
        }
    }
}

int main() {
    int m, k;
    scanf("%d %d", &m, &k);

    Sample samples[MAX_SAMPLES];
    int total_samples = 0;

    for (int i = 1; i <= m; i++) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            samples[total_samples].x = x;
            samples[total_samples].y = y;
            samples[total_samples].category = i;
            samples[total_samples].distance = 0;
            total_samples++;
        }
    }

    int x0, y0;
    scanf("%d %d", &x0, &y0);

    // 计算每个样本点与待分类点的距离
    for (int i = 0; i < total_samples; i++) {
        samples[i].distance = calculate_distance(samples[i].x, samples[i].y, x0, y0);
    }

    // 使用冒泡排序按距离排序
    bubble_sort(samples, total_samples);

    // 统计前k个样本的类别
    int category_count[101] = {0};
    for (int i = 0; i < k; i++) {
        category_count[samples[i].category]++;
    } // 本质上是一个“字典”，索引恰好是类别号，值是该类别号出现的次数

    // 找到出现次数最多的类别
    int result_category = 0;
    int max_count = 0;
    for (int i = 1; i <= m; i++) {
        if (category_count[i] > max_count) {
            max_count = category_count[i];
            result_category = i;
        }
    }

    printf("%d\n", result_category);

    return 0;
}
