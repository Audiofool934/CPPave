## Function

### 一、函数的基本概念

函数是**将一段特定功能的代码封装成一个模块**，通过函数名调用实现代码复用，提高程序的可维护性和可读性。

#### 1.1 函数的定义

函数的组成部分：
- **返回值类型**：函数返回值的数据类型。如果没有返回值，使用 `void`。
- **函数名**：函数的标识符，用于调用。
- **参数列表**：函数需要的输入数据，可以为空。
- **函数体**：包含具体执行代码的块。

语法：

```c
返回值类型 函数名(参数列表) {
    函数体;
}
```

示例：

```c
int add(int a, int b) {
    return a + b;
}
```

#### 1.2 函数的调用

函数名后加小括号即可调用，括号中传入实际参数：

```c
int sum = add(3, 5);  // 调用函数并接收返回值
```

---

### 二、函数的基本操作

#### 2.1 函数的声明与定义

- **函数声明**：提前告知编译器函数的存在，一般放在头文件或文件顶部。声明的语句以分号结束。
- **函数定义**：包含具体实现。

示例：
```c
// 声明
int add(int a, int b);

int main() {
    int sum = add(3, 5);  // 调用
    printf("Sum = %d\n", sum);
    return 0;
}

// 定义
int add(int a, int b) {
    return a + b;
}
```

#### 2.2 函数的返回值
- 函数可以通过 `return` 返回值。
- 如果函数没有返回值，返回值类型用 `void`。

示例：
```c
int square(int x) {
    return x * x;  // 返回 x 的平方
}

void greet() {
    printf("Hello, World!\n");
}
```

## parameters pass 参数传递

在C语言中，**函数参数传递**有两种主要方式：
- 按值传递（默认）
- 使用指针实现间接传递（常用于数组和修改外部变量）

---

### 一、按值传递的基本概念

#### 1.1 按值传递

当一个基本变量作为参数传递给函数时，传递的是该变量的值，**函数内部修改不会影响外部变量**。

示例：
```c
void increment(int x) {
    x++;
}

int main() {
    int a = 5;
    increment(a);
    printf("a = %d\n", a); // 输出：a = 5（a未被修改）
    return 0;
}
```

#### 1.2 指针传递

通过传递变量地址，可以在函数内修改变量的值。
```c
void increment(int *x) {
    (*x)++;
}

int main() {
    int a = 5;
    increment(&a);
    printf("a = %d\n", a); // 输出：a = 6（a被修改）
    return 0;
}
```

---

### 二、数组作为函数参数的传递

在C语言中，**数组传递给函数时实际上是通过指针传递的**。函数接收的是数组的首地址，而不是整个数组的副本。

#### 2.1 数组作为参数的定义和使用

示例：
```c
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    printArray(nums, size); // 传递数组和大小
    return 0;
}
```

**解析：**
- `arr[]` 是函数参数，表示接收一个整型数组。
- `nums` 作为实参，实际传递的是数组 `nums` 的首地址。

#### 2.2 数组传递的特点
1. **首地址传递**：函数内部操作直接作用于原数组。
2. **大小未知**：数组传递时不会携带大小信息，需额外传递 `size` 参数。

---

### 三、数组传递的实现方式

#### 3.1 使用数组语法传递
```c
void modifyArray(int arr[], int size) {
    arr[0] = 99;  // 修改数组的第一个元素
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    modifyArray(nums, 5);
    printf("nums[0] = %d\n", nums[0]); // 输出：nums[0] = 99
    return 0;
}
```

#### 3.2 使用指针语法传递

```c
void modifyArray(int *arr, int size) {
    *(arr + 0) = 99;  // 修改数组的第一个元素
}

int main() {
    int nums[] = {1, 2, 3, 4, 5};
    modifyArray(nums, 5);
    printf("nums[0] = %d\n", nums[0]); // 输出：nums[0] = 99
    return 0;
}
```

**等效性：**
- `arr[i]` 等价于 `*(arr + i)`。
- 无论是 `arr[]` 还是 `int *arr`，本质都是传递数组首地址。

---

### 四、多维数组的参数传递

多维数组传递时，需明确每一维的大小（除第一维）。

#### 4.1 二维数组的传递

```c
void print2DArray(int arr[][3], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int nums[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    print2DArray(nums, 2); // 传递二维数组
    return 0;
}
```

**注意：**
- 必须指定第二维大小，例如 `[3]`。
- 函数内部通过 `arr[i][j]` 访问元素。

#### 4.2 动态二维数组的传递

动态分配的二维数组可通过指针传递：

```c
#include <stdio.h>
#include <stdlib.h>

void printDynamic2DArray(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 2, cols = 3;
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i * cols + j + 1;
        }
    }

    printDynamic2DArray(arr, rows, cols);

    // 释放内存
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
```

---

### 五、使用 `const` 修饰数组参数

如果函数只需要读取数组而不修改，可以使用 `const` 修饰，保证数组不可变：
```c
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
```

**好处：**
1. 提高代码的安全性，避免误修改。
2. 对调用者明确函数不会更改传入的数组。

---

### 六、数组作为返回值

C语言函数**不能直接返回数组**，但可以通过以下方式实现：

#### 6.1 使用指针返回
```c
int* generateArray(int size) {
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

int main() {
    int size = 5;
    int *arr = generateArray(size);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    free(arr); // 释放内存
    return 0;
}
```

#### 6.2 使用静态数组

静态数组的生命周期贯穿整个程序，可以返回其指针：
```c
int* getStaticArray() {
    static int arr[5] = {1, 2, 3, 4, 5};
    return arr;
}

int main() {
    int *arr = getStaticArray();
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

**注意：**
- 使用静态数组时要小心数据覆盖问题。
- 动态分配的数组需要手动释放内存。
