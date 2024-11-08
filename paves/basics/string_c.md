## String(C)

在 C 语言中，字符串实际上是使用空字符 `\0` 结尾的**一维字符数组**

### 字符串的初始化

```c
char str[] = "CPPave";
```

### string.h

`strcmp(s1, s2)` // 有的时候会简化很多！
如果 `s1` 和 `s2` <span style="color:red">相同，则返回 0</span>；如果 `s1`<`s2` 则返回小于 0；如果 `s1`>`s2` 则返回大于 0（这里字符串比较按照<span style="color:red">字典顺序</span>）

`strncmp(s1, s2, n)` // 比较前 n 个字符
比较`s1`, `s2` 中 `[a, a + n]` 内的字符串:
    
```c
strncmp(s1+a, s2+a, n)
```

`strcpy(s1, s2)`
复制字符串 `s2` 到字符串 `s1`

`strcat(s1, s2)`
连接字符串 `s2` 到字符串 `s1` 的末尾

`strlen(s1)`
返回字符串 `s1` 的长度

`strchr(s1, ch)`
返回一个指针，指向字符串 `s1` 中字符 `ch` 的第一次出现的位置。

`strstr(s1, s2)`
返回一个指针，指向字符串 `s1` 中字符串 `s2` 的第一次出现的位置。