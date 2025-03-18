// 力扣：LCR 166. 珠宝的最高价值(原剑指offer 47.礼物的最大价值)
// 链接：https://leetcode.cn/problems/li-wu-de-zui-da-jie-zhi-lcof/description/

// 方法：动态规划
class Solution
{
public:
    int jewelleryValue(vector<vector<int>>& frame)
    {
        int m = frame.size(), n = frame[0].size();

        // 创建一个 (m+1)x(n+1) 的 DP 数组，初始化为0，dp[i][j] 表示从 (0,0) 到 (i-1,j-1) 的最大价值
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 状态转移：dp[i][j] 由左边 dp[i][j-1] 和上边 dp[i-1][j] 两个位置的最大值加上当前的价值 frame[i-1][j-1] 得到
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];
            }
        }

        return dp[m][n];                // 返回右下角的位置，即 (m,n) 位置的最大价值
    }
};
