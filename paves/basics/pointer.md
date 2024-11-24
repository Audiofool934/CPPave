## Pointer

### a "quirk": int* a vs. int *a

answers from [stackoverflow](https://stackoverflow.com/questions/3770187/difference-between-int-i-and-int-i)

> As far as `C` goes they both do the same thing. It is a matter of preference. `int* i` shows clearly that it is an int pointer type. `int *i`shows the fact that the asterisk only affects a single variable. So `int *i, j` and `int* i, j` would both create `i` as an int pointer and `j` as an int.

---

>They are the same. The two different styles come from a quirk in C syntax.
>Some people prefer `int* i`; because `int*` is the type of i.
>Others prefer `int *i`; because the parser attaches the star to the variable, and not the type. This only becomes meaningful when you try to define two variables on the line. Regardless of how you write it:
>```c
>int* i,j;
>int*i,j;
>int *i,j;
>```
>in each of those, `i` is a pointer to an int, while `j` is just an int. The last syntax >makes that clearer, although, even better would be:
>```c
>int j, *i;
>```
>or best yet:
>```c
>int *i;
>int j;
>```

---

>It's an accident of C syntax that you can write either int `*i` or `int* i` or even `int    >*      i`. All of them are parsed as `int (*i)`; IOW, the `*` is bound to the declarator, >not the type specifier. This means that in declarations like
>```c
>int* i, j;
>```
>only `i` is declared as a pointer; `j` is declared as a regular int. If you want to declare >both of them as pointers, you would have to write
>```c
>int *i, *j;
>```
>Most C programmers use `T *p` as opposed to `T* p`, since
>1. declarations in <span style="color"red">C are expression-centric</span>, not >object-centric, and
>2. it more closely reflects declaration syntax.
>
>As an example of what I mean by expression-centric, suppose you have an array of pointers >to int and you want to get the integer value at element `i`. The expression that >corresponds to that value is `*a[i]`, and the type of the expression is `int`; thus, the >declaration of the array is
>```
>int *a[N];
>```
>When you see the phrase "declaration mimics use" with regard to C programming, this is what >is meant.


### 一、什么是指针

指针用于存储**变量的地址**。指针本质上是一个变量，其值是另一个变量的内存地址。

#### 1.1 指针的基本概念

- **地址**：内存中**每个字节**都有一个唯一的编号（地址）。
- **指针**：存储地址的变量。
  
#### 1.2 指针的定义与语法

```c
数据类型 *指针变量名;
```

- `*` 表示该变量是一个指针。
- **数据类型**：指针指向的变量的数据类型。

示例：

```c
int a = 10;      // 定义一个整数变量
int *p = &a;     // 定义一个指针变量 p，并使其存储变量 a 的地址
```

| 操作符       | 含义                  | 示例        |
|--------------|-----------------------|-------------|
| `&`         | 取地址符             | `&a` 获取变量 `a` 的地址 |
| `*`         | 解引用（访问地址内容） | `*p` 获取指针 `p` 指向地址中的值 |

---

### 二、指针的基本操作

#### 2.1 获取变量地址

使用 `&` 运算符：

```c
int a = 20;
int *p = &a; // p 存储 a 的地址
```

#### 2.2 通过指针访问变量值

使用 `*` 运算符：

```c
printf("通过指针访问 a 的值: %d\n", *p);
```

#### 2.3 修改变量值
通过指针可以间接修改变量的值：

```c
*p = 30; // 修改 a 的值为 30
```

---

### 三、常见的指针类型

#### 3.1 空指针（NULL指针）
- 空指针是一个不指向任何有效内存的指针。
- 定义空指针：
  ```c
  int *p = NULL;
  ```
- 检查指针是否为空：
  ```c
  if (p == NULL) { //也可以简化为 if (!p)
      printf("指针为空\n");
  }
  ```

#### 3.2 野指针
- 野指针是一个未初始化或已经被释放但未置为 `NULL` 的指针。
- 避免野指针：
  - 初始化指针时赋值为 `NULL`。
  - 释放指针后立即将其置为 `NULL`。

#### 3.3 通用指针（void *）
- 通用指针可以指向任意类型的数据。
- 使用通用指针时需要强制类型转换：
  ```c
  void *ptr;
  int a = 10;
  ptr = &a; // void* 指向 int 类型的变量
  printf("通过通用指针访问值: %d\n", *(int *)ptr); // 强制类型转换：先转为 int*，再解引用
  ```

---

### 四、指针与数组

#### 4.1 数组与指针的关系
数组名本身就是指向第一个元素的指针。

```c
int arr[3] = {1, 2, 3};
int *p = arr;  // p 指向数组的第一个元素
```

| 表达式      | 含义                | 示例值   |
|-------------|---------------------|----------|
| `arr`       | 数组第一个元素的地址 | `&arr[0]` |
| `*arr`      | 数组第一个元素的值   | `1`      |
| `arr + i`   | 数组第 i 个元素的地址| `&arr[i]`|
| `*(arr + i)`| 数组第 i 个元素的值  | `arr[i]` |

#### 4.2 指针遍历数组

```c
int arr[3] = {1, 2, 3};
int *p = arr;
for (int i = 0; i < 3; i++) {
    printf("%d ", *(p + i));
}
```

---

### 五、☆ 指针与函数

#### 5.1 指针作为函数参数

通过指针传递参数可以实现函数对变量的修改。

```c
void change(int *p) {
    *p = 100;  // 修改 p 指向变量的值
}

int main() {
    int a = 10;
    change(&a);
    printf("a = %d\n", a);  // 输出: a = 100
    return 0;
}
```

#### 5.2 返回指针的函数

函数可以返回指针，但要保证返回的指针是有效的。

```c
int* getPointer() {
    static int a = 10; // 静态变量，生命周期与程序相同
    return &a;
}
```

---

### 六、指针与动态内存分配

#### 6.1 动态内存分配函数

- `malloc`：分配内存但不初始化。
- `calloc`：分配并初始化为 0。
- `realloc`：重新调整内存大小。
- `free`：释放动态分配的内存。

#### 6.3 `malloc` 和 `free` 的用法

`malloc` 和 `free` 是 C 语言中用于动态内存分配和释放的函数。

- `malloc`：用于在堆区分配指定大小的内存，返回一个指向分配内存的指针。如果分配失败，返回 `NULL`。
    ```c
    void* malloc(size_t size);
    ```

- `free`：用于释放之前通过 `malloc` 分配的内存，释放后该内存可以被重新分配。
    ```c
    void free(void* ptr);
    ```

示例：

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = (int *)malloc(5 * sizeof(int)); // 分配内存
             // 这里的 (int *) 是强制类型转换，将 void* 转为 int* 
    
    if (p == NULL) {
        printf("内存分配失败\n");
        return -1;
    }

    for (int i = 0; i < 5; i++) {
        p[i] = i + 1; // 初始化
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", p[i]); // 输出
    }

    free(p); // 释放内存
    return 0;
}
```

---

### 七、多级指针

多级指针指的是指向指针的指针，例如 `int **p`。

#### 7.1 定义与使用

```c
int a = 10;
int *p1 = &a;  // 一级指针
int **p2 = &p1; // 二级指针

printf("a = %d\n", **p2);  // 解引用两次，访问 a 的值
```

---

### 八、指针的注意事项

1. 指针必须初始化后才能使用。
2. 指针操作需确保地址有效，避免野指针。
3. 使用 `free` 后需将指针置为 `NULL`。
4. 小心指针越界和非法内存访问。

---
