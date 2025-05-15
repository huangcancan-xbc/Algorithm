// 力投：680. 验证回文串 II
// 链接：https://leetcode.cn/problems/valid-palindrome-ii/description/

// 方法：双指针 + 贪心
class Solution
{
public:
    bool is(string& s, int l, int r)
    {
        while (l < r)
        {
            
            if (s[l] != s[r])
            {
                return false;                   // 如果与对应位置字符不等，列表不是回文串
            }
            l++;                                // 左指针后移
            r--;                                // 右指针前移
        }

        return true;                            // 如果没有发现不等，表示是回文串
    }

    bool validPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;     // 左右指针切点
        while (left < right)
        {
            if (s[left] != s[right])            // 如果字符不等，尝试删除一个字符后再判断
            {
                // 删除 left 或 right 之一，看能否成为回文串
                return is(s, left + 1, right) || is(s, left, right - 1);
            }
            left++;                             // 左指针向右移动
            right--;                            // 右指针向左移动
        }

        return true;                            // 如果没有遇到不等的情况，说明已经是回文串
    }
};