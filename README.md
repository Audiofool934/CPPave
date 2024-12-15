# CPPave

*"paving the way for future programming learning"*

## Introduction

**"CPPave"** is a collection of notes, examples, and exercises for learning C programming language, as well as data structures, and algorithms. The goal is to provide a **comprehensive and intuitive** understanding of these topics.

**Basic:** This section covers the fundamental concepts of C programming, including data types, I/O operations, arrays, strings, structures, pointers, and functions.

**Data Structures:** Due to time constraints, this section offers a brief introduction and intuitive examples of key data structures, such as arrays, linked lists, stacks, queues, trees, and graphs.

**Algorithms:** This section focuses on core algorithmic concepts, including recursion, divide and conquer, backtracking, dynamic programming, depth-first search, and searching and sorting techniques.

Given my limited knowledge and experience, there may be mistakes or misunderstandings. If you notice any errors or have suggestions for improvement, please feel free to reach out. Special thanks to LLMs' assistance XD.

These notes are based on the following sources and references: (highly recommended if you have the time to explore further):

[1] Erickson, J. (2019). *Algorithms* (1st ed.). Self-published. Retrieved from http://jeffe.cs.illinois.edu/teaching/algorithms

[2] Hello 算法. (n.d.). *Hello Algo*. Retrieved December 15, 2024, from https://www.hello-algo.com

[3] 菜鸟教程. (n.d.). *Runoob.com*: 菜鸟教程. Retrieved December 15, 2024, from https://www.runoob.com



<!-- 梳理：C++学习路径❌，并非路径！
入口有很多，开始会overwhelmed，但是后面回过头来看，往往会不一样，有顿悟的感觉！

coding 越学越容易（不是algo、theoretical cs）
math 才是越学越难

编程语言（与物理层面计算机进行交互）--抽象-> 数据结构 --实现-> 算法
所以要分成两个部分：编程语言学习，与数据结构算法学习，但是二者又不可能分开 -->

## Basic

- [x] [Data Type (数据类型)](paves/basics/data_type.md)
- [x] [IO (输入输出)](paves/basics/io.md)
- [x] [Array (数组)](paves/basics/array.md)
- [x] [String (字符串)](paves/basics/string_c.md)
- [x] [Struct (结构体)](paves/basics/struct.md)
- [x] [Pointer (指针)](paves/basics/pointer.md)
- [x] [Function(and scope) (函数以及变量作用域)](paves/basics/function_n_scope.md)

## Data Structures

### 🏗️ [Work in progress](./paves/data_structure/data_structure.md)

## Algorithm

### [Introduction](./paves/algorithms/introduction.md)
[Time/Space Complexity (时空复杂度)](https://www.hello-algo.com/chapter_computational_complexity/)

---

### <u style="color:lightblue">[Recursion (递归)](./paves/algorithms/recursion.md)</u>

**Takeaway:**

Recursion is a powerful technique in programming and algorithm design, deeply rooted in **Mathematical Induction** and **Reduction principles**. It allows complex problems to be broken down into simpler subproblems, relying on a **base case** and an **inductive step** to ensure correctness.

1. **Mathematical Induction as a foundation:** Recursion mirrors induction by solving the base case first and assuming smaller subproblems are solvable (inductive hypothesis).
2. **Reduction in recursion:** Problems are transformed into smaller instances of the same problem, solved recursively until the base case is reached.
3. **Call Stack:** Recursive function calls utilize a call stack, with each recursive call pushing a new stack frame and returning results as frames are popped.
4. **Comparison with iteration**: Recursion emphasizes problem decomposition, while iteration focuses on process repetition, each with its unique strengths depending on the context.
5. **Efficiency:** While recursion offers elegant solutions (e.g., Fibonacci sequence), it can lead to inefficiencies like redundant computations. Techniques like **dynamic programming** or **memoization** can optimize recursive algorithms (we will explore these techniques later).

---

### <u style="color:lightblue">[Divide and Conquer (分而治之)](./paves/algorithms/divide_n_conquer.md)</u>

**Takeaway:**

Whether it’s **mergesort**, **quicksort**, **nearest points**, or KD-Tree construction, the **divide-and-conquer** strategy is a powerful approach to solving complex problems. By breaking a problem into smaller subproblems **(Divide)**, recursively solving them Points, and combining their solutions into a final result **(Combine)**, we not only simplify problem analysis and correctness proofs but also significantly enhance computational efficiency.

---

### <u style="color:lightblue">[Backtracking (回溯)](./paves/algorithms/backtracking.md)</u>

**Takeaway:**

Backtracking is a versatile algorithmic technique that **systematically explores all potential solutions to a problem by <span style="color:lightblue">incrementally building candidates</span> and <span style="color:#F08080">abandoning (“backtracking”) those that fail to satisfy the problem’s constraints</span>**. 

Its core involves recursive decision-making, **leveraging partial solutions to navigate vast solution spaces effectively**. Applications span diverse problems like the N-Queens puzzle, subset sum, permutations, and game tree analysis, emphasizing:
1. Recursive Decision-Making: Each recursive call represents **one decision** while maintaining consistency with prior decisions.
2. Efficiency via Pruning: By skipping infeasible or redundant states, backtracking avoids unnecessary computation.
3. Generalization Potential: Backtracking often solves a broader problem for simplicity and adaptability.

<span style='color:#F08080'> <b>first make it work, then make it fast.</b></span>

---

### <u style="color:lightblue">[Dynamic Programming (动态规划)](./paves/algorithms/dynamic_programming.md)</u>

**Takeaway:**

**Dynamic Programming (DP)** and **memoization** are fundamentally equivalent techniques for solving problems with overlapping subproblems and optimal substructure. Both methods ensure that **each subproblem is solved only once**:
1. Memoization: A top-down approach that starts with the main problem and **recursively breaks it into smaller subproblems**, caching solutions to avoid redundant computations.
2. Dynamic Programming: A bottom-up approach that **iteratively builds solutions from base cases**, ensuring dependencies are resolved before progressing.

While their implementation differs, the underlying principle—**avoiding redundant computations by reusing previously solved results**—remains the same.

---

### 🏗️ Depth-First Search (深度优先搜索)


---

### 🏗️ Searchign & Sorting (查找与排序)

---

### 🏗️ [Utility (实用算法)](./paves/algorithms/utility.md)
