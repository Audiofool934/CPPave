#include <stdio.h>

// 分区函数：将数组分为两部分，返回基准值的索引
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 选择最后一个元素作为基准值
    int i = low - 1;       // i 指向小于等于 pivot 的区域

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // 如果当前元素小于等于 pivot
            i++;
            // 交换 arr[i] 和 arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 交换 pivot 和 arr[i+1]，将 pivot 放到正确的位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // 返回基准值的位置
}

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 分区操作，获得基准值的索引
        int pi = partition(arr, low, high);

        // 对基准值左边的部分排序
        quickSort(arr, low, pi - 1);
        // 对基准值右边的部分排序
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}