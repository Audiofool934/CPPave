## Divide and Conquer (分而治之)

>Both mergesort and quicksort follow a general three-step pattern called **divide and conquer**:
>**1. Divide** the given instance of the problem into <u>several independent smaller instances of exactly the same problem</u> <span style="color:lightblue">(reduction)</span>.
>**2. Delegate** each smaller instance to the Recursion Fairy <span style="color:lightblue">(induction hypothesis)</span>.
>**3. Combine** the solutions for the smaller instances into the final solution for the given instance.
>
>If the size of any instance falls below some constant threshold, we abandon recursion and solve the problem directly, by brute force, in constant time <span style="color:lightblue">(base case)</span>. Proving a divide-and-conquer algorithm correct almost always requires induction.
>
>-- <cite>Algorithms, by Jeff Erickson</cite>

在考虑一个递归算法时，我们可以将其分为三个步骤：
1. **Divide**：将问题分解为更小的子问题
2. **Delegate**：递归地解决这些子问题
3. **Combine**：将子问题的解合并为原问题的解

### 典例: Merge Sort (归并排序)

1. 将一个数组分成两个子数组，分别进行排序。
2. 将两个有序子数组合并成一个有序数组。

#### divide & conquer

1. **分解(Divide)：** 将数组不断划分（二分），直到每个子数组只包含一个元素
2. **解决(Delegate)：** 对每个子数组进行排序（对于单个元素的数组，天然有序）
3. **合并(Combine)：** 将两个有序子数组合并为一个有序数组。

<img src="../../media/paves/algorithms/merge_sort_overview.png" alt="merge_sort_overview" width="500px"/>

#### 实现

```c
// 合并两个有序子数组
void merge(int arr[], int left, int mid, int right);

// 递归实现归并排序
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // 分解阶段
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并阶段
        merge(arr, left, mid, right);
    }
}
```

[full code](../../code/examples/merge_sort.c)

#### 关于归并排序

- 时间复杂度稳定为 \(O(n \log n)\)，不受输入数据分布的影响
- 是稳定的排序算法（排序前后相等元素的相对位置不变），适用于链表排序
- 需要额外的 \(O(n)\) 辅助空间

#### sources and readings

- [Hello 算法 - 归并排序](https://www.hello-algo.com/chapter_sorting/merge_sort/)4

### 典例: Quick Sort (快速排序)

1. 从数组中选择一个基准值(`pivot`)
2. 通过交换元素将数组划分为两部分：
   - 左部分的元素小于（等于）基准值
   - 右部分的元素大于基准值
3. 分别对左右两部分递归地进行快速排序

#### 分而治之

1. **分解(Divide)：** 选取基准值，将数组分成两部分
2. **解决(Delegate)：** 分别对左右两部分递归排序
3. **合并(Combine)：** 不需要额外的合并步骤——数组已经在递归中排序结束

<img src="../../media/paves/algorithms/quick_sort_overview.png" alt="merge_sort_overview" width="500px"/>

#### 实现

```c

// 分区函数：将数组分为两部分，返回基准值的索引
int partition(int arr[], int low, int high)

// 快速排序函数
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 分区操作，获得基准值的索引
        int pi = partition(arr, low, high);

        // 对基准值左边的部分排序
        quickSort(arr, low, pi - 1);
        // 对基准值右边的部分排序
        quickSort(arr, pi + 1, high);
    }
}
```

[full code](../../code/examples/quick_sort.c)

- **`partition` 函数：**
   - 核心是找到基准值的正确位置，并将数组分为两部分。
   - 使用**双指针法**，一个指针 \(i\) 指向小于等于基准值的区域，另一个指针 \(j\) 遍历数组
   - 每当发现一个小于等于基准值的元素，就交换它与 \(i+1\) 的位置，扩大小于等于基准值的区域。

- **`quickSort` 函数：**
   - 基准条件：当子数组的长度为 0 或 1 时，不再递归
   - 递归调用：对分区后的左右部分分别进行快速排序

#### 关于快速排序

- 时间复杂度：
  - **最好情况：** 每次分区都能将数组均分为两部分，递归深度为 \(\log n\)，每层操作 \(O(n)\)，总复杂度 \(O(n \log n)\)
  - **最坏情况：** 每次分区基准值都在数组的最左或最右，递归深度为 \(n\)，总复杂度 \(O(n^2)\)——**这时快速排序退化为冒泡排序**
  - **平均情况：** 分区效率接近于最好情况，总复杂度为 \(O(n \log n)\)。

- 原地排序，不需要额外的辅助数组
- 不稳定排序，可能改变相同值元素的相对位置

#### sources and readings

- [Hello 算法 - 快速排序](https://www.hello-algo.com/chapter_sorting/quick_sort/)

### 典例: Nearest Points (平面最近点对)

给定一个平面上的点集 $P = \{p_1, p_2, \dots, p_n\}$，其中每个点 $p_i$ 由其二维坐标 $(x_i, y_i)$ 表示，目标是找到距离最近的一对点，并返回它们之间的最短距离

最近点对问题可以通过分治法有效地解决，时间复杂度从暴力算法的 $O(n^2)$ 降低到 $O(n \log n)$，主要步骤如下：

#### 分而治之

1. **分解(Divide)：** 将点集按照 $x$ 坐标排序后，划分为左右两部分 $P_L$ 和 $P_R$，分别包含点集的左半部分和右半部分
2. **解决(Delegate)：** 递归地在 $P_L$ 和 $P_R$ 中分别求解最近点对，获得左右两部分的最小距离 $d_L$ 和 $d_R$
3. **合并(Combine)：** 
   1. 最近点对要么出现在 $P_L$ 或 $P_R$ 内部（对应 $d_L$ 或 $d_R$），要么跨越两部分
   2. 对于跨越两部分的情况，只需检查位于中间带宽为 $2\min(d_L, d_R)$ 的点对

#### 实现

```c
// 分治法计算最近点对
double nearestUtil(Point P[], int n) {
    // 当点数小于等于 3 时，使用暴力法
    if (n <= 3) {
        return bruteForce(P, n);
    }

    // 取中点
    int mid = n / 2;
    Point midPoint = P[mid];

    // 分别计算左右两部分的最近点对距离
    double dl = nearestUtil(P, mid);
    double dr = nearestUtil(P + mid, n - mid);

    // 当前的最近距离
    double d = fmin(dl, dr);

    // 构造跨越分割线的点集
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(P[i].x - midPoint.x) < d) {
            strip[j] = P[i];
            j++;
        }
    }

    // 返回三者中的最小值
    return fmin(d, stripNearest(strip, j, d));
}
```

[full code](../../code/examples/nearest_points.c)

可以进一步参考 [OI Wiki - 平面最近点对](https://oi-wiki.org/geometry/nearest-points/)

#### 进阶：Nearest neighbour search (NN)

The nearest neighbour search algorithm aims to find the point in the tree that is nearest to a given input point.

可以使用 [KD-Tree](https://oi-wiki.org/ds/kdt) 实现高效的最近邻搜索

<img src="../../media/paves/algorithms/nn_kdtree.gif" alt="nn_kdtree" width="500px"/>

<a href="https://en.wikipedia.org/wiki/K-d_tree"><em>Example of a nearest neighbor search in a 2-d tree.</em></a>

构造KD-Tree的过程是分治法的典型应用

1. **分解(Divide)：** 将点集按当前分割轴（例如 x 坐标）排序，选择中位数作为分割点，将点集划分为两部分：
   - 左侧点集：比中位数小
   - 右侧点集：比中位数大
2. **解决(Delegate)：** 对左右子集递归地重复上述操作，构建左子树和右子树
3. **合并(Combine)：** 将当前节点（中位点）连接到左右子树上，形成一棵完整的 KD-Tree

#### 实现

```c
// 构建 KD-Tree，参数：点集起始位置、结束位置（包含）、分割轴
KDNode *buildKDTree(Point *pts, int start, int end, int axis) {
    if (start > end) return NULL;
    int n = end - start + 1;
    // 中间点作为根
    int mid = start + n/2;

    // 根据当前轴进行排序
    if (axis == 0) {
        qsort(pts + start, n, sizeof(Point), cmp_x);
    } else {
        qsort(pts + start, n, sizeof(Point), cmp_y);
    }

    KDNode *node = (KDNode *)malloc(sizeof(KDNode));
    node->p = pts[mid];
    node->axis = axis;
    node->left = buildKDTree(pts, start, mid - 1, 1 - axis);
    node->right = buildKDTree(pts, mid + 1, end, 1 - axis);
    return node;
}
```

[full code](../../code/examples/nearest_points_query.c)

