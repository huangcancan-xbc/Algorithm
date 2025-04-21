// 力扣：738. 单调递增的数字
// 链接：https://leetcode.cn/problems/monotone-increasing-digits/description/

// 方法一：暴力枚举（超时）
class Solution
{
public:
    bool is(int x)
    {
        if (x < 10)
        {
            return true;                    // 如果是个位数，则直接返回true
        }

        string s = to_string(x);            // 转换为字符串
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] < s[i - 1])
            {
                return false;               // 遍历字符串，发现有逆序，则返回false
            }
        }

        return true;                        // 遍历完毕没有发现逆序，则返回true
    }

    int monotoneIncreasingDigits(int n)
    {
        for (int i = n; i >= 0; i--)        // 暴力枚举0到n-1是否满足条件，注意是从大到小枚举
        {
            if (is(i))
            {
                return i;                   // 如果找到了满足条件的数，则返回
            }
        }

        return 0;
    }
};

// 数学判断：
class Solution
{
public:
    bool is(int x)
    {
        if (x < 10)
        {
            return true;                    // 如果是个位数，则直接返回true
        }

        int prev = x % 10;                  // 记录个位数
        x /= 10;                            // 去掉个位数

        while (x > 0)
        {
            int cur = x % 10;               // 当前最低位，即当前位
            if (cur > prev)                 // 检查当前位是否大于下一位
            {
                return false;               // 如果发现当前位大于下一位，则返回false
            }
            prev = cur;                     // 更新prev为当前位
            x /= 10;                        // 去掉当前最低位，继续循环
        }

        return true;                        // 循环结束没有发现不满足条件的情况，返回true
    }

    int monotoneIncreasingDigits(int n)
    {
        for (int i = n; i >= 0; i--)
        {
            if (is(i))
            {
                return i;
            }
        }

        return 0;
    }
};



// 方法二：贪心

//1. 为了方便处理数中的每一位数字，可以先将数转换成字符串
//2. 从左往右扫描，找到第一个递减的位置
//3. 从这个位置向前推，推到相同区域的最左端
//4. 将该点的数字减一，并将右边所有数字都置为9
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string s = to_string(n);                // 转换为字符串
        int m = s.size(), i = 0;                // 计算字符串长度和定义当前扫描位置

        while (i + 1 < m && s[i] <= s[i + 1])
        {
            i++;                                // 找到第一个递减的位置
        }

        if (i == m - 1)
        {
            return stoi(s);                     // 特判：如果这个数已经是单调递增的，则直接返回
        }

        while (i - 1 >= 0 && s[i] == s[i - 1])
        {
            i--;                                // 推到相同区域的最左端（例：12223，找到第一个2的位置）
        }

        s[i]--;                                 // 将该点的数字减一
        for (int j = i + 1; j < m; j++)
        {
            s[j] = '9';                         // 将右边所有数字都置为9
        }

        return stoi(s);                         // 转换回数字并返回
    }
};