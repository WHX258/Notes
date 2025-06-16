# 题目
请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。

实现 LRUCache 类：

LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存

int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。

void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。

函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

示例：

输入

["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]

输出

[null, null, null, 1, null, -1, null, -1, 3, 4]

解释

    LRUCache lRUCache = new LRUCache(2);
    lRUCache.put(1, 1); // 缓存是 {1=1}
    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
    lRUCache.get(1);    // 返回 1
    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    lRUCache.get(2);    // 返回 -1 (未找到)
    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    lRUCache.get(1);    // 返回 -1 (未找到)
    lRUCache.get(3);    // 返回 3
    lRUCache.get(4);    // 返回 4


# 思路

要求O(1) -- 哈希表 unordered_map

查找get：哈希表 unordered_map

不存在返回-1，存在把当前节点移动到队首（为了put逐出最久未使用）

加入put：类似于队列的链表（容量为capacity），

如果大于容量，删除队尾元素，同时删除hashmap对应的key-val（可以通过在node中记录key来找到删除位置）

如果有一样的key，更新节点数值，删除节点，把要更新节点放队首

```c++

// struct结尾也有分号
struct Node {
    int key, val;
    Node* pre;
    Node* next;

    Node (): key(0), val(0), pre(nullptr), next(nullptr) {}
    Node (int _key, int _val): key(_key), val(_val), pre(nullptr), next(nullptr) {}
};

class LRUCache {
    int capacity;
    int cur_cap = 0;
    // 只能这样写，全局先声明，然后在构造函数里面再初始化，并且构造函数里面的函数不能被其他函数访问
    Node* head; 
    Node* tail;
    unordered_map <int, Node*> hmap;

public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (hmap.find(key) != hmap.end()) {
            Node* removed = hmap[key];
            remove(removed);
            AddNodeToHead(removed);
            return removed->val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        // 不要写if (hmap[key]),因为哈希表没有key会自动添加
        if (hmap.find(key) != hmap.end()) { 
            Node* node = hmap[key];
            node->val = value;
            
            remove(node);
            AddNodeToHead(node);
            
        } else {
            
            if (cur_cap >= capacity) {

                hmap.erase(tail->pre->key);
                remove(tail->pre);
                Node* node = new Node(key, value);
                AddNodeToHead(node);
                hmap[key] = node;

            } else {

                Node* node = new Node(key, value);
                AddNodeToHead(node);
                hmap[key] = node;
                cur_cap++;

            }
        }
    }

    void AddNodeToHead (Node* node) {
        // 必须先修改node，再改其他的
        node->pre = head;
        node->next = head->next;

        head->next->pre = node;
        head->next = node;
    }
    // 前面连接后面
    void remove(Node* removed){
        removed->pre->next = removed->next;
        removed->next->pre = removed->pre;
    }
};

```
