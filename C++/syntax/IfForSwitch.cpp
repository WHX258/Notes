#include<iostream>
using namespace std;

int main(){
    int a = 3;

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

    for (int i=1;i<=10;i++) {
        break;
        continue;
    }

    while (a) {
        a--;
    }
    return 0;
}