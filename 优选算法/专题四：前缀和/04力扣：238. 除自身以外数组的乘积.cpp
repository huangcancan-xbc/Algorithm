//力扣：238. 除自身以外数组的乘积
//https://leetcode.cn/problems/product-of-array-except-self/description/


//方法一：暴力法
//时间复杂度：O(n^2)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int fsum = 1, gsum = 1;                 //初始化 fsum 和 gsum 为1，避免乘积为0

            //计算 i 左侧所有元素的乘积
            for (int j = 0; j < i; j++)
            {
                fsum *= nums[j];
            }

            //计算 i 右侧所有元素的乘积
            for (int k = i + 1; k < n; k++)
            {
                gsum *= nums[k];
            }

            ans[i] = fsum * gsum;                   //计算除 i 位置外的乘积
        }

        return ans;
    }
};







//方法二：前缀积
//时间复杂度：O(n)

//算法原理：
// · 注意题⽬的要求，不能使⽤除法，并且要在 O(N) 的时间复杂度内完成该题。那么我们就不能使⽤暴⼒的解法，以及求出整个数组的乘积，然后除以单个元素的⽅法。
// · 继续分析，根据题意，对于每⼀个位置的最终结果 ret[i] ，它是由两部分组成的：
//        i.nums[0] * nums[1] * nums[2] * ... * nums[i - 1]
//        ii.nums[i + 1] * nums[i + 2] * ... * nums[n - 1]
// · 于是，我们可以利⽤前缀和的思想，使⽤两个数组 f 和 g，分别处理出来两个信息：
//        i.post 表⽰：i 位置之前的所有元素，即[0, i - 1] 区间内所有元素的前缀乘积，
//        ii.suf 表⽰： i 位置之后的所有元素，即[i + 1, n - 1] 区间内所有元素的后缀乘积
// · 然后再处理最终结果。

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();                               // 获取数组大小
        vector<int> f(n), g(n);                            // 前缀乘积数组f和后缀乘积数组g
        vector<int> ans(n);                                // 存放结果的数组

        f[0] = g[n - 1] = 1;                               // 初始化边界条件，避免乘积为0
        for (int i = 1; i < n; i++)                        // 从1到n-1计算前缀乘积
        {
            f[i] = f[i - 1] * nums[i - 1];                 // f[i]为前缀乘积，排除当前元素
        }

        for (int i = n - 2; i >= 0; i--)                   // 从n-2到0计算后缀乘积
        {
            g[i] = g[i + 1] * nums[i + 1];                 // g[i]为后缀乘积，排除当前元素
        }

        for (int i = 0; i < n; i++)                        // 组合前缀和后缀乘积得到最终结果
        {
            ans[i] = f[i] * g[i];                          // ans[i]即为除自身外的乘积
        }

        return ans;                                        // 返回最终结果
    }
};






class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();                               // 获取数组大小
        vector<int> f(n, 1), g(n, 1);                      // 初始化为1，避免乘积为0
        vector<int> ans(n);                                // 存放结果的数组

        for (int i = 1; i < n; ++i)                        // 从1到n-1计算前缀乘积
        {
            f[i] = f[i - 1] * nums[i - 1];                 // 前缀乘积排除当前元素
        }

        for (int i = n - 2; i >= 0; --i)                   // 从n-2到0计算后缀乘积
        {
            g[i] = g[i + 1] * nums[i + 1];                 // 后缀乘积排除当前元素
        }

        for (int i = 0; i < n; ++i)
        {
            ans[i] = f[i] * g[i];                          // 组合前缀和后缀得到最终结果
        }

        return ans;                                        // 返回结果
    }
};
