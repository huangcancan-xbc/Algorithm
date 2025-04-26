// 力扣：767. 重构字符串
// 链接：https://leetcode.cn/problems/reorganize-string/description/

// 方法：贪心（和 1054. 距离相等的条形码类似）
class Solution
{
public:
    string reorganizeString(string s)
    {
        int hash[26] = { 0 };                   // 哈希表，用于统计每个字母的出现次数（下标 0~25 对应 'a'~'z'）
        int n = s.size();                       // n 为字符串的长度
        int maxcount = 0;                       // maxcount 记录出现最多的字母的出现次数
        char maxchar = ' ';                     // maxchar 记录出现最多的字母

        for (auto x : s)                        // 统计每个字母的出现次数，并找出出现次数最多的字母
        {
            
            if (maxcount < ++hash[x - 'a'])     // 如果当前字母的出现次数大于 maxcount，则更新 maxchar 和 maxcount
            {
                maxchar = x;
                maxcount = hash[x - 'a'];
            }
        }

        if (maxcount > (n + 1) / 2)
        {
            return "";                          // 贪心判断：如果出现最多的字母次数超过 (n + 1) / 2，无法重构，返回空字符串
        }

        string ret(n, ' ');                     // 创建结果字符串，初始全部填充空格，注意一定要进行初始化，否则会出现未定义行为
        int index = 0;                          // 用于填充结果字符串的索引

        for (int i = 0; i < maxcount; i++)      // 将出现次数最多的字母放在偶数索引位置，优先分散出现次数最多的字母
        {
            ret[index] = maxchar;               // 填充字母
            index += 2;                         // 索引递增 2，确保放在偶数位置
        }

        hash[maxchar - 'a'] = 0;                // 将 maxchar 的出现次数清零，避免后续重复填充

        
        for (int i = 0; i < 26; i++)            // 遍历所有字母。填充剩余的字母，尽量分散放置
        {
            for (int j = 0; j < hash[i]; j++)   // 根据每个字母的出现次数进行填充
            {
                
                if (index >= n)
                {
                    index = 1;                  // 如果索引超出字符串长度，从奇数位置开始填充
                }

                ret[index] = 'a' + i;           // 填充当前字母
                index += 2;                     // 索引递增 2，确保奇偶位置交替放置
            }
        }

        return ret;                             // 返回重构后的字符串
    }
};