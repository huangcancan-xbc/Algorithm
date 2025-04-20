// 力扣：45. 跳跃游戏 II
// 链接：https://leetcode.cn/problems/jump-game-ii/description/

// 方法一：贪心（类似层序遍历）
class Solution
{
public:
    int jump(vector<int>& nums)
    {
        // 当前跳跃的区间 [left, right]，记录当前区间内能跳到的最远位置，跳跃次数
        int n = nums.size(), left = 0, right = 0, maxpos = 0, ret = 0;

        while (left <= right)                       // 当当前区间 [left, right] 内还可以继续跳跃时，执行循环
        {
            if (maxpos >= n - 1)
            {
                return ret;                         // 如果当前的最远可达位置已经覆盖了终点，返回跳跃次数
            }

            for (int i = left; i <= right; i++)
            {
                maxpos = max(maxpos, nums[i] + i);  // 在当前区间内寻找能跳到的最远位置
            }

            // 更新下一次跳跃的区间，左边界设为当前区间的右边界 +1，右边界设为能跳到的最远位置
            left = right + 1;
            right = maxpos;
            ret++;                                  // 完成一次跳跃
        }

        return -1;                                  // 如果无法跳到终点，返回 -1（题目保证有解，这里其实不会触发）
    }
};



// 方法二：动态规划
class Solution
{
public:
    int jump(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);                 // dp[i] 表示跳到第 i 个位置所需的最少跳跃次数
        dp[0] = 0;                                  // 起点跳跃次数为 0

        for (int i = 0; i < n; i++)                 // 遍历每一个位置 i
        {
            // 从位置 i 出发，跳跃 nums[i] 的范围
            for (int j = 1; j <= nums[i] && i + j < n; j++)
            {
                dp[i + j] = min(dp[i + j], dp[i] + 1);  // 更新跳到 i+j 位置的最小跳跃次数
            }
        }

        return dp[n - 1];                           // 返回跳到最后一个位置的最小跳跃次数
    }
};