// 数据类型 名称(数据类型 变量名) {
//     return 变量; // 类型对应于第一行声明的类型
// }

// 形参变化不影响实参（实际上是两块内存），但利用引用传递可以实现操作原变量
// 如void swap(int &a, int &b) {}

// 函数有无参数/有无返回值均可实现

// #include<iostream>
// using namespace std;

// // 可以在文件前面只声明函数，先写主函数，再把定义函数写后面
// int max(int a, int b);

// int main() {

//     return 0;
// }

// int max(int a, int b) {
//     return a>b ? a:b;
// }

// 头文件中写声明，源文件中写定义
// 源文件中#include "xxx.h", 头文件中#include<>需要的库
// 自己的程序中只需要#include "xxx.h"即可

#include "5.Function_swap.h"
int main() {
    int a = 10; int b = 20;
    swap(a,b);
    return 0;
}