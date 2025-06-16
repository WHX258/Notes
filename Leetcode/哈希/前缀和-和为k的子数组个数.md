# 题目
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的`连续`子数组的个数 。

示例 1：
输入：nums = [1,1,1], k = 2；输出：2

示例 2：
输入：nums = [1,2,3], k = 3；输出：2

# 思路: hashmap + 前缀和

计算前缀和，如果 有 曾经计算过的前缀和 = 当前前缀和 - k，则答案次数 + 1 。
曾经计算 联想到 hmap。

`hmap(key = 前缀和; val = 次数)` 

注意：先查找后插入，比如nums=1, k=0。
如果先插入了，后面会查找到 1-0 的次数是1，但是实际上不该出现。

```c++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pre = 0; // 遍历到当下的前缀和
        int ans = 0;
        unordered_map<int,int> hmap;
        hmap[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];

            if (hmap.find(pre - k) != hmap.end()) ans += hmap[pre - k];

            hmap[pre]++;
        }
        return ans;
    }
};
```