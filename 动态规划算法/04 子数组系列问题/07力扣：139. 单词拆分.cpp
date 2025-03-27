// 力扣：139. 单词拆分
// 链接：https://leetcode.cn/problems/word-break/description/

// 方法：动态规划
class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        // 优化：使用哈希集合存储字典中的单词，提高查询效率
        unordered_set<string> hash;
        for (auto& word : wordDict)
        {
            hash.insert(word);
        }

        int n = s.size();
        
        vector<bool> dp(n + 1, false);      // dp[i] 表示字符串 s[0...i-1] 是否可以被拆分成字典中的单词
        dp[0] = true;                       // 保证后续填表的正确性：空字符串是可以被拆分的

        for (int i = 1; i <= n; i++)        // 遍历字符串 s 的每个位置 i
        {
            for (int j = i; j >= 1; j--)    // 从 i 向后遍历检查每一个可能的前缀 j（找最后一个单词的起始位置）
            {
                // 如果 dp[j-1] 为 true 且 s[j...i] 是字典中的单词，则 dp[i] 为 true
                if (dp[j - 1] && hash.count(s.substr(j - 1, i - j + 1)))
                {
                    dp[i] = true;
                    break;                  // 一旦找到有效的拆分，立即退出内层循环
                }
            }
        }

        return dp[n];                       // 返回 dp[n]，即字符串 s 是否可以拆分成字典中的单词
    }
};