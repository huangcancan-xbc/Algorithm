// 力投：524. 通过删除字母匹配到字典里最长单词
// 链接：https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/description/

// 方法：双指针 + 字符串
class Solution
{
public:
    string findLongestWord(string s, vector<string>& dictionary)
    {
        string ret = "";                                    // 用于存储答案
        
        for (auto x : dictionary)                           // 遍历字典中的每个单词
        {
            int l1 = 0, l2 = 0;                             // l1 比较 s 中字符，l2 比较 x 中字符
            
            while (l1 < s.size() && l2 < x.size())          // 使用双指针完成字符匹配
            {
                if (s[l1] == x[l2])                         // 如果相等，两指针同时移动
                {
                    l1++;
                    l2++;
                }
                else                                        // 如果不等，l1 移动，接着匹配
                {
                    l1++;
                }
            }
            
            if (l2 == x.size())                             // 检查字典单词 x 是否全部匹配完成
            {
                // 若 x 更长，或者长度相同时 x 字典字序在 ret 之前，更新答案
                if (x.size() > ret.size() || (x.size() == ret.size() && x < ret))
                {
                    ret = x;
                }
            }
        }
        return ret;                                         // 返回求解
    }
};