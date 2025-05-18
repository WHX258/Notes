#include<iostream>
#include <vector>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

int main(){
    // array 的第一维可以不给，自动由编译器推断，但第二个维度必须给定
    int array[][3] = {
        {1,2,3}, 
        {1,2,3}
    };
    int rowSum = accumulate(begin(array[0]), end(array[0]), 0); // 使用accumulate对行快速求和，对列求只能自己手动遍历了
    cout<< array << endl; // c++中，数组名表示地址（常量）。所以这里打印地址，并非内容

    // vector就可以不给行和列数了 （存储在堆上，大小可动态扩展）
    vector<vector<int>> arr = {
    {1, 2, 3},
    {1, 2, 3}
    };
    // vector有.push_back()操作，相当于append()

    // stack / 堆的操作
    stack<int> s;
    s.push(1);
    s.push(2);
    cout << "栈顶元素:（不弹出） " << s.top() << endl; // 输出 2
    s.pop(); // 弹出栈顶元素（无返回值）
    cout << "栈是否为空: " << s.empty() << endl; // 输出 0 (false)
    s.size(); // 返回栈中元素个数

    priority_queue<int> pq; // 大顶堆
    pq.push(3);
    pq.push(1);
    pq.push(4);
    cout << "堆顶元素: " << pq.top() << endl; // 输出 4
    pq.pop();
    cout << "新堆顶: " << pq.top() << endl;   // 输出 3
    
    // deque的操作
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << "队首元素（不弹出）: " << q.front() << endl; // 输出 1
    q.pop();
    cout << "队列大小: " << q.size() << endl;  // 输出 1

    // 冒泡排序:
    // 比较相邻元素，如果后<前，就交换
    // 每次的循环次数-1
    int a[] = {7,6,5,4,3,2,1};

    for (int i = 0; i < size(a) - 1; i++) {
        for (int j = 0; j < size(a) - i - 1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }

    // 自动遍历数组或容器 a 中的每一个元素，并将当前元素的值赋给变量 num
    for (int num : a) {
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}