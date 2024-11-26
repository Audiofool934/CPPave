## Quick Sort (快速排序)

1. 从数组中选择一个基准值（pivot）
2. 通过交换元素将数组划分为两部分：
   - 左部分的元素小于（等于）基准值
   - 右部分的元素大于基准值
3. 分别对左右两部分递归地进行快速排序

### 三、分而治之

1. **分解(Divide)：** 选取基准值，将数组分成两部分
2. **解决(Delegate)：** 分别对左右两部分递归排序
3. **合并(Combine)：** 不需要额外的合并步骤——数组已经在递归中排序结束

### 递归实现

```c
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
    for (int i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);
    return 0;
}
```

- **`partition` 函数：**
   - 核心是找到基准值的正确位置，并将数组分为两部分。
   - 使用**双指针法**，一个指针 \(i\) 指向小于等于基准值的区域，另一个指针 \(j\) 遍历数组
   - 每当发现一个小于等于基准值的元素，就交换它与 \(i+1\) 的位置，扩大小于等于基准值的区域。

- **`quickSort` 函数：**
   - 基准条件：当子数组的长度为 0 或 1 时，不再递归
   - 递归调用：对分区后的左右部分分别进行快速排序

### 关于快速排序

- 时间复杂度：
  - **最好情况：** 每次分区都能将数组均分为两部分，递归深度为 \(\log n\)，每层操作 \(O(n)\)，总复杂度 \(O(n \log n)\)
  - **最坏情况：** 每次分区基准值都在数组的最左或最右，递归深度为 \(n\)，总复杂度 \(O(n^2)\)——**这时快速排序退化为冒泡排序**
  - **平均情况：** 分区效率接近于最好情况，总复杂度为 \(O(n \log n)\)。

- 原地排序，不需要额外的辅助数组
- 不稳定排序，可能改变相同值元素的相对位置

### sources and readings

- [Hello 算法 - 快速排序](https://www.hello-algo.com/chapter_sorting/quick_sort/)
- [Algorithms](https://jeffe.cs.illinois.edu/teaching/algorithms/)
