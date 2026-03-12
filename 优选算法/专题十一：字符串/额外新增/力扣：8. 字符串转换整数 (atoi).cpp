// 力扣：8. 字符串转换整数 (atoi)
// 链接：https://leetcode.cn/problems/string-to-integer-atoi/description/

// 方法：模拟字符串处理
class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        int n = s.size();

        // 1. 去掉前导空格
        while (i < n && s[i] == ' ')
        {
            i++;
        }

        // 2. 处理符号
        int fu = 1; // 默认是正数
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            fu = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // 3. 转换数字
        long long ret = 0; // 用 long long 防止中间计算溢出，方便判断

        while (i < n && s[i] >= '0' && s[i] <= '9')
        {
            int val = s[i] - '0';
            ret = ret * 10 + val;

            // 4. 核心：溢出判断
            // 如果结果已经超过 int 范围，直接截断返回
            if (fu == 1 && ret > INT_MAX)
            {
                return INT_MAX;
            }
            if (fu == -1 && -ret < INT_MIN)
            {
                return INT_MIN;
            }

            i++;
        }

        return (int)(fu * ret);
    }
};