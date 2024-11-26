## Divide and Conquer (分而治之)

### sources and references

>Both mergesort and quicksort follow a general three-step pattern called **divide and conquer**:
>1.**Divide** the given instance of the problem into <u>several independent smaller instances of exactly the same problem</u> <span style="color:lightblue">(reduction)</span>.
>2.**Delegate** each smaller instance to the Recursion Fairy <span style="color:lightblue">(induction hypothesis)</span>.
>3.**Combine** the solutions for the smaller instances into the final solution for the given instance.

>If the size of any instance falls below some constant threshold, we abandon recursion and solve the problem directly, by brute force, in constant time <span style="color:lightblue">(base case)</span>. Proving a divide-and-conquer algorithm correct almost always requires induction. Analyzing the running time requires setting up and solving a recurrence, which usually (but unfortunately not always!) can be solved using recursion trees.

>-- <cite>Algorithms, by Jeff Erickson</cite>

### Overview

在考虑一个递归算法时，我们可以将其分为三个步骤：
1. **Divide**：将问题分解为更小的子问题
2. **Delegate**：递归地解决这些子问题
3. **Combine**：将子问题的解合并为原问题的解

### 典例

- [x] [Quick Sort](../../code/examples/quick_sort.md)
- [x] [Merge Sort](../../code/examples/merge_sort.md)
