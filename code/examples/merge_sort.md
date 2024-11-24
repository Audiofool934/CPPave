### Merge Sort (归并排序)

#### 一、什么是归并排序？

1. 将一个数组分成两个子数组，分别进行排序。
2. 将两个有序子数组合并成一个有序数组。

#### 二、归并排序的特点
- **时间复杂度：** \(O(n \log n)\)
- **空间复杂度：** \(O(n)\) （需要额外的辅助空间）
- **稳定性：** 归并排序是一个**稳定**的排序算法。

#### 三、分而治之

1. **分解(Divide)：** 将数组不断划分，直到每个子数组只包含一个元素。
2. **解决(Delegate)：** 对每个子数组进行排序（对于单个元素的数组，天然有序）。
3. **合并(Combine)：** 将两个有序子数组合并为一个有序数组。

#### 四、归并排序的递归实现

归并排序的核心是递归。递归的两个关键点是：

1. **基准条件：** 当子数组的长度为 1 时，不需要再划分和排序。
2. **递归关系：** 将数组划分为两部分，分别进行排序，再合并。

---

#### 五、实现

```c
#include <stdio.h>
#include <stdlib.h>

// 合并两个有序子数组
void merge(int arr[], int left, int mid, int right) {
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

// 打印数组
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, arrSize);

    mergeSort(arr, 0, arrSize - 1);

    printf("Sorted array: \n");
    printArray(arr, arrSize);

    return 0;
}
```

---

#### 六、代码详解

1. **合并函数 `merge`:**
   - 输入：两个有序子数组（通过索引范围 `left` 到 `mid` 和 `mid+1` 到 `right` 表示）
   - 输出：将两个子数组合并为一个有序数组
   - 实现：使用两个临时数组分别存储左、右子数组，逐步比较并合并

2. **递归函数 `mergeSort`:**
   - 基准条件：当 `left >= right` 时，数组不可再分
   - 递归关系：分割数组为两个子数组，分别排序后合并

3. **主函数 `main`:**
   - 定义输入数组，调用 `mergeSort` 实现排序，最后输出排序结果

---

#### 八、时间复杂度分析
1. **分解阶段：** 每次递归将数组分为两半，共需要 \(O(\log n)\) 次分解。
2. **合并阶段：** 每次合并操作需要 \(O(n)\) 的时间。
3. **总时间复杂度：**
   \[
   T(n) = 2T(n/2) + O(n) \quad \implies \quad T(n) = O(n \log n)
   \]

---

#### 九、优缺点
- **优点：**
  1. 时间复杂度稳定为 \(O(n \log n)\)，不受输入数据分布的影响。
  2. 稳定的排序算法，适合排序链表等需要稳定性的场景。
- **缺点：**
  1. 需要额外的 \(O(n)\) 辅助空间，不适合内存受限的场景。