# Sorting

https://www.hello-algo.com/chapter_sorting/

## code snippet

```c
/* 插入排序 */
void insertionSort(int nums[], int size) {
    // 外循环：已排序区间为 [0, i-1]
    for (int i = 1; i < size; i++) {
        int base = nums[i], j = i - 1;
        // 内循环：将 base 插入到已排序区间 [0, i-1] 中的正确位置
        while (j >= 0 && nums[j] > base) {
            // 将 nums[j] 向右移动一位
            nums[j + 1] = nums[j];
            j--;
        }
        // 将 base 赋值到正确位置
        nums[j + 1] = base;
    }
}
```

```c
/* 选择排序 */
void selectionSort(int nums[], int n) {
    // 外循环：未排序区间为 [i, n-1]
    for (int i = 0; i < n - 1; i++) {
        // 内循环：找到未排序区间内的最小元素
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[k])
                k = j; // 记录最小元素的索引
        }
        // 将该最小元素与未排序区间的首个元素交换
        int temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
}
```

```c
void bubbleSort(int nums[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // 外循环：未排序区间为 [0, i]
        for (int j = 0; j < size - i - 1; j++) {
            // 内循环：将未排序区间 [0, i] 中的最大元素交换至该区间的最右端
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}
```

## Introduction

排序算法

## ☆ Bubble Sort

冒泡排序

## Selection Sort

## Insertion Sort

---

## ☆ Quick Sort

## Merge Sort*

## Heap Sort*

## Bucket Sort*

## Radix Sort*