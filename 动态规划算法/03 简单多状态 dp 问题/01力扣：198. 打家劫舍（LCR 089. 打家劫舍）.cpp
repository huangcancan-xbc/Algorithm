// 力扣：198. 打家劫舍（LCR 089. 打家劫舍）
// 链接：https://leetcode.cn/problems/house-robber/description/
        https://leetcode.cn/problems/Gu0c2T/description/


// 方法：动态规划
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();            // 获取房屋数量

        if (n == 0)
        {
            return 0;                   // 如果没有房屋，直接返回0
        }

        // 创建两个数组 f 和 g，用于记录每个位置的状态
        // f[i] 表示到第i间房时，选择打劫第i间房后的最大金额
        // g[i] 表示到第i间房时，不选择打劫第i间房后的最大金额
        vector<int> f(n);
        auto g = f;                     // g 和 f 数组一样，分别表示选择与不选择打劫的状态

        f[0] = nums[0];                 // 如果选择打劫第0间房，获得的金额就是 nums[0]
        // g[0] = 0;                    // 如果不打劫第0间房，金额为0

        // 从第二个房屋开始进行状态转移
        for (int i = 1; i < n; i++)
        {
            f[i] = g[i - 1] + nums[i];  // f[i]：选择打劫第i间房时，最大金额为不打劫上一个房屋的最大金额 + 当前房屋的金额 nums[i]
            g[i] = max(f[i - 1], g[i - 1]);// g[i]：不选择打劫第i间房时，最大金额为选择上一个房屋打劫的最大金额和不选择上一个房屋打劫的最大金额中的较大值
        }

        return max(f[n - 1], g[n - 1]); // 最后返回最大值，表示打劫到最后一间房时能够获得的最大金额
    }
};