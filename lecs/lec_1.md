## Lec 1

### Coverage

- [ ] [Data Type](../paves/basics/datatype.md)

- [ ] [IO](../paves/basics/io.md)

- [ ] [Array](../paves/basics/array.md)
- [ ] [String(C)](../paves/basics/string_c.md)
- [ ] [Struct](../paves/basics/struct.md)

- [ ] [Sorting](../paves/algorithms/sorting.md)
- [ ] [Utility_Algo](../paves/algorithms/utility.md)

### Code Arrangement

模块化设计，虽然不是面向对象编程，但是模块化的思想很重要。提高代码的可读性和可维护性；便于调试；便于复用；为后续OOP打下基础。

### Debugging

- 在合适的地方打印变量
- 尽可能用简单但全面的case测试程序
- 用gdb调试程序

### OJ

#### 几种（常见）错误类型：

`Compile Error (CE)`: 一般来说在本地编译后不会出现CE，如果是的话检查编译器版本
`Wrong Answer (WA)`: 注意**边界情况**
`Time Limit Exceeded (TLE)`: 算法复杂度过高，检查不必要的循环（但往往是算法本身的问题）
`Memory Limit Exceeded (MLE)`: 递归深度过大，导致栈溢出
`Runtime Error (RE)`: 运行过程中崩溃，通常因为非法操作或数据访问错误（数组越界访问、除零、空指针、未初始化变量）

#### 测试点设置：

- 可能会根据想要考察的算法特性设计测试点，会有几个较难的点，考察算法性能；
- 边界情况可能会被考察

### Tips

- 《程序设计Ⅰ》课程对同学来说压力本身就比较大（时间上是time-consuming，并且容易被打击）—— 所以就不要再给自己加peer pressure了😂
- 限时训练的时候一定要 calm down 拿到能达到的分数
- 

### [《综合练习》](exercises/lec_1/comprehensive.md)

758	序列最小差
209	triangel
582	统计各个年级的某个姓的同学并且排序
601	社交距离
273	K近邻算法

1 3 5 7 8 9 10 88 89 110 116 128 135 140 151 152 154 161 170 170 171 172 175 178 179 180 183 185 187 188 191 195 255 257 288 287 292 297 300 303 307 310 316 456 490 565 856 858



* 注意，条件语句中的条件是有先后顺序的，如果前面的条件满足，后面的条件就不会被执行