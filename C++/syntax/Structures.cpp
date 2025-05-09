
#include<iostream>
using namespace std;
struct students
{
    int data;
};
// 结构体可以嵌套结构体
struct teachers
{
    int data;
    students stu;
};

// 值传递
void printstudent(students stu){
    stu.data = 28;
    cout <<"值传递"<< stu.data << endl;
}

//地址传递 要用指针来接受地址
//const 可以修饰students, 这样*stu的内容就只读不可写了
void printstudent2(students *stu){
    stu -> data = 28; // structure里指针用->来改数值
    cout <<"地址传递"<< stu->data << endl;
}


int main() {
    
    // 两种声明方法
    students st1;
    st1.data = 1;
    students st2 = {2};

    // 结构体数组
    students stuArray[] = {
        {1},
        {2},
        {3}
    };
    stuArray[2].data = 4;

    // 结构体指针 指针类型和指向的内容的类型一致
    students * p = &st1;
    // 可以用指针->直接来访问指向的内容
    cout << p -> data << endl;
    
    // 结构体嵌套结构体
    teachers t = {1, st1};
    cout << t.stu.data << endl;

    // 结构体做函数参数
    printstudent(st1);
    cout<<"修改后没变还是"<< st1.data << endl;
    printstudent2(&st1);
    cout<<"地址传递修改后变了"<< st1.data << endl;

    return 0;
}