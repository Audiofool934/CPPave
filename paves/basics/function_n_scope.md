## Function

关于C语言中函数的基本内容，可参考这里，下面主要讨论**函数参数传递**和**变量作用域**

### 1. 函数参数传递

讨论：“形参”与“实参”

>**Arguments versus Parameters**
>Although the terms argument and parameter often have been used interchangeably, the C99 documentation has decided to use the <u>term argument for actual argument</u> or actual parameter and the <u>term parameter for formal parameter</u> or formal argument. With this convention, we can say that parameters are variables and that arguments are values provided by a function call and assigned to the corresponding parameters.
-- <cite>C Primer Plus, Fifth Edition, By Stephen Prata</cite>

**形参（parameter，形式参数）**：在函数定义时，用来表示传入的值的变量。形参本身没有具体的值，是一个占位符
**实参（argument，实际参数）**：在函数调用时，传递给函数的实际值。这个值会被赋给对应的形参

在C语言中，**函数参数传递**有两种方式：
- 按值传递（pass by value）：形参接收的是实参的**副本**。
- 通过指针传递（pass by pointers）：可改变实参值

#### 1.1. 按值传递的特点

- **传递的是值的副本**：函数内部操作不会影响调用函数中实参的值。
- **内存独立**：形参在函数调用时分配内存，函数执行完后形参释放。

**示例：**
```c
#include <stdio.h>

void modifyValue(int x) {
    x = 42; // 修改的是形参的副本
}

int main() {
    int a = 10;
    modifyValue(a); // 传递 a 的值
    printf("a = %d\n", a); // 输出仍然是 a = 10
    return 0;
}
```

#### 1.2. 通过指针间接修改实参

传递变量的地址（指针），函数通过解引用修改地址指向的值。

**示例：**
```c
#include <stdio.h>

void modifyValue(int *x) {
    *x = 42; // 修改的是指针指向的实参
}

int main() {
    int a = 10;
    modifyValue(&a); // 传递 a 的地址
    printf("a = %d\n", a); // 输出 a = 42
    return 0;
}
```

#### 1.3. 数组的特殊情况

数组名在函数调用中会**退化为指针**，传递的是数组首元素的地址，而不是整个数组：

```c
#include <stdio.h>

void modifyArray(int arr[], int size) {
    arr[0] = 42; // 修改的是数组首元素
}

int main() {
    int a[] = {1, 2, 3};
    modifyArray(a, 3);
    printf("a[0] = %d\n", a[0]); // 输出 a[0] = 42
    return 0;
}
```

#### 1.4. 动态分配二维数组

动态分配的二维数组可以通过指针传递：

```c
#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);

int main() {
    int rows = 2, cols = 3;
    int **matrix = (int **)malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = 1;
        }
    }

    printMatrix(matrix, rows, cols);
    fillMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fillMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * cols + j;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
```
output:
```
1 1 1 
1 1 1 

0 1 2 
3 4 5
```

---

### 2. （变量）作用域

关于作用域与生命周期的概念，可以参考[这里](https://blog.csdn.net/cnds123/article/details/132234436)

下面主要对**局部变量**、**全局变量**和**静态局部变量**，以及**块作用域**进行回顾与讨论

#### 2.1. **局部变量（Local Variables）**
- **定义**：在函数或代码块内部定义的变量
- **作用域**：**仅在函数或代码块内部有效**
- **存储**：通常存储在**栈（stack）**中，函数执行完后变量**自动释放**
- **特点**：不同函数中的局部变量互不干扰

**示例：**
```c
#include <stdio.h>

void func() {
    int x = 10; // 局部变量
    printf("x = %d\n", x);
}

int main() {
    func();
    // printf("%d\n", x); // 错误，x 不在 main 函数的作用域中
    return 0;
}
```

#### 2.2. **全局变量（Global Variables）**
- **定义**：在所有函数外部定义的变量
- **作用域**：从变量定义位置开始到文件结尾，整个程序都可访问
- **存储**：存储在全局/静态内存区
- **特点**：
  - 使用全局变量时需**谨慎**，容易引发错误
  - **建议使用静态变量替代全局变量，限制其作用域**

**示例：**
```c
#include <stdio.h>

int x = 10; // 全局变量

void func() {
    printf("x = %d\n", x); // 访问全局变量
}

int main() {
    func();
    printf("x = %d\n", x); // 访问全局变量
    return 0;
}
```

#### 2.3. **静态局部变量（Static Local Variables）**

关于`static`关键字，可参考[这里](https://www.runoob.com/w3cnote/c-static-effect.html)

- **定义**：使用 `static` 关键字修饰的局部变量
- **作用域**：仅在定义它的函数或代码块中有效
- **存储**：存储在全局/静态内存区，**生命周期贯穿程序始终**
- **特点**：**即使函数执行完，变量的值也会被保留**

**示例：**
```c
#include <stdio.h>

void func() {
    static int x = 0; // 静态局部变量
    x++;
    printf("x = %d\n", x);
}

int main() {
    func(); // 输出 x = 1
    func(); // 输出 x = 2
    func(); // 输出 x = 3
    return 0;
}
```

#### 2.4. **块作用域（Block Scope）**
- **定义**：在 `{}` 花括号中定义的变量。
- **作用域**：仅在花括号内部有效。
- **特点**：块作用域内的变量在块结束后销毁。

**示例：**
```c
#include <stdio.h>

int main() {
    {
        int x = 10; // 块作用域
        printf("x = %d\n", x);
    }
   4 // printf("%d\n", x); // 错误，x 不在作用域中
    return 0;
}
```
