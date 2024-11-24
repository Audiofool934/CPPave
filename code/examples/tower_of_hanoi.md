###  Tower of Hanoi (汉诺塔问题)

#### 一、什么是汉诺塔问题？
汉诺塔（Tower of Hanoi）问题是一个经典的递归算法问题：
- 有三根柱子（A、B、C），在柱子A上有若干不同大小的圆盘，从上到下按大小顺序排列。
- 目标是将所有圆盘从柱子A移到柱子C，并满足以下规则：
  1. 每次只能移动一个圆盘；
  2. 大圆盘不能放在小圆盘上。

#### 二、递归思想

1. **基准条件（Base Case）：** 确定递归何时结束。
2. **递归关系：** 将大问题分解成多个小问题。

汉诺塔问题的递归思想：
1. 将 \(n-1\) 个圆盘从 A 移动到 B（借助 C）；
2. 将第 \(n\) 个圆盘从 A 移动到 C；
3. 将 \(n-1\) 个圆盘从 B 移动到 C（借助 A）。

#### 三、分而治之思想

汉诺塔问题的核心是“分而治之”：
- **分解：** 将 \(n\) 个圆盘的移动分解为多个更小的子问题。
- **解决：** 通过递归解决较小规模的子问题。
- **合并：** 将子问题的解决方案结合，完成整个问题。

#### 四、C语言实现汉诺塔问题
下面是一个经典的汉诺塔递归实现：

```c
#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) { // 基准条件：当只有一个圆盘时，直接移动
        printf("Move disk %d from %c to %c\n", n, from, to);
        return;
    }
    // 步骤 1：将 n-1 个圆盘从 from 移到 aux，（借助 to）
    hanoi(n - 1, from, aux, to);
    // 步骤 2：将第 n 个圆盘从 from 移到 to
    printf("Move disk %d from %c to %c\n", n, from, to);
    // 步骤 3：将 n-1 个圆盘从 aux 移到 to，（借助 from）
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Steps to solve Tower of Hanoi for %d disks:\n", n);
    hanoi(n, 'A', 'C', 'B'); // 从 A 移到 C，（借助 B）
    return 0;
}
```

#### 五、代码分析
1. **递归基准条件：**
   ```c
   if (n == 1) {
       printf("Move disk %d from %c to %c\n", n, from, to);
       return;
   }
   ```
   当只剩一个圆盘时，直接从起点柱子移到目标柱子，递归终止。

2. **递归关系：**
   ```c
   hanoi(n - 1, from, aux, to); // 将 n-1 个圆盘移到辅助柱
   printf("Move disk %d from %c to %c\n", n, from, to); // 移动第 n 个圆盘
   hanoi(n - 1, aux, to, from); // 将 n-1 个圆盘移到目标柱
   ```
   通过递归调用实现问题的分解与组合。

3. **输入输出：**
   - 输入：圆盘数 \(n\)
   - 输出：移动步骤

#### 六、运行示例

输入圆盘数 \(n = 3\)，输出移动步骤：

```
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
```

#### 七、递归的时间复杂度

汉诺塔问题每次递归将 \(n\) 个圆盘分解为两个规模为 \(n-1\) 的子问题，因此递归公式为：
\[
T(n) = 2T(n-1) + O(1)
\]
通过递归展开，可得时间复杂度为：
\[
T(n) = O(2^n)
\]
这说明汉诺塔问题的时间复杂度随圆盘数量呈指数增长。

#### *构建递归树

https://images2015.cnblogs.com/blog/1026866/201610/1026866-20161016023307592-594782514.png

