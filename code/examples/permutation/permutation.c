#include <stdio.h>
#include <stdbool.h>
#define MAXN 100

int result[MAXN]; // 用于存储当前排列
bool used[MAXN]; // 标记某个元素是否已被使用

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void printPermutation(int result[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

void generatePermutations(int arr[], int n, int depth) {
    if (depth == n) {
        printPermutation(result, n);
        return;
    }

    for (int i = 0; i < n; i++) {

        if (used[i]) {
            continue;
        }

        // 如果当前元素与前一个元素相同且前一个元素尚未被使用，则跳过（避免重复排列）
        if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1]) {
            continue;
        }

        used[i] = true;
        result[depth] = arr[i];

        generatePermutations(arr, n, depth + 1);

        // 回溯
        used[i] = false;
    }
}

int main() {
    int n;
    int arr[MAXN];

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 对输入数组排序，便于处理重复元素
    sort(arr, n);

    // 初始化used数组
    for (int i = 0; i < n; i++) {
        used[i] = false;
    }

    printf("All unique permutations are:\n");
    generatePermutations(arr, n, 0);

    return 0;
}