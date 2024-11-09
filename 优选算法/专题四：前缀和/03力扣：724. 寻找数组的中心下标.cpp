// 力扣：724. 寻找数组的中心下标
// https://leetcode.cn/problems/find-pivot-index/description/


// 方法一：暴力法
// 时间复杂度：O(n^2)
// 算法原理：
// 遍历数组，对于每个元素，计算其左右两边元素的和。
// 如果两边元素的和相等，则返回该元素的下标。

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) 
        {
            int leftSum = 0;
            int rightSum = 0;

            // 计算左侧元素和
            for (int j = 0; j < i; j++) 
            {
                leftSum += nums[j];
            }

            // 计算右侧元素和
            for (int j = i + 1; j < n; j++) 
            {
                rightSum += nums[j];
            }

            // 比较左右和，找到中心下标
            if (leftSum == rightSum) 
            {
                return i;
            }
        }

        return -1; // 未找到则返回 -1
    }
};


// 方法二：前缀和法
// 时间复杂度：O(n)

//区间划分：     [0,i - 1]  i  [i,n - 1]
//f:前缀和数组(f(x))，f[i]表示 [0,i - 1] 区间所有元素的和
//g:前缀和数组(g(x))，g[i]表示 [i + 1,n - 1] 区间所有元素的和
//细节问题：
//1.f(0) = 0,g(n - 1) = 0
//2.f:从左向右，g:从右向左

// 算法原理：
// 利用前缀和优化计算左右子数组之和。
// 通过构建左前缀和数组 (f) 和右前缀和数组 (g) 来快速计算每个元素的左右和。
// 若 f[i] == g[i]，则找到了中心下标。

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 0);            // 前缀和数组 f: [0,i - 1] 的和
        vector<int> g(n, 0);            // 前缀和数组 g: [i + 1,n - 1] 的和

        // 计算左前缀和数组 f
        for (int i = 1; i < n; i++) 
        {
            f[i] = f[i - 1] + nums[i - 1];
        }

        // 计算右前缀和数组 g
        for (int i = n - 2; i >= 0; i--) 
        {
            g[i] = g[i + 1] + nums[i + 1];
        }

        // 寻找符合条件的中心下标
        for (int i = 0; i < n; i++) 
        {
            if (f[i] == g[i]) 
            {
                return i;               // 返回找到的中心下标
            }
        }

        return -1;                      // 若无满足条件的下标，返回 -1
    }
};
