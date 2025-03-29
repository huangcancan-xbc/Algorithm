// 力扣：646. 最长数对链
// 链接：https://leetcode.cn/problems/maximum-length-of-pair-chain/description/

// 方法：动态规划（Dynamic Programming, DP）
class Solution
{
public:
    int findLongestChain(vector<vector<int>>& pairs)
    {
        sort(pairs.begin(), pairs.end());  // 按照每对数的第一个元素排序
        int n = pairs.size();              // 获取数对的个数
        vector<int> dp(n, 1);              // dp[i] 表示以 pairs[i] 为结尾的最长链的长度，初始化为 1

        int ret = 1;                       // 记录最长数对链的长度，初始化为 1
        for (int i = 1; i < n; i++)        // 遍历每个数对，从第二个数对开始
        {
            for (int j = 0; j < i; j++)    // 对于每个数对 i，遍历 i 之前的所有数对 j
            {
                // 如果 pairs[j][1] < pairs[i][0]，说明可以将 pairs[i] 连接到 pairs[j] 后面
                if (pairs[j][1] < pairs[i][0])
                {
                    // 如果可以连接，则更新 dp[i]，选择最大长度
                    dp[i] = max(dp[j] + 1, dp[i]);  // dp[j] + 1 表示将 pairs[i] 加入到 dp[j] 的链中
                }
            }

            ret = max(ret, dp[i]);          // 更新最长链的长度，取 dp[i] 和当前最长链长度的最大值
        }

        return ret;                         // 返回最长数对链的长度
    }
};