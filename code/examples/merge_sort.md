## Merge Sort (归并排序)

1. 将一个数组分成两个子数组，分别进行排序。
2. 将两个有序子数组合并成一个有序数组。

### divide & conquer

1. **分解(Divide)：** 将数组不断划分（二分），直到每个子数组只包含一个元素
2. **解决(Delegate)：** 对每个子数组进行排序（对于单个元素的数组，天然有序）
3. **合并(Combine)：** 将两个有序子数组合并为一个有序数组。

### 递归实现

```c
#include <stdio.h>
#include <stdlib.h>

// 合并两个有序子数组
void merge(int arr[], int left, int mid, int right);

// 递归实现归并排序
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 分解阶段
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并阶段
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    // “双指针”法合并两个有序数组，“归并”

    int n1 = mid - left + 1; // 左子数组的大小
    int n2 = right - mid;    // 右子数组的大小

    // 创建临时数组
    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));

    // 将数据复制到临时数组
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    // 合并临时数组到原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // 复制剩余元素
    while (i < n1) {
        arr[k] = leftArr[i];
        i++; k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++; k++;
    }

    // 释放临时数组
    free(leftArr);
    free(rightArr);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, arrSize - 1);
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    return 0;
}
```

### 关于归并排序

- 时间复杂度稳定为 \(O(n \log n)\)，**不受输入数据分布的影响**
- 是稳定的排序算法（排序前后相等元素的相对位置不变），适用于链表排序
- 需要额外的 \(O(n)\) 辅助空间

### sources and readings

- [Hello 算法 - 归并排序](https://www.hello-algo.com/chapter_sorting/merge_sort/)
- [Algorithms](https://jeffe.cs.illinois.edu/teaching/algorithms/)
