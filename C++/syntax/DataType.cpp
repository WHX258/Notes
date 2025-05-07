//  单行注释

/*
    多行注释
*/
#include <iostream>
#include<string>
using namespace std;
int main(){
    // 变量
    int a = 1;
    // 常量(不可修改)
    #define DAY 7               // 后无分号
    const int b = 2;
    cout << "hello c++, a, DAY, b = " << a <<", "<< DAY <<", "<< b << endl;
  
    // sizeof()                 // 计算数据类型占用内存

    double x = 3.1415926535;
    float y = 3.1415926535f;    // 小数默认是double，小数后加个f可以变成float类型
    float z = 3E2;              // 3e2
    cout <<  x <<", "<< y <<", "<< z << endl;

    char ch = 'a';              // 字符型(char)：一定是单引号，且只能有一个字符，实际存储的是对应的askii码
    cout<<(int)ch<< endl;       // a -- 97; A -- 65
                                // 转义字符 \t 表示制表

    char st[] = "abcd";         // 字符串: 一定是双引号，这是第一种风格（char 变量名[] = "xx"）
    string str = "abcde";       // 这是第二种风格（string 变量名 = "xx"）,需要头文件#include<string>
    cout<<str<<endl;

    // 数据输入输出 cin >> and cout <<
    int d = 0;                  // 类似的, float/ char/ string/ bool都可以这么操作
    cout<<"give a number for d"<<endl;
    cin >> d;
    cout<<"d="<<d<<endl;

    return 0;
}

