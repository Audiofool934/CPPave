## IO

`stdio.h` --- 标准输入输出头文件

### `getchar()` & `putchar()`

`int getchar(void)`
`int putchar(int c)` // int 是因为返回值是 `EOF` 或者 `c`

```c
int c;
c = getchar();
putchar(c);
```

本质上是用ASCII码来处理单个字符，所以用 `int` 类型来接收

忘记了ASCII码？👇

```c
int a = 'a';
printf("a = %d\n", a);
return 0;
```

读取一行（最后有回车）：
```c 
while ((c = getchar()) != '\n') {
    putchar(c);
}
```

读取未知长度的字符串：

`EOF`(End Of File) 是一个常量，表示**文件结束**
在读取输入时，可以使用 `EOF` 来判断是否已经到达输入的末尾

```c
int c;
while ((c = getchar()) != EOF) {
    putchar(c);
}
```

这个循环会一直读取字符，直到遇到 `EOF`，即输入结束
（在终端中，可以通过按 `Ctrl+D` 来发送 `EOF` 信号，调试的时候用）

### `gets()` & `puts()`

`char* gets(char* s)`
`int puts(const char* s)` // 返回值是 `EOF` 或者 `1`；字符串末尾会自动添加换行符

```c
char str[100];
gets(str);
puts(str);
```

### `scanf()` & `printf()`

`int scanf(const char* format, ...)` // 函数从标准输入流stdin读取输入，并根据format参数来解析输入
`int printf(const char* format, ...)` // 函数把输出写入到标准输出流stdout，根据format参数来生成输出

```c
int a; long long aa; float b; char c[10];
scanf("%d %lld %f %s", &a, &aa, &b, c);
printf("%d %lld %f %s\n", a, aa, b, c);
```

在读取字符串时，只要遇到一个空格，scanf() 就会停止读取，所以 "this is test" 对 scanf() 来说是三个字符串。

`scanf` 的 `format` 参数用于指定如何解析输入。**空格会被忽略**，但其他特殊字符（如 `-`、`:`、`,` 等）会被视为**分隔符**，并且 `scanf` **会尝试匹配这些字符**

并不是true or false（不是reg exp！），scanf会尝试去匹配，这里需要清楚，“到底读到了什么”，如果输入的format比较复杂，可能会读入错误的数据类型！

例子：
```c
int a, int b, int c;
scanf("%d%d%d", &a, &b, &c);
scanf("%d %d %d", &a, &b, &c);
scanf("%d       %d %d", &a, &b, &c);
// 没有任何区别！
```
输入：
```
1 2 3
```
输入中的空格，是为了让`scanf`函数能够处理成多个`%d`（否则会出现矛盾！123 or 1 23 or 1 2 3？），**而不是将空格与format字符串中的空格匹配！**

例子：
```c
int a, b; char c;
scanf("%d %c %d", &a, &c, &b);
printf("%d - %c - %d\n", a, c, b);
```

输入：
```
12c1
```
输出？
```
12 - c - 1
```
`%f` 是格式化字符串，表示读取一个浮点数

---

如何理解 `&`：

`&` 是取地址符，表示将变量的地址传递给函数

First thing first: Check the output

关于 空格 和 特殊字符