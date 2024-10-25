//力扣：904. 水果成篮
//https://leetcode.cn/problems/fruit-into-baskets/description/


//方法一：暴力枚举+哈希表
//时间复杂度：O(n^2)

//算法思路：
//1.枚举每一个可能的起点 i，然后向右扩展，直到遇到超过两种不同类型的水果为止。
//2.使用哈希表（unordered_map）记录当前范围内的水果种类及数量。
//3.每次记录窗口内水果数量的最大值。
//4.最终返回最大的水果数量。
class Solution
{
public:
    int totalFruit(vector<int>& fruits)
    {
        int n = fruits.size();
        int ret = 0;  // 记录最大水果数量

        // 遍历每个起点 i
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> hash;  // 使用哈希表记录水果种类及其数量
            int count = 0;  // 当前窗口水果数量

            // 向右扩展窗口，从位置 i 开始
            for (int j = i; j < n; j++)
            {
                // 增加当前水果的数量
                hash[fruits[j]]++;

                // 如果窗口内的水果种类超过 2 种，退出循环
                if (hash.size() > 2)
                {
                    break;
                }

                // 计算当前窗口内的水果数量
                count = j - i + 1;
                ret = max(ret, count);  // 更新最大水果数量
            }
        }

        return ret;  // 返回最大水果数量
    }
};








//方法二：滑动窗口
//时间复杂度：O(n)

//算法原理：转化问题：找出一个最长的最数组长度，子数组中不超过两种类型的水果

//1. 遍历数组，记录每种水果的数量，使用哈希表记录
//2. 双指针法，左指针和右指针都初始化为0，记录窗口大小
//3. 右指针右移，增加当前水果的数量，如果窗口内的水果种类超过两种，收缩左指针，直到窗口内的水果种类不超过两种
//4. 记录最大水果数量  

class Solution
{
public:

    int totalFruit(vector<int>& fruits)
    {
        // 使用哈希表记录每种水果的数量
        unordered_map<int, int> hash;
        int ret = 0;  // 记录最大的水果数量

        // 双指针法，左指针和右指针都初始化为0
        for (int left = 0, right = 0; right < fruits.size(); right++)
        {
            // 增加当前水果的数量
            hash[fruits[right]]++;

            // 如果窗口内的水果种类超过两种，收缩左指针
            while (hash.size() > 2)
            {
                // 移除左边的水果
                hash[fruits[left]]--;

                // 如果该水果的数量变为0，移除该水果类型
                if (hash[fruits[left]] == 0)
                {
                    hash.erase(fruits[left]);
                }
                left++;  // 左指针右移，缩小窗口
            }

            // 更新最大水果数量
            ret = max(ret, right - left + 1);  // 计算当前窗口大小
        }

        return ret;  
    }
};





// 根据题目范围，做出一点优化，使用数组代替哈希表
// 数组下标表示水果类型，数组值表示该类型水果的数量

class Solution
{
public:

    int totalFruit(vector<int>& fruits)
    {
        // 用于记录每种水果的数量，假设水果类型编号在 0 到 100000 之间
        int hash[100001] = { 0 };
        int ret = 0;  // 记录最大的水果数量

        // 双指针法，左指针和右指针都初始化为0
        for (int left = 0, right = 0, kinds = 0; right < fruits.size(); right++)
        {
            // 如果当前水果类型是新类型
            if (hash[fruits[right]] == 0)
            {
                kinds++;  // 新增一种水果类型，种类数增加
            }

            // 更新当前水果的数量
            hash[fruits[right]]++;

            // 如果窗口内的水果种类超过两种，收缩左指针
            while (kinds > 2)
            {
                // 移除左边的水果
                hash[fruits[left]]--;

                // 如果移除后该水果数量为0，说明这种水果已经不在窗口中
                if (hash[fruits[left]] == 0)
                {
                    kinds--;  // 种类数减少
                }
                left++;  // 左指针右移，缩小窗口
            }

            // 更新最大水果数量
            ret = max(ret, right - left + 1);  // 计算当前窗口大小
        }

        return ret;  // 返回最大水果数量
    }
};
