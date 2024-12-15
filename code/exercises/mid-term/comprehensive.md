## Exercises - Comprehensive

### 序列最小差

#### 描述：

给定一个包含 $m$ 个整数的数组，要求计算该数组中任意两数之间差的绝对值的最小值

#### 输入：

1. 第一行输入一个整数 $m$，表示数组的长度（$2 \leq m \leq 1000$）
2. 第二行输入 $m$ 个整数，表示数组中的元素，每个整数的范围在 $-1000$ 到 $1000$ 之间

#### 输出：

一个整数，表示数组中任意两数之间差的绝对值的最小值

#### 样例输入：

```
5
3 8 15 1 9
```

#### 样例输出：

```
1
```
#### 解题思路：

1. 使用**暴力穷举法**计算最小差：遍历数组中的所有数对，计算差的绝对值并比较，取最小值
2. 可以优化为**排序法**：将数组排序后，只需比较相邻元素之间的差即可得到最小差

[code](code/min.c)

### Triangle

#### 描述：

给定一个包含 $n$ 个正整数的数组，这些整数表示若干条线段的长度。请在这些线段中选择三条线段组成一个三角形，并使该三角形的周长最大。如果无法组成三角形，则输出 0

#### 输入：

1. 第一行输入一个整数 $n$，表示数组的长度（$3 \leq n \leq 1000$）。
2. 第二行输入 $n$ 个正整数，表示线段的长度。

#### 输出：

一个整数，表示所能组成的最大周长的三角形。如果无法组成三角形，输出 0。

#### 解题思路：

1. 首先对数组中的线段长度从大到小排序，这样可以优先尝试最长的三条线段来组成最大周长的三角形。
2. 排序后，从最大处开始依次检查连续的三个线段 $a[i], a[i+1], a[i+2]$ 是否满足三角形不等式：
$$
a[i] < a[i+1] + a[i+2]
$$
3. 如果满足该条件，则它们的和就是最大的周长，输出其周长并结束。
4. 若遍历完数组仍未找到满足条件的三角形，则输出 0。

#### 样例输入：

```
5
2 3 10 4 5
```

#### 样例输出：

```
12
```

#### 思路

1. 因为要取最大值，所以先对数组排序，从最大处开始判断。  
2. 三角形三条边从大到小，按下标排序为$i$、$i+1$、$i+2$，若满足 $i <(i+1)+(i+2)$ 或者， $i -(i+1) < (i+2)$，则满足；如果不满足，下标右移，重新判断。

[code](code/triangle.c)

### 统计各个年级的某个姓的同学并且排序

#### 描述：  

给定一个包含学生信息的列表，每行包含学生的学号、姓和名。你需要统计指定姓氏的同学，并按学号中表示的年级从小到大进行排序，然后输出各个年级中该姓氏的学生人数。

学号的前四位表示入学年份。例如，学号 `20220001` 表示该学生入学年份为 2022 年。

#### 输入：

1. 第一行输入一个整数 $n$ 和一个字符串 $last\_name$，表示学生总人数和要统计的姓（$1 \leq n \leq 1000$，姓氏不超过 60 个字符）。
2. 接下来 $n$ 行，每行包含一个整数 $xuehao$ 和两个字符串 $a$ 和 $b$，分别表示学生学号、姓和名。

#### 输出：

按年级从小到大依次输出指定姓氏的学生人数。若无该姓氏的同学，则输出 `NONE`。

#### 解题思路：

1. 遍历每行输入数据，若姓与指定的 $last\_name$ 匹配，则将学号存入数组 `jieguo` 中
2. 对数组 `jieguo` 按年级（学号的前四位）从小到大排序。
3. 遍历排序后的数组，统计并输出每个年级中该姓的学生人数。

#### 样例输入：

```
6 Wang
20220001 Wang Ming
20220002 Wang Ming
20210002 Zhang Wei
20220003 Wang Li
20230004 Wang Hua
20210005 Li Lei
```

#### 样例输出：

```
2022 2
2023 1
```

#### 思路

1. 逐行输入学号+姓名后，进行判断（`strcmp`函数），若是该“姓”的同学，则存入数组中
2. 题目要求按照年度从小到大进行排序，故对数组进行排序
3. 累计计算每个年度的人数并输出

[code](code/names.c)

### K近邻算法

<img src="media/KNN.png" alt="KNN" width="500px">

#### 描述：
给定一组已知类别的样本点以及一个待分类样本点，使用K近邻算法判断待分类样本点所属的类别。

#### 输入：
1. 第一行输入两个整数 $m$ 和 $k$，分别表示类别总数和所需的最邻近样本数（$1 \leq m \leq 100$，$1 \leq k \leq 100$）。
2. 接下来是 $m$ 组数据，每组数据首先是一个整数 $n$（表示该类别的样本数量），然后是 $n$ 对整数 $(x, y)$，表示该类别下的样本点的坐标。
3. 最后一行输入两个整数 $x_0$ 和 $y_0$，表示待分类样本点的坐标。

#### 输出：
一个整数，表示待分类样本点所属的类别编号（1到$m$之间的一个数）。

#### 样例输入：
```
3 4
2 1 2 2 1
3 3 3 4 4 5 5
4 6 6 7 7 8 8 9 9
5 5
```

#### 样例输出：
```
2
```

#### 解题思路：
1. 使用四维数组存储已知样本点信息，包含类别编号、坐标点以及到待分类样本点的距离。
2. 对所有样本点按距离排序，若距离相同则按类别编号排序。
3. 找到距离待分类样本点最近的 $k$ 个样本，统计其中每个类别的出现次数。
4. 如果类别之间存在相同的数量，则选择类别编号最小的类别作为分类结果。

#### 特别说明
1. 如果待分类样本到两个点的距离D相同，那么它跟类别编号小的那个样本更相近
2. 如果最相似第 $ k+1, k+2, \dots , k+j $ 样本到待分类样本的距离等于最相似的第$k$个样本到待分类样本的距离，那么确定待分类样本的类别是需要考虑这$j$个样本
3. 与待分类样本最相似的$k$个样本中无法找到一个唯一的大多数所属的类别，则认为相同的大多数类别中类别编号小的那个类别为待分类样本所属的类别。例如$k = 4$时，如果发现$ k $个最相似的样本有2个来自`类别1`，另外2个来自`类别2`，则将待分类样本划分为`类别1`
4. 样本总数小于k时，考虑所有样本

#### 示例代码：

[使用结构体](code/knn.c)

[使用四维数组（不推荐）](code/knn_a.c)