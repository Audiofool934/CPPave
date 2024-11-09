## Struct

**为面向对象编程奠定了基础**

**结构体**（`struct`）是 C 语言中一种用户定义的数据类型，它允许将**不同类型的数据**组合在一起，用于定义更复杂的数据结构。结构体提供了一个封装多种数据的方式，是实现**面向对象**编程的一种重要手段。

### 定义结构体

使用 `struct` 关键字定义结构体，并指定结构体的成员。结构体成员可以是任何数据类型，包括其他结构体。

```c
struct tag { 
    member-list
    member-list 
    member-list  
    ...
} variable-list ;
```

例子

```c
struct Student {
    char name[50];    // 学生姓名
    int age;          // 学生年龄
    float grade;      // 学生成绩
};
```

### 声明结构体变量

定义结构体后，可以使用结构体名称来声明变量，方式有两种：

**单独声明变量**：

```c
struct Student {
    char name[50];
    int age;
    float grade;
}

struct Student student1;
```

**在定义结构体时同时声明变量**：

```c
struct Student {
    char name[50];
    int age;
    float grade;
} student1, student2;
```

### 初始化结构体变量

结构体变量可以在声明时直接初始化：

```c
struct Student student1 = {"Alice", 20, 85.5};
```

初始化时按成员顺序赋值，也可以在运行时逐个赋值：

```c
struct Student student2;
student2.age = 21;
student2.grade = 90.0;
strcpy(student2.name, "Bob");  // 赋值字符串
```

### 访问结构体成员

使用**成员访问运算符** `.` 来访问结构体的成员：

```c
printf("Name: %s\n", student1.name);
printf("Age: %d\n", student1.age);
printf("Grade: %.1f\n", student1.grade);
```

### 结构体数组

可以定义一个结构体数组来存储多个结构体变量，例如多个学生的信息：

```c
struct Student students[3] = {
    {"Alice", 20, 85.5},
    {"Bob", 21, 90.0},
    {"Charlie", 19, 92.5}
};
```

访问结构体数组中的成员：

```c
for (int i = 0; i < 3; i++) {
    printf("Student %d: %s, %d, %.1f\n", i+1, students[i].name, students[i].age, students[i].grade);
}
```

使用 `typedef` 关键字定义结构体类型的别名：

```c
typedef struct Student {
    char name[50];
    int age;
    float grade;
} Student;

Student student1 = {"Alice", 20, 85.5};
```

### 结构体指针

可以使用指针指向结构体变量，使用 `->` 运算符来访问结构体成员。

```c
struct Student student1 = {"Alice", 20, 85.5};
struct Student* ptr = &student1;

printf("Name: %s\n", ptr->name);
printf("Age: %d\n", ptr->age);
printf("Grade: %.1f\n", ptr->grade);
```

### 结构体作为函数参数

可以将结构体传递给函数，分为**值传递**和**指针传递**。

1. **值传递**：函数会复制结构体的所有成员，适用于小型结构体，但会消耗更多内存。

   ```c
   void printStudent(struct Student s) {
       printf("Name: %s, Age: %d, Grade: %.1f\n", s.name, s.age, s.grade);
   }
   ```

2. **指针传递**：传递结构体的地址，更节省内存，适合大型结构体。

   ```c
   void updateGrade(struct Student* s, float newGrade) {
       s->grade = newGrade;
   }
   ```

### 结构体的大小

```c
struct Person {
    char name[20];
    int age;
    float height;
};

int main() {
    struct Person person;
    printf("结构体 Person 大小为: %zu 字节\n", sizeof(person));
    return 0;
}
```

*注意，结构体的大小可能会受到编译器的优化和对齐规则的影响，编译器可能会在结构体中插入一些额外的填充字节以对齐结构体的成员变量，以提高内存访问效率。因此，结构体的实际大小可能会大于成员变量大小的总和*