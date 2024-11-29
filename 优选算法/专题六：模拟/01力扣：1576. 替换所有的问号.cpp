//力扣：1576. 替换所有的问号
//https://leetcode.cn/problems/replace-all-s-to-avoid-consecutive-repeating-characters/description/


//方法：模拟
// 时间复杂度：O(n)
//算法原理：
//纯模拟。从前往后遍历整个字符串，找到问号之后，就⽤ a ~z 的每⼀个字符去尝试替换即可。
class Solution
{
public:
    string modifyString(string s)
    {
        int n = s.size();                            // 获取字符串的长度

        for (int i = 0; i < n; i++)                  // 遍历字符串的每个字符
        {
            if (s[i] == '?')                         // 当遇到 '?' 字符时
            {
                for (char ch = 'a'; ch <= 'z'; ch++) // 从 'a' 到 'z' 逐个尝试填充字符
                {
                    // 确保当前字符与前后字符不相同
                    if ((i == 0 || ch != s[i - 1]) && (i == n - 1 || ch != s[i + 1]))
                    {
                        s[i] = ch;                   // 替换 '?' 为合适字符
                        break;                       // 替换完成后跳出循环
                    }
                }
            }
        }

        return s;                                    // 返回修改后的字符串
    }
};