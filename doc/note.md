# All in Cpp Note

从类开始重学

--------

## Git

### 工作区、暂存区、版本库、远程仓库

```bash
# 工作区->暂存区：
git add filename

# 暂存区->版本库(本地)：
git commit -m "Commit message"

# 版本库->远程仓库：
git push origin branch-name

# 版本库(本地)<- 远程仓库
git pull origin branch-name
# 或者
git fetch origin branch-name
git merge origin/branch-name
```

### 基本操作

![6个命令](assets/git的6个命令.png)

- `workspace`：工作区
- `staging area`：暂存区/缓存区
- `local repository`：版本库或本地仓库
- `remote repository`：远程仓库

## 内存分区模型

- 代码区：存放代码
- 全局区：**全局变量**、**静态变量**、**常量**
- 栈区：**函数参数**、**局部变量**。由编译器管理生命周期。
- 堆区：new出来的内存。由程序员管理生命周期

代码区和全局区存在于可执行文件中，堆栈在程序运行之后产生。

另：

- `const`修饰的全局变量视为常量(由其创建之后不可修改可印证)，放在全局区中。
- 由之前所学，得出一点注意事项：**不要返回局部变量地址**。  
  例如在函数中声明了一个局部变量并返回，可以正确返回，但函数结束之后，内存会被自动释放，指针变成野指针。  
  有意思的是：现代编译器会把这个局部变量做一次保留，被读取一次之后再释放。但这么做依然是不安全的。

## 引用

给变量起别名。很多情况能起到和指针一样的作用(操作特定一块内存)。

引用必须初始化，初始化之后不可再改变。

> 将字符串作函数参数时，如果不必创建待修改的副本，函数参数类型可写为`const &string`。  
> 其一，它避免了字符串拷贝。  
> 其二，它防止了字符串在函数中被修改。

拓展以上：  
引用能作为函数参数。此时类似于地址传递，但不能作指针偏移，修改值时不需要解引用。  
引用能作为函数返回值。返回之后不会像新创建的变量一样被销毁，但使用方式和变量一样。

引用的本质 ———— **指针常量**  
即：  
`int & ref` == `int* const ref`

## 时间&日期

C++主要用`tm`类型处理时间与日期。

```C++
struct tm {
  int tm_sec;   // 秒，正常范围从 0 到 59，但允许至 61
  int tm_min;   // 分，范围从 0 到 59
  int tm_hour;  // 小时，范围从 0 到 23
  int tm_mday;  // 一月中的第几天，范围从 1 到 31
  int tm_mon;   // 月，范围从 0 到 11
  int tm_year;  // 自 1900 年起的年数
  int tm_wday;  // 一周中的第几天，范围从 0 到 6，从星期日算起
  int tm_yday;  // 一年中的第几天，范围从 0 到 365，从 1 月 1 日算起
  int tm_isdst; // 夏令时
};
```

另有:

1. `time_t`：自 1970 年 1 月 1 日以来经过的秒数，获取失败返回-1。
2. `clock_t`：程序执行所使用的时间，获取失败返回-1。
3. `size_t`：不同平台用以格式化时间量的中间变量。需配合相关函数使用。

相关方法：

```C++
// 该函数返回系统的当前日历时间，自 1970 年 1 月 1 日以来经过的秒数。如果系统没有时间，则返回 -1。
time_t time(time_t *time);
// 该返回一个表示当地时间的字符串指针，字符串形式 day month year hours:minutes:seconds year\n\0。
char *ctime(const time_t *time);
// 该函数返回一个指向表示本地时间的 tm 结构的指针。
struct tm *localtime(const time_t *time);
// 该函数返回程序执行起（一般为程序的开头），处理器时钟所使用的时间。如果时间不可用，则返回 -1。
clock_t clock(void);
// 该函数返回一个指向字符串的指针，字符串包含了 time 所指向结构中存储的信息，返回形式为：day month date hours:minutes:seconds year\n\0。
char * asctime ( const struct tm * time );
// 该函数返回一个指向 time 的指针，time 为 tm 结构，用协调世界时（UTC）也被称为格林尼治标准时间（GMT）表示。
struct tm *gmtime(const time_t *time);
// 该函数返回日历时间，相当于 time 所指向结构中存储的时间。
time_t mktime(struct tm *time);
// 该函数返回 time1 和 time2 之间相差的秒数。
double difftime ( time_t time2, time_t time1 );
// 该函数可用于格式化日期和时间为指定的格式。
size_t strftime();
```

> [C++ 日期 & 时间 | 菜鸟教程](https://www.runoob.com/cplusplus/cpp-date-time.html)

## 基本输入输出

- cout  
  无缓冲，在刷新或缓冲区满时显示在输出设备上。可用`endl`、`fflush`刷新缓冲区。
- cerr  
  标准错误流，无缓冲，立刻输出。
- clog  
  标准日志流，有缓冲。
- cin  
  标准输入流，从输入设备到变量等地方。

## 小东西 - 函数占位参数

例如：`int func(int a, int, int b)`

函数重载时可以用来提高可读性。可能还有其他用途。

占位参数也可以有默认参数。

## 封装、继承、多态

### 封装

- 将属性和行为作为一个整体
- 权限控制

一些名词：`属性(Attribute)`、`字段(Field)`、`方法(Method)`、`行为(Behavior)`：

- `属性`和`字段`：两者概念大部分是重叠的，前者更多考虑封装性和数据验证；后者更多考虑作为成员变量。
- `方法`和`行为`：行为指类能实现的操作，一般通过方法实现。
- 它们被统一称为`成员`。

### 继承



## 友元函数

定义在类外部，但能访问类的`private`、`protect`成员。*友元函数不属于成员函数*。使用`friend`关键字声明友元。

用类似的写法可以声明友元类。由友元类实例出的对象都能访问原本的类的私有和保护成员。

写法：

```C++
class classname
{
public:
  friend void func(int arg);
  friend class friend_class;
}
```



























