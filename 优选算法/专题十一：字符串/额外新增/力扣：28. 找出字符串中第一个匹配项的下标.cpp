// 力扣：28. 找出字符串中第一个匹配项的下标
// 链接：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/?envType=study-plan-v2&envId=top-interview-150

// 方法一：直接用库函数
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        return haystack.find(needle);
    }
};




// 方法二：暴力美学
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++)
        {
            int j = 0;

            // 逐个字符比较
            while (j < m && haystack[i + j] == needle[j])
            {
                j++;
            }

            // 如果 j 走到头了，说明全匹配上了
            if (j == m)
            {
                return i;
            }
        }

        return -1;
    }
};