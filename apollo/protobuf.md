# 简介：

跨语言跨平台 的 传输数据的载体（序列化传输---有顺序）。

内置编译器，将.proto文件编译为C++/Python等语言的代码，可以直接被对应语言使用，实现数据读写。

* Pro: 高效、便捷、跨语言、高兼容
* Con: 二进制易读性差、缺乏自描述

# 创建
在demo_proto文件夹下创建.proto文件，定义消息结构，例如：

```proto
syntax = "proto2";
package apollo.cyber.demo_proto; // package 包名用于声明作用域

message Person { 
  required string name = 1;     // required 必填字段（不建议用），   1 是字段编号, 后序2, 3 ...（起标记作用）
  optional int32 age = 2;       // optional 选填字段 
  repeated string books = 3;    // repeated 表示可重复字段（动态数组存储多个数据）
}
```
字段编号：每个字段有唯一编号，用于消息的二进制格式中标识字段。

# 编译
在demo_proto文件夹下新建BUILD文件，输入如下：

```bash
# 加载py_binary函数（cc_binary函数被默认加载）
load("//tools:python_rules.bzl", "py_proto_binary")
package(default_visibility = ["//visibility:public"])

# 生成proto库
proto_library(
    name = "stu_proto", //注意这里name必须添加_proto后缀，否则python调用异常
    srcs = ["stu.proto"],
)

# 生成C++对应的代码, 其他C++文件就能调用生成的函数获取proto信息了
cc_proto_binary(
    name = "stu_cc",
    deps = [":stu_proto"], # :是一种作用域前缀符号，:stu_proto当前目录下名为stu_proto目标
) 

# 生成Python对应的代码, 其他Python文件就能调用生成的函数获取proto信息了
py_proto_binary(
    name = "stu_py",
    deps = [":stu_proto"],
)
``` 



# c++实现读写

生成实现读写的文件test_stu.cc，内容如下：
```c++
// 设置字段 ： set/add_xxx
对象名.set_name("a")  // required和optional字段都是set
对象名.set_age(10)
对象名.add_books("xxx") // 如果是列表就是add
对象名.add_books("yyy") // 如果是列表就是add

// 获取字段 .xxx()
对象名.name()
对象名.age()
for (int i = 0; i < 对象名.books_size(); i++) {
    string book = 对象名.books(i);
    cout << book << " - " << endl;
}
```

然后继续修改demo_proto文件夹下的BUILD文件，添加如下：
```bash
cc_binary(
    name = "test_stu",
    srcs = ["test_stu.cc"],
    deps = [":stu_proto"], 
) 
```
cc_binary用来编译cc文件，cc_proto_binary用来编译proto并产生cc


# python实现读写

生成实现读写的文件test_stu.py，内容如下：
```python
# 设置字段 ： 直接用赋值操作即可
对象名.name = "a"  # required和optional字段都是set
对象名.age = 10
对象名.books.append("xxx") # 如果是列表就是add
对象名.books.append("yyy") # 如果是列表就是add

# 获取字段 .xxx
print(对象名.name)
print(对象名.age)
for book in 对象名.books:
    print(book)
```

然后继续修改demo_proto文件夹下的BUILD文件，添加如下：
```bash
py_binary(
    name = "test_stu_py",
    srcs = ["test_stu_py.py"],
    deps = [":stu_proto_py"], 
) 
```



