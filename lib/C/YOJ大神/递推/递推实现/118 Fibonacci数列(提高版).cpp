#include <stdio.h>

#define MOD 10000

// 矩阵结构
typedef struct {
    int a, b, c, d;
} Matrix;

// 矩阵乘法
Matrix matrixMultiply(Matrix m1, Matrix m2) {
    Matrix result;
    result.a = (m1.a * m2.a + m1.b * m2.c) % MOD;
    result.b = (m1.a * m2.b + m1.b * m2.d) % MOD;
    result.c = (m1.c * m2.a + m1.d * m2.c) % MOD;
    result.d = (m1.c * m2.b + m1.d * m2.d) % MOD;
    return result;
}

// 快速幂算法来计算矩阵的幂
Matrix fastPower(Matrix m, int n) {
    Matrix result = {1, 0, 0, 1}; // 单位矩阵
    while (n) {
        if (n & 1) result = matrixMultiply(result, m);
        m = matrixMultiply(m, m);
        n >>= 1;
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0\n");
    } else {
        Matrix m = {1, 1, 1, 0};
        Matrix result = fastPower(m, n - 1);
        printf("%d\n", result.a); // F[n] 是结果矩阵的左上角元素
    }

    return 0;
}

/*快速幂 by GPT4
快速幂算法是一种高效的算法，用于计算 \( a^n \)（即a的n次幂），其中 \( a \) 是一个数字，\( n \) 是一个非负整数。这种算法比直接使用连续乘法要快得多，尤其是当指数 \( n \) 非常大时。其基本原理是利用幂运算的性质来减少计算次数。

### 基本原理

快速幂算法基于幂运算的以下性质：

1. \( a^{b+c} = a^b \times a^c \)
2. \( a^{2b} = (a^b)^2 \)

这意味着我们可以将幂拆分成更小的部分来计算，特别是通过将幂表示为二进制形式，我们可以有效地将问题拆分成更小的部分。

### 算法步骤

1. **二进制表示**：将指数 \( n \) 转换为二进制表示。
2. **迭代计算**：对于 \( n \) 的每一位二进制数（从最低位到最高位）：
   - 如果位为1，将当前结果乘以当前的基数 \( a \) 的幂。
   - 每次迭代，将基数 \( a \) 平方（即 \( a = a \times a \)）。
3. **最终结果**：迭代完成后的累积结果即为 \( a^n \)。

### 示例

假设我们要计算 \( 3^13 \)。首先将13表示为二进制数，即1101。然后按照以下步骤进行计算：

- 初始化结果 res = 1, base = 3。
- 从13的最低位开始（即从右向左）：
  - 第1位为1：res = res * base = 3。
  - base平方：base = 9。
  - 第2位为0：跳过。
  - base平方：base = 81。
  - 第3位为1：res = res * base = 3 * 81 = 243。
  - base平方：base = 6561。
  - 第4位为1：res = res * base = 243 * 6561。
- 最终 res = 1594323，即 \( 3^{13} \)。

### 优点

- **效率高**：算法的时间复杂度为 \( O(\log n) \)，远低于直接连乘的 \( O(n) \)。
- **适用广泛**：可用于大数幂运算，也可扩展到矩阵快速幂，广泛应用于算法和密码学领域。

快速幂算法是计算幂运算的高效方法，特别是在涉及大数或需要重复幂运算的场景中非常有用。
*/