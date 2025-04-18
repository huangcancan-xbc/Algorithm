// 力扣：409. 最长回文串
// 链接：https://leetcode.cn/problems/longest-palindrome/description/

// 方法：贪心
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int hash[127] = { 0 };          // 创建一个大小为 127 的哈希表（ASCII 范围内的字符个数），用于记录每个字符出现的次数
        for (auto x : s)
        {
            hash[x]++;                  // 遍历字符串 s，统计每个字符的出现次数
        }

        int ret = 0;                    // 计算最大回文长度

        // 遍历哈希表中的字符出现次数
        for (auto x : hash)
        {
            // 巧妙运用奇数除以2舍去小数点后面的部分，可以得到每个字符形成回文串的有效个数
            ret += (x / 2 * 2);
        }

        // 如果有字符的出现次数是奇数，说明可以在回文串中间放置一个字符，也就是说回文串长度可以加 1
        return ret < s.size() ? ret + 1 : ret;
    }
};