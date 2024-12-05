#include <stdio.h>

// 交换两个元素的值
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 将数组分区并返回分区点的索引
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 选择最后一个元素作为基准
    int i = low - 1;  // 初始化分区点的索引

    for (int j = low; j < high; j++) {
        // 如果当前元素小于或等于基准，将其交换到分区点
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // 将基准元素交换到正确的位置
    swap(&arr[i + 1], &arr[high]);

    return i + 1;  // 返回分区点的索引
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 找到分区点
        int pi = partition(arr, low, high);

        // 递归地对分区的两侧进行排序
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 打印数组元素
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    // 调用快速排序函数
    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
