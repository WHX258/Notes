#include<iostream>
using namespace std;

int main(){
    int a = 3;

    // if
    if (a >= 1) {
        cout<< "hello" <<endl;
        if (a >= 3) {
            cout<< "this" <<endl;  // 到这里就直接返回了，不会继续向下走 >=2 那部分
        } else if (a >= 2) {
            cout<< "super" <<endl;
        } else {
            cout<< "boring"<< endl;
        }
    } else if (a <= 0) {
        cout<< "world" <<endl;
    } else {
        cout<< " !!! " <<endl;
    }

    // switch 
        /*注意1:switch语句中表达式类型只能是整型或者字符型
        注意2:case里如果没有break，那么程序会一直向下执行
        总结:与if语句比，对于多条件判断时，switch的结构清晰，执行效率高，缺点是switch不可以判断区间
        */
    switch (a) {
    case 3:
        cout<< " a = 3 " <<endl;
        break;
    case 2:
        cout<< " a = 2 " <<endl;
        break;
    default:
        cout<< " a 既不是3 也不是2 " <<endl;
        break;
    }

    // while / do while (无论如何会先执行一次)
    while (a) {
        cout<<a<<endl; // 0不会输出，已经被拦在判断外了
        a--;
    }
    cout<< a <<endl;
    do {
        a--;
    } while (a>0);
    cout<< a <<endl;
    
    // for
    for (int i=1;i<=10;i++) {
        break;      // 跳出循环
        continue;   // 跳过本次循环 进入下一次循环
    }

    // goto （无条件跳转语句）
    goto flag;
    cout<< "goto 跳过" <<endl;
    flag:

    return 0;
}