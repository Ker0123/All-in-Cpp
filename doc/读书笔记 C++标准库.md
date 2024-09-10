# 第ⅱ部分 C++标准库

## 第8章 IO库

### 8.1 IO类

宽字符类型`wchar_t`，和配套的IO类：

- `wchar_t`本质是一个16位的数据类型，与`int`相当。
- 其对应的类型与函数均以字符w开头：`wchar_t`、`wchin`、`wcout`、`wcerr`。

文件流`fstream`、字符流`sstream`均继承自标准输入输出流`iostream`。因此`iostream`的绝大多数属性都适用于其他二者。  
例如：可以对一个`ifstream`或`sstringstream`使用`getline()`；可以使用`>>`从`ifstream`获取数据。

可用`eof()`、`fail()`等函数获取流状态。(略)

输出流都有缓冲区，数据可能被保留在缓冲区，也可能立即打印。  
使缓冲区刷新的原因：

- 程序正常结束
- 缓冲区满
- 用操纵符刷新: `endl`换行并刷新；`flush`刷新；`ends`输出空字符并刷新。
- 每个输出操作后，用操纵符`unitbuf`设置流内部状态。默认`cerr`是设置`unitbuf`的，因此写到`cerr`的数据都是立即刷新。
- 关联的输出流被读写。例如`cin`和`cerr`都是关联到`cout`的，读写前两者都会导致`cout`刷新。

> `unitbuf`操纵符
> 对流使用之后，所有的流操作都会立即刷新
> 用`nounitbuf`重置流
> cout << unitbuf;
> cout << nounitbuf;




