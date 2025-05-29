# 简介
构建工具（编译用的）

特点：
* 快速可靠，没改的不会再构建
* 多平台（linux/windows/mac）
* 大规模编译保持敏捷性
* 支持多语言且可拓展

# 使用流程

1. 创建目录
```
project
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
    name = 'hello'      # 生成的可执行文件名称
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



