// 力扣：213. 打家劫舍 II（LCR 090. 打家劫舍 II）
// 链接：https://leetcode.cn/problems/house-robber-ii/description/
        https://leetcode.cn/problems/PzWKhm/description/

// 方法：动态规划
class Solution
{
public:
    // 辅助函数 rob1 用于解决一个区间内的打家劫舍问题，left 和 right 为该区间的左右边界，nums 为房屋的金额数组
    int rob1(vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return 0;                       // 如果 left > right，说明区间没有房屋可打劫，返回0
        }

        int n = nums.size();                // 获取房屋数量

        // 创建两个数组 f 和 g，用于记录每个位置的状态
        // f[i] 表示打劫到第i间房时，选择打劫第i间房后的最大金额
        // g[i] 表示打劫到第i间房时，不选择打劫第i间房后的最大金额
        vector<int> f(n);
        auto g = f;                         // g 和 f 数组一样，表示选择与不选择打劫的状态

        f[left] = nums[left];               // 如果选择打劫第left间房，获得的金额就是 nums[left]

        // 从第二个房屋开始进行状态转移
        for (int i = left + 1; i <= right; i++)
        {
            f[i] = g[i - 1] + nums[i];      // f[i]：选择打劫第i间房时，最大金额为不打劫上一个房屋的最大金额 + 当前房屋的金额 nums[i]
            g[i] = max(f[i - 1], g[i - 1]); // g[i]：不选择打劫第i间房时，最大金额为选择上一个房屋打劫的最大金额和不选择上一个房屋打劫的最大金额中的较大值
        }

        return max(f[right], g[right]);     // 返回最终的最大值，即打劫到第right间房时的最大金额
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        //if (n == 1)
        //{
        //    return nums[0];                 // 特判：如果只有一间房屋，只能打劫这一间
        //}

        // 计算两种情况：1. 不打劫第一个房屋；2. 不打劫最后一个房屋，使用 rob1 函数分别解决这两个子问题，并取最大值
        return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
    }
};


// 不使用辅助函数 rob1，直接使用两个数组 f 和 g 记录状态：
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];                 // 特判：如果只有一间房屋，只能打劫这一间
        }

        // 当 n == 2 时，f[1] = nums[1] 会越界，因为在 n == 2 的情况下，nums 只有 2 个元素，需要考虑到这个边界条件！
        if (n == 2)
        {
            return max(nums[0], nums[1]);   // 特判：如果只有两间房屋，取最大值
        }

        // 第一种情况：不打劫第一个房屋，考虑房屋 [1, n-1]
        vector<int> f(n, 0);                // f[i] 表示打劫到第i间房屋时的最大金额
        f[0] = 0;                           // 不打劫第1间房屋
        f[1] = nums[1];                     // 从第二间房屋开始打劫
        for (int i = 2; i < n; i++)
        {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }

        // 第二种情况：打劫第一个房屋，不打劫最后一个房屋，考虑房屋 [0, n-2]
        vector<int> g(n, 0);                // g[i] 表示打劫到第i间房屋时的最大金额
        g[0] = nums[0];                     // 从第1间房屋开始打劫
        g[1] = nums[0];                     // 不能打劫第二个房屋
        for (int i = 2; i < n - 1; i++)
        {
            g[i] = max(g[i - 1], g[i - 2] + nums[i]);
        }

        return max(f[n - 1], g[n - 2]);     // 返回两种情况的最大值
    }
};