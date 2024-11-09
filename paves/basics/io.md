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
int c;
while ((c = getchar()) != '\n') {
    // putchar(c);
}
```

读取未知长度的字符串：

`EOF`(End Of File) 是一个常量，表示**文件结束**
在读取输入时，可以使用 `EOF` 来判断是否已经到达输入的末尾

```c
int c;
while ((c = getchar()) != EOF) {
    // putchar(c);
}
```

这个循环会一直读取字符，直到遇到 `EOF`，即输入结束
（在终端中，可以通过按 `Ctrl+D` 来发送 `EOF` 信号，调试的时候用）

### `gets()` & `puts()`

**注意** `gets()` 函数已经被废弃，不建议使用！

`char* gets(char* s)`
`int puts(const char* s)` // 返回值是 `EOF` 或者 `1`；字符串末尾会自动添加换行符

```c
char str[100];
gets(str);
puts(str);
```

`gets` 函数在 C 语言中有多种潜在的问题，因此在 C11 标准中被废弃。以下是 `gets` 的常见问题及其替代方法 `fgets` 的详细说明。

#### `fgets()`

**`gets()`的潜在问题：**

1. **缓冲区溢出**：`gets` 没有边界检查，它会一直读取输入，直到遇到换行符 `\n` 为止。因此，**如果输入内容超过预分配的数组大小，`gets` 会导致缓冲区溢出，从而引发严重的安全漏洞。**

2. **不安全的输入处理**：`gets` 不允许限制输入字符数，无法确保数据的长度在预期范围内，因此可能导致意外的程序行为或崩溃。

3. **无法读取空行**：如果用户仅输入换行符 `\n`，`gets` 会将该输入忽略，而不会将其视为有效的空行。

#### 使用 `fgets` 替代 `gets`

```c
fgets(char* str, int size, FILE* stream);
```

- **`str`**：目标字符数组，存储读取的输入
- **`size`**：要读取的最大字符数，通常为字符数组的大小（例如，若数组大小为 100，使用 `fgets(str, 100, stdin);`）
- **`stream`**：输入流，标准输入为 `stdin`

例子

```c
char str[100];
fgets(str, sizeof(str), stdin); // 使用 fgets 读取最多 99 个字符
printf("%s", str)
```

注意 `fgets` 会将换行符 `\n` 一并读取并存储在字符串中。如果不需要换行符，可以手动将其去掉：

```c
str[strcspn(str, "\n")] = '\0'; // 去掉换行符
```

### `scanf()` & `printf()`

`int scanf(const char* format, ...)` // 函数从标准输入流stdin读取输入，并根据format参数来解析输入
`int printf(const char* format, ...)` // 函数把输出写入到标准输出流stdout，根据format参数来生成输出

| 数据类型 | 格式标识符 |
|---------|--------|
| **`int`** | `%d` |
| `long` | `%ld` |
| **`long long`** | `%lld` |
| `float` | `%f` |
| **`double`** | `%lf` |
| **`char`** | `%c` |
| **`char*`** (string) | `%s` |

```c
int a; long long aa; float b; char c[10];
scanf("%d %lld %f %s", &a, &aa, &b, c);
printf("%d %lld %f %s", a, aa, b, c);
```

#### 如何理解 `&`：

`&`：取址符
`scanf` 需要接收变量的地址，以便通过该地址直接修改变量的值
scanf 会将输入的数据按照 `%d` 的格式解析为整数，并将其存储在 `a` 的内存地址上，即 `&a` 所指向的地方。

对于 `char` 类型的字符串（字符数组）读取时，不需要 `&` 符号，因为字符数组的名称（如 `char str[100]`; 中的 `str`）本身就是一个**指向数组首地址的指针**，`scanf("%s", str)`; 是合法的。

#### 关于 `scanf`：

`scanf` 的 `format` 参数用于指定如何解析输入。**空格、`\n`、`\t`都会被忽略**，但其他特殊字符（如 `-`、`:`、`,` 等）会被视为**分隔符**，并且 `scanf` **会尝试匹配这些字符**

**remark:**
在读取字符串时，只要遇到一个空格，scanf() 就会停止读取，所以 "this is test" 对 scanf() 来说是三个字符串。

**remark:**
scanf的匹配并不是true or false（不是reg exp！），scanf会尝试去匹配，这里需要清楚，“到底读到了什么”，如果输入的format比较复杂，可能会读入错误的数据类型！

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

输入中的空格，是为了让`scanf`函数能够处理成多个`%d`（否则会出现矛盾！123 or 1 23 or 1 2 3？），**而不是将空格与format字符串中的空格匹配！**；输入时的空格、换行等**不会被严格匹配**，只要数据之间有空白字符分隔即可

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

### Format Output

`printf()` 可以使用格式化标识符对输出进行控制，允许我们以指定格式打印各种类型的数据。

#### 宽度和精度控制

例子：

```c
int a = 123;
printf("%5d\n", a);  // 输出：  123 （总宽度为5，右对齐，左边补空格）

float b = 3.14159;
printf("%.2f\n", b);  // 输出：3.14 （保留2位小数）

printf("%10.3f\n", b); // 输出：    3.142 （总宽度为10，保留3位小数，左边补空格）
```

#### 对齐方式

使用 `-` 来指定左对齐：

```c
printf("%-5d\n", a);  // 输出：123  （总宽度为5，左对齐）
```

#### 转义字符

在 C 语言中，**转义字符**用于表示一些特殊的字符，这些字符通常不能直接在字符串中使用。转义字符以反斜杠 `\` 开头，后面跟一个或多个字符来表示特定的含义。

| 转义字符 | 含义                   |
|----------|------------------------|
| `\n`     | 换行符（newline）      |
| `\t`     | 水平制表符（tab）      |
| `\\`     | 反斜杠字符（`\`）       |
| `\'`     | 单引号字符（`'`）       |
| `\"`     | 双引号字符（`"`）       |
| `\r`     | 回车符（carriage return） |
| `\v`     | 垂直制表符（vertical tab） |
| `\0`     | 空字符（null character） |

**`\0`（空字符）：**
- 表示字符串的结束，是字符串结尾的标记
- 在字符串中，`\0` 之后的字符将被忽略
- `\0` 是一个字符常量，表示空字符，在 `ASCII` 编码中对应数值 0
- 区别于空格字符 `' '`
- 区别于EOF（文件结束符）

**输出转义字符：**

| 要输出的转义字符 | 转义写法   | 解释                  |
|------------------|------------|-----------------------|
| `\`             | `\\`       | 输出反斜杠           |
| `"`             | `\"`       | 输出双引号           |
| `'`             | `\'`       | 输出单引号           |
| `\n`            | `\\n`      | 输出 `\n` 字符串本身 |
| `\t`            | `\\t`      | 输出 `\t` 字符串本身 |

### Tips 'N' Tricks

在做后面操作之前，先确保输入输出的正确性！

简单的字符集匹配，可以使用 `scanf` 的格式化标识符 `%[...]` 来匹配

```c
char str[100];

// 读取直到换行符
printf("Enter a string (stops at newline): ");
scanf("%[^\n]", str);
printf("You entered: %s\n", str);

// 只读取小写字母
printf("Enter lowercase letters only: ");
scanf("%[a-z]", str);
printf("You entered: %s\n", str);

// 读取非数字字符
printf("Enter non-digit characters: ");
scanf("%[^0-9]", str);
printf("You entered: %s\n", str);
```