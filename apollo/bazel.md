# 简介
构建工具（编译用的）

特点：
* 快速可靠，没改的不会再构建
* 多平台（linux/windows/mac）
* 大规模编译保持敏捷性
* 支持多语言且可拓展

# 使用流程 
## c++
1. 创建目录
```
project1
│   WORKSPACE
│
└───PKG
│   │   BUILD
│   │   pkg.cc
│   │   pkg.h
|
```

2. 编写BUILD内容：

```bash
cc_binary(
    name = 'hello'      # 生成的可执行文件(.so)名称
    srcs = ["pkg.cc"]   # 源码文件
)
```

3. 进入project文件夹下编译：
```bash
bazel build //PKG/...
```
//表示当前目录下

如果只编译一个文件（用 `:` ）：
```bash
bazel build //PKG:hello
```

编译后会在project下生成一些文件夹，如bazel-bin等

4. 执行
进入bazel-bin，启动刚才生成的可执行文件：
```bash
./bazel-bin/PKG/hello
```
既编译又执行 (某个文件)：
```bash
bazel run PKG:hello
```


## python

目录、编译、运行同上；

BUILD添加：
```bash
py_binary(
    name = 'hello_py'      # 生成的可执行文件(.so)名称
    srcs = ["pkg.py"]     # 源码文件
)
```

# 同包下库依赖

1. 创建目录
```
project2
│   WORKSPACE
│
└───demo_lib
│   │   BUILD
│   │   demo_lib.cc
│   │   demo_lib.h
│   │   helloworld.cc
|
```
2. 编写BUILD内容（被引用的是`_library`）：
```bash
cc_library(
    name = 'demo_libs'        # 生成的可执行文件(.so)名称
    srcs = ["demo_lib.cc"]   # 源码文件
    hdrs = ["demo_lib.h"]    # 头文件
)
```
3. 编译、运行同上

4. 编写引用demo_lib.h中函数的文件 (helloworld.cc)：
```c++
#include<demo_lib.h>
...
...
```

5. 继续添加BUILD，依赖项抄写`cc_library`中的`name`项，`:`表示当前目录下:
```bash
cc_binary(
    name = 'helloworld'      # 生成的可执行文件(.so)名称
    srcs = ["helloworld.cc"]   # 源码文件
    deps = [":demo_libs"]     # 依赖项 
)
```

6. 编译、运行同上

# 跨包库依赖 (注意被引用lib的可见性)
目录如下，在demo_lib2中引用demo_lib的内容
```
project2
│   WORKSPACE
│
└───demo_lib
│   │   BUILD
│   │   demo_lib.cc
│   │   demo_lib.h
│   │   helloworld.cc
|
└───demo_lib2
│   │   BUILD
│   │   helloworld.cc
|
```

编写BUILD内容: 
```bash
cc_binary(
    name = 'helloworld'      # 生成的可执行文件(.so)名称
    srcs = ["helloworld.cc"]   # 源码文件
    deps = ["//demo_lib:demo_libs"]     # 依赖项 
)
```

修改demo_lib的BUILD，在文件开头添加如下命令，表示这个包对所有对象开放:
```bash
package(
    default_visibility = [
        "//visibility:public"
    ],
)
```
或者给cc_library添加visibility单独开放给lib2：
```bash
cc_library(
    name = 'demo_libs'        # 生成的可执行文件(.so)名称
    srcs = ["demo_lib.cc"]   # 源码文件
    hdrs = ["demo_lib.h"]    # 头文件
    visibility = ["//demo_lib2:__pkg__"]
)
