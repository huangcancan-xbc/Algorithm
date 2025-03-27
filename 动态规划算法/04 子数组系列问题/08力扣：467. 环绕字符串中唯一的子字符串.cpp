// 力扣：467. 环绕字符串中唯一的子字符串
// 链接：https://leetcode.cn/problems/unique-substrings-in-wraparound-string/description/

// 方法：动态规划
class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        int n = s.size();                   // 获取字符串的长度
        vector<int> dp(n, 1);               // dp[i] 表示以 s[i] 结尾的子字符串的不同个数

        // 动态规划，计算每个位置的 dp[i]，表示以 s[i] 结尾的最长有效子串长度
        for (int i = 1; i < n; i++)
        {
            // 判断当前字符是否与前一个字符形成有效的环绕字母关系，例如，'a' 和 'b'，'y' 和 'z'，或者 'z' 和 'a' 
            if (s[i - 1] + 1 == s[i] || (s[i - 1] == 'z' && s[i] == 'a'))
            {
                dp[i] += dp[i - 1];         // 当前字符与前一个字符连续，则 dp[i] 增加连续子串的个数
            }
        }

        // 用 hash 数组来记录每个字符的最大子字符串数量
        int hash[26] = { 0 };               // 用于存储每个字符作为子串结尾的最大子串个数
        for (int i = 0; i < n; i++)
        {
            hash[s[i] - 'a'] = max(hash[s[i] - 'a'], dp[i]);    // 更新每个字符的最大值，找到每个字符的唯一子串数最大的那一个
        }

        // 最终结果是所有字符对应的唯一子串的总数
        int sum = 0;
        for (auto x : hash)
        {
            sum += x;                       // 求所有字符作为子串结尾时的最大子串数之和
        }

        return sum;                         // 返回总的唯一子字符串数
    }
};