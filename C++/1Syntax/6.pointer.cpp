// 定义：把a的地址赋予指针p 
// int * p = &a;
// 使用：指针前面加*表示解引用，找到所指内存中的数据
// *p = 1000; 结果把a修改为1000

#include<iostream>
using namespace std;
void BubbleSort(int * arr, int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int a = 1;
    int * p = &a;
    
    *p = 2; // 用指针修改a
    cout<< a <<endl;

    // 指针所占内存 64位操作系统为 8
    cout<< sizeof(p) <<endl;
    
    // 空指针（指向0）：
    // 用于给指针初始化
    // 0~255 内存不可访问
    int * p2 = NULL;
    cout<< p2 <<endl; // 输出0

    // 野指针 一种错误，指针指向了非法空间



    // const修饰*p：指针指向的数值不可修改，但可以改变指针的指向
    int c = 1; int d = 2;
    const int * p3 = &c;
    // *p3 = 3; // 错误，不可修改
    p3 = &d;
    // const修饰p：指针指向的数值可以改，但不能改变指针朝向
    int * const p4 = &c;
    *p4 = 4;
    // p4 = &d; // 错误
    cout<< c <<endl; // 4
    // 两个const，指向位置和指向位置的内容都改不了
    const int * const p5 = &c;




    // 用指针实现冒泡排序
    int arr[] = {5,1,2,3,4,6,7,8,9,0};
    BubbleSort(arr, 10);
    for (int num : arr) {
        cout<< num <<endl;
    }
    
    return 0;
}