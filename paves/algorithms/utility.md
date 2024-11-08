## Utility Algorithms

常见小算法

进制转换、快速幂、求最大公约数、素数筛选、字符串处理等。

---

### 1. 进制转换

#### 十进制转换为其他进制

将一个十进制数转换为二进制、八进制或十六进制。

**实现步骤**：
1. 使用除基取余法，将数反复除以目标进制，记录余数。
2. 余数的逆序即为转换后的数。

**示例代码**（十进制转二进制）：
```c
void decimalToBinary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }
    int binary[32], i = 0;
    while (num > 0) {
        binary[i++] = num % 2;
        num /= 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}
```

#### 其他进制转换为十进制

将二进制、八进制或十六进制转换为十进制。

**实现步骤**：
1. 使用权重法，从最低位到最高位，乘以对应的进制权重，累加每一位的值。
2. 累加结果即为十进制数。

**示例代码**（二进制转十进制）：
```c
int binaryToDecimal(const char* binary) {
    int decimal = 0, base = 1;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        decimal += (binary[i] - '0') * base;
        base *= 2;
    }
    return decimal;
}
```

---

### 2. 字符串翻转和回文检测

#### 字符串翻转

将一个字符串从头到尾逆序。

**实现步骤**：
1. 使用双指针交换字符串两端的字符，逐步向中间移动。

**示例代码**：
```c
void reverseString(char* str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left++] = str[right];
        str[right--] = temp;
    }
}
```

#### 回文检测

判断一个字符串是否是回文。

**实现步骤**：
1. 使用双指针，从两端向中间移动，比较字符是否相等。

**示例代码**：
```c
int isPalindrome(const char* str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        if (str[left++] != str[right--]) return 0;
    }
    return 1;
}
```

---

### 3. 快速幂算法（Exponentiation by Squaring）

用于快速计算 `a^b % mod`，减少计算次数，提高效率。

**实现步骤**：
1. 将指数按二进制分解，通过平方加速计算幂。
2. 每次遇到奇数指数时，乘入当前的基数。

**示例代码**：
```c
int powerMod(int a, int b, int mod) {
    int result = 1;
    a = a % mod;
    while (b > 0) {
        if (b % 2 == 1) result = (result * a) % mod;
        b = b / 2;
        a = (a * a) % mod;
    }
    return result;
}
```

---

### 4. 求最大公约数（GCD）和最小公倍数（LCM）

#### 欧几里得算法求 GCD

**实现步骤**：
1. 使用递归或循环的方式，不断用 `a % b` 直到余数为 `0`。
2. 当余数为 `0` 时，`b` 即为最大公约数。

**示例代码**：
```c
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
```

#### LCM 的求法

公式：`LCM(a, b) = a * b / GCD(a, b)`

**示例代码**：
```c
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}
```

---

### 5. 素数筛选（埃拉托色尼筛法）

用于在一定范围内快速筛选出所有素数。

**实现步骤**：
1. 创建一个布尔数组，将所有数标记为素数。
2. 从 2 开始，若当前数是素数，则将其所有倍数标记为非素数。
3. 重复直到 `sqrt(n)` 为止。

**示例代码**：
```c
void sieveOfEratosthenes(int n) {
    int isPrime[n + 1];
    memset(isPrime, 1, sizeof(isPrime));
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = 0;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (isPrime[p]) printf("%d ", p);
    }
}
```

---

### 6. 位运算常见技巧

位运算在很多题目中用来优化计算，例如交换变量、判断奇偶性、位移运算等。

#### 交换两个数

使用异或（XOR）交换两个变量，不用临时变量。

**示例代码**：
```c
void swap(int* a, int* b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}
```

#### 判断奇偶性

通过位运算判断数的奇偶性，`num & 1` 为 1 表示奇数，为 0 表示偶数。

**示例代码**：
```c
int isOdd(int num) {
    return num & 1;
}
```

#### 清除最低位的 1

`x & (x - 1)` 可以清除整数 `x` 的最低位 `1`，常用于统计二进制中 `1` 的个数。

**示例代码**：
```c
int countOnes(int x) {
    int count = 0;
    while (x) {
        x = x & (x - 1);
        count++;
    }
    return count;
}
```

---

### 7. 常用数学算法

#### 阶乘计算

递归或循环实现阶乘的计算。

**示例代码**：
```c
int factorial(int n) {
    return n == 0 ? 1 : n * factorial(n - 1);
}
```

#### 斐波那契数列

可以用递归、循环或动态规划实现，快速求解斐波那契数列。

**示例代码**（循环法）：
```c
int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
```
