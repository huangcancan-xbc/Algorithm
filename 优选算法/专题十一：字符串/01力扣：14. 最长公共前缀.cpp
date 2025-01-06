//力扣：14. 最长公共前缀
//链接：https://leetcode.cn/problems/longest-common-prefix/description/


//方法一：两两比较
//时间复杂度：O（nm)

//思路：
//1. 先取第一个字符串的第一个字符，与其他字符串依次进行比较
//2. 如果相同且不超过较短字符串的长度，则继续比较下一个字符
//3. 如果不同，则返回当前字符串的前缀
//4. 直到所有字符串都比较完，则返回最长公共前缀
class Solution 
{
public:
    string common_prefix(string& s1, string& s2)
    {
        int i = 0;                                      // 记录字符串相同的长度
        while (s1[i] == s2[i] && i < min(s1.size(), s2.size()))//相等且不越界
        {
            i++;                                        //增加长度，继续比较
        }

        return s1.substr(0, i);                         // 截取前缀
    }

    string longestCommonPrefix(vector<string>& strs)
    {
        string ret = strs[0];                           // 取第一个字符串作为初始值
        for (int i = 1; i < strs.size(); i++)           // 依次与其他字符串比较
        {
            ret = common_prefix(ret, strs[i]);          // 传要比较的两个字符
        }

        return ret;
    }
};

class Solution 
{
public:
    string common_prefix(string& s1, string& s2)
    {
        int i = 0;
        string ret;                                     // 记录公共前缀（答案）
        while (s1[i] == s2[i] && i < min(s1.size(), s2.size()))
        {
            ret += s1[i];                               // 将相同的字符添加到公共前缀中
            i++;
        }

        return ret;
    }

    string longestCommonPrefix(vector<string>& strs)
    {
        string ret = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            ret = common_prefix(ret, strs[i]);
        }

        return ret;
    }
};




//方法二：统一比较（纵向扫描）
//时间复杂度：O(nm)

//思路：
//1. 取第一个字符串的第一个字符，与其他字符串依次进行比较
//2. 如果相同且不超过较短字符串的长度，则继续比较下一个字符
//3. 如果不同，则返回当前字符串的前缀
//4. 直到所有字符串都比较完，则返回最长公共前缀
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        for (int i = 0; i < strs[0].size(); i++)        //第一个字符串
        {
            char temp = strs[0][i];                     //取第一个字符
            for (int j = 1; j < strs.size(); j++)       //其他字符串
            {
                if (i == strs[j].size() || strs[j][i] != temp)  // 越界或不相同，返回前缀
                {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];                                 // 所有字符串都相同，返回第一个字符串
    }
};