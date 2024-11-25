## Data Type

关注条件中数据范围，一般不会太离谱

`int -> long -> long long`
`float -> double -> long double`

---

在 C 语言中，数据类型用于定义变量存储的数据种类，**以便编译器为其分配合适的内存空间**

C 语言的数据类型可以分为基本数据类型、构造数据类型、指针类型和空类型

---

## 1. 基本数据类型

基本数据类型（Primitive Data Types）用于表示简单的数据类型，如整数、浮点数和字符。

### 整数类型（Integer Types）

C 语言提供多种整数类型，可以根据数据范围选择适当的类型。

| 数据类型         | 大小     | 取值范围                         |
|------------------|----------|----------------------------------|
| `short`          | 2 字节   | -32,768 到 32,767               |
| `unsigned short` | 2 字节   | 0 到 65,535                     |
| `int`            | 4 字节   | -2,147,483,648 到 2,147,483,647 |
| `unsigned int`   | 4 字节   | 0 到 4,294,967,295             |
| `long`           | 4 或 8 字节 | -2^31 到 2^31-1 或更大          |
| `unsigned long`  | 4 或 8 字节 | 0 到 2^32-1 或更大              |
| `long long`      | 8 字节   | -2^63 到 2^63-1                |
| `unsigned long long` | 8 字节 | 0 到 2^64-1                    |

**示例**：
```c
int a = 10;
long b = 100000L;
unsigned int c = 50;
```

### 浮点类型（Floating Point Types）

浮点类型用于存储小数和科学计数法形式的数字。

| 数据类型    | 大小     | 精度（小数位）                   |
|-------------|----------|----------------------------------|
| `float`     | 4 字节   | 约 6-7 位                       |
| `double`    | 8 字节   | 约 15 位                        |
| `long double` | 10, 12 或 16 字节 | 高于 `double` 的精度（依赖实现） |

**示例**：
```c
float x = 3.14f;
double y = 3.141592653589793;
long double z = 3.14159265358979323846L;
```

### 字符类型（Character Type）

字符类型用于存储单个字符，通常占用 1 字节。`char` 类型可以存储 ASCII 字符值。

| 数据类型 | 大小     | 取值范围              |
|----------|----------|-----------------------|
| `char`   | 1 字节   | -128 到 127（带符号） |
| `unsigned char` | 1 字节 | 0 到 255          |

**示例**：
```c
char ch = 'A';
unsigned char uch = 255;
```

---

## 2. 构造数据类型（Derived Data Types）

构造数据类型由基本数据类型扩展而来，包括数组、结构体、枚举和联合等。

### 数组（Array）

数组用于存储多个相同类型的元素。数组元素在内存中连续存储，并使用索引访问。

**示例**：
```c
int arr[5] = {1, 2, 3, 4, 5};
char name[10] = "Alice";
```

### 结构体（Structure）

结构体用于将不同类型的变量组合成一个单一的数据单元。结构体的每个成员可以是不同的数据类型。

**示例**：
```c
struct Student {
    char name[50];
    int age;
    float grade;
};

struct Student student1 = {"Alice", 20, 85.5};
```

### 枚举（Enumeration）

枚举用于定义一组命名的整数常量，有助于提高代码的可读性。

**示例**：
```c
enum Day { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };
enum Day today = MONDAY;
```

### 联合（Union）

联合类似于结构体，但它的所有成员共享同一块内存，因此同一时间只能存储一个成员的值。

**示例**：
```c
union Data {
    int i;
    float f;
    char str[20];
};

union Data data;
data.i = 10;
```

---

## 3. 指针类型（Pointer Type）

指针用于存储变量的内存地址。指针可以指向任何数据类型，并支持间接访问和操作数据。

**示例**：
```c
int num = 10;
int* ptr = &num;
printf("Address of num: %p\n", ptr);
printf("Value of num: %d\n", *ptr);
```

### 常见指针操作

- **声明指针**：`int* ptr;` 指针存储一个 `int` 类型变量的地址。
- **取地址**：使用 `&` 运算符获取变量的地址。
- **解引用**：使用 `*` 运算符访问指针指向的变量的值。

---

## 4. 空类型（Void Type）

空类型（`void`）用于表示无类型或空数据类型，主要用于函数的返回类型或通用指针。

- **`void` 返回类型**：函数没有返回值。
  
  ```c
  void printMessage() {
      printf("Hello, World!\n");
  }
  ```

- **`void*` 指针**：通用指针，可以指向任意数据类型的地址，但必须在使用前进行类型转换。

  ```c
  void* ptr;
  int num = 10;
  ptr = &num; // 指向 int 类型的地址
  ```

---

## 5. 类型限定符（Type Qualifiers）

类型限定符用于修饰数据类型，以定义变量的使用规则，常见的限定符包括 `const`、`volatile` 和 `restrict`。

### `const`：常量限定符

- 使用 `const` 声明的变量值不能被修改。
  
  ```c
  const int MAX = 100;
  ```

### `volatile`：易变限定符

- 使用 `volatile` 告诉编译器变量可能随时被改变，不要对其进行优化。

  ```c
  volatile int flag = 1;
  ```

### `restrict`：指针限定符

- 仅用于指针，表明指针是该对象的唯一引用，能优化性能。

  ```c
  int* restrict p = &num;
  ```