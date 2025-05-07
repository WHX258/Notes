#include<iostream>
using namespace std;
int main(){
    int a = 10;
    int b = 3;
    cout<< a/b <<endl;      // 输出3，两个int运算只能是整数，且向下取整(Python // 也是)
                            // 不过如果换一个变量为float结果就是float了

    cout<< 5.0f <<endl;     // 输出时5.0(float)会输出为5

    int a1 = 10;
    int b1 = 3;
    cout<< ++a1 * b1 <<endl;  // 前置递增，先+1后运算 输出33

    int a2 = 10;
    int b2 = 3;
    cout<< a2++ * b2 <<endl;  // 后置递增，先运算后+1 输出30

    // 赋值运算符   : = += -= *= /= %=

    // 运算符优先级 ：1. 加减乘除 2. >> 3. 比较运算符 4. 与或非

    cout<< (a2==b2) <<endl;

    // 三目运算符： 表达式1 ? 表达式2 : 表达式3 (如果表达式1为真，返回表达式2，否则表达式3)
    int x =1; int y = 2; 
    int c = x>y ? x : y;
    cout<< c <<endl;
    // 返回的是变量，可以继续赋值
    (x>y ? x : y) = 100;
    cout<< "y = " << y <<endl; // y = 100
    return 0;
}