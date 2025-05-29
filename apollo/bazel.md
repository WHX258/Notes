# 简介
构建工具（编译用的）

特点：
* 快速可靠，没改的不会再构建
* 多平台（linux/windows/mac）
* 大规模编译保持敏捷性
* 支持多语言且可拓展

# 使用流程

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

BUILD内容如下：
```build
cc_binary(
    name = 'hello'
    srcs = ["pkg.cc"]
)
```