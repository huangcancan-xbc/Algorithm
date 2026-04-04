// 力扣：125. 验证回文串
// 链接：https://leetcode.cn/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150

// 方法一：字符串硬模拟 + 转换
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string ss;
        for (auto x : s)
        {
            if (x >= 'A' && x <= 'Z')
            {
                ss += x + 32;
            }
            else if ((x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
            {
                ss += x;
            }
        }

        string sss = ss;
        reverse(sss.begin(), sss.end());
        return sss == ss;
    }
};




// 方法二：使用库函数
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string ss;
        for (auto x : s)
        {
            if (x >= 'A' && x <= 'Z')
            {
                ss += tolower(x);
            }
            else if (x >= 'a' && x <= 'z')
            {
                ss += x;
            }
            else if (x >= '0' && x <= '9')
            {
                ss += x;
            }
        }

        string sss = ss;
        reverse(sss.begin(), sss.end());
        return sss == ss;
    }
};




// 方法三：纯手动模拟（双指针）
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !isalnum(s[i]))
            {
                i++;        // 左边跳过无效字符
            }
            while (i < j && !isalnum(s[j]))
            {
                j--;        // 右边跳过无效字符
            }

            char left = s[i], right = s[j];

            if (left >= 'A' && left <= 'Z')
            {
                left += 32;
            }
            if (right >= 'A' && right <= 'Z')
            {
                right += 32;
            }

            if (left != right)
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};