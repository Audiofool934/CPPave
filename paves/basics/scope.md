## 变量作用域与 `static` 关键字

在 C 语言中，**变量的作用域**指的是变量在程序中的可见范围，主要分为以下几类：
1. **块作用域**（Block Scope）
2. **文件作用域**（File Scope）
3. **函数作用域**（Function Scope）
4. **全局作用域**（Global Scope）

同时，`static` 关键字在不同作用域中具有独特的意义，主要用于控制**变量的存储类型**和**作用域**。

---

### 一、变量的作用域

#### 1.1 块作用域（Block Scope）
- 块作用域是通过 `{}` 定义的，变量在其定义的块内可见。
- 离开块后，变量不再存在。

**示例：块作用域**
```c
#include <stdio.h>

int main() {
    int x = 10; // 块作用域变量 x
    {
        int y = 20; // y 的作用域仅限于这个块
        printf("x = %d, y = %d\n", x, y);
    }
    // printf("%d\n", y); // 错误：y 超出了作用域
    return 0;
}
```

**特点：**
- 块内声明的变量仅在块内有效。
- 通常用于函数内的局部变量。

---

#### 1.2 文件作用域（File Scope）

- 文件作用域指变量或函数的作用范围是当前文件。
- 定义在所有函数之外的变量具有文件作用域。
- 默认情况下，全局变量具有文件作用域，并可以被其他文件访问（除非用 `static` 限制为内部链接）。

**示例：文件作用域**
```c
#include <stdio.h>

int globalVar = 100; // 文件作用域，全局变量

void printGlobal() {
    printf("globalVar = %d\n", globalVar);
}

int main() {
    printGlobal();
    globalVar = 200;
    printGlobal();
    return 0;
}
```

---

#### 1.3 静态变量与作用域

`static` 关键字影响变量的**作用域**和**存储持续时间**。根据变量声明的位置，`static` 的含义不同。

---

### 二、`static` 的含义与用法

#### 2.1 局部变量的 `static`

局部变量默认存储在栈上，生命周期随函数调用的结束而结束。但 `static` 修饰的局部变量存储在全局静态区，其生命周期贯穿整个程序运行。

**特点：**
- 作用域：限定在定义它的函数内（块作用域）。
- 生命周期：整个程序运行期间。

**示例：局部静态变量**
```c
#include <stdio.h>

void counter() {
    static int count = 0; // 静态局部变量
    count++;
    printf("Count = %d\n", count);
}

int main() {
    counter(); // Count = 1
    counter(); // Count = 2
    counter(); // Count = 3
    return 0;
}
```

**注意：**
- 静态局部变量在程序启动时初始化，仅初始化一次。
- 每次调用函数时变量的值不会被重置，而是保留上次调用的值。

---

#### 2.2 全局变量的 `static`
全局变量默认具有**外部链接**（可以被其他文件访问），使用 `static` 可以限制其为**内部链接**（仅在当前文件可见）。

**特点：**
- 作用域：当前文件。
- 生命周期：整个程序运行期间。

**示例：文件作用域的静态变量**
`file1.c`
```c
#include <stdio.h>

static int staticGlobal = 10; // 静态全局变量，仅在当前文件可见

void printStaticGlobal() {
    printf("staticGlobal = %d\n", staticGlobal);
}
```

`file2.c`
```c
#include <stdio.h>

// extern int staticGlobal; // 错误：staticGlobal 在 file1.c 中不可见

int main() {
    // printf("%d\n", staticGlobal); // 错误：无法访问 file1.c 的静态全局变量
    return 0;
}
```

**应用场景：**
- 在模块开发中，`static` 可用来隐藏模块的内部实现，防止外部文件误用。

---

#### 2.3 函数的 `static`
`static` 修饰函数时，函数的作用域限定在当前文件内。

**示例：静态函数**
`file1.c`
```c
#include <stdio.h>

static void hiddenFunction() { // 静态函数，仅当前文件可见
    printf("This is a static function.\n");
}

void callHiddenFunction() {
    hiddenFunction(); // 正常调用
}
```

`file2.c`
```c
#include <stdio.h>

// extern void hiddenFunction(); // 错误：无法访问 file1.c 的静态函数

int main() {
    // hiddenFunction(); // 错误：函数不可见
    return 0;
}
```

**应用场景：**
- 使用静态函数隐藏模块的实现细节，提供更安全的接口。

---

### 三、`static` 在递归与参数传递中的应用

#### 3.1 静态变量与递归
在递归函数中，静态变量可以保存状态，帮助优化递归算法或记录计算结果。

**示例：斐波那契数列**
```c
#include <stdio.h>

int fibonacci(int n) {
    static int memo[100] = {0}; // 静态记忆数组
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n]; // 查表
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2); // 递归
    return memo[n];
}

int main() {
    printf("Fibonacci(10) = %d\n", fibonacci(10));
    return 0;
}
```

---

#### 3.2 静态变量与回溯
静态变量可以在回溯过程中记录路径状态，避免重复初始化。

**示例：路径计数**
```c
#include <stdio.h>

void countPaths(int x, int y) {
    static int pathCount = 0; // 静态变量记录路径数
    if (x == 0 && y == 0) {
        pathCount++;
        return;
    }
    if (x > 0) countPaths(x - 1, y);
    if (y > 0) countPaths(x, y - 1);
}

int main() {
    countPaths(2, 2);
    countPaths(2, 2); // 第二次调用，pathCount 累加
    printf("Total Paths = %d\n", pathCount); // 输出路径总数
    return 0;
}
```

---

### 四、总结

#### 4.1 不同作用域和 `static` 的适用场景

| **类型**               | **作用域**                  | **生命周期**               | **使用场景**                                      |
|------------------------|-----------------------------|----------------------------|--------------------------------------------------|
| 普通局部变量           | 块作用域                   | 函数调用期间               | 普通变量，只在函数调用期间有效。                 |
| 静态局部变量（`static`）| 块作用域                   | 程序运行期间               | 记录状态（如递归计数、回溯路径）。               |
| 普通全局变量           | 文件作用域                 | 程序运行期间               | 跨模块共享数据（不推荐滥用）。                   |
| 静态全局变量（`static`）| 文件作用域                 | 程序运行期间               | 模块内部共享数据，隐藏实现细节。                 |
| 静态函数（`static`）    | 文件作用域                 | 程序运行期间               | 限定函数作用域，防止外部文件访问。               |

`static` 的灵活使用可以提高程序的模块化程度，优化递归和回溯，同时限制变量作用范围，避免潜在错误。在实际设计中，应结合需求合理使用 `static`，避免滥用全局变量。