//力扣：50. Pow(x, n)
//https://leetcode.cn/problems/powx-n/description/

//在方法一中，当n = -2147483648时，-n会溢出，因为int范围为[-2^31, 2^31-1]。通过将n转为long类型，避免了溢出。
//方法二中同样采用了将n转为long的处理方式。

//方法一：for循环
//时间复杂度：O(logn)
class Solution {
public:
    double myPow(double x, long n) 
    {
        if (n == 0) 
        {
            return 1.0;                       // 任何数的 0 次方均为 1
        }

        double res = 1.0;

        if (n < 0) 
        {
            x = 1.0 / x;                      // 处理负指数，取倒数
            n = -(long)n;                     // 转为 long 避免溢出
        }

        while (n > 0) 
        {
            if (n % 2 == 1) 
            {
                res *= x;                     // 如果当前位为 1，则累乘当前基数
            }
            x *= x;                           // 每次迭代，基数平方
            n /= 2;                           // 指数右移一位
        }

        return res;
    }
};



//方法二：（递归 - 快速幂）
//时间复杂度：O(logn)
//算法原理：
//1. 递归函数的含义：求出 x 的 n 次⽅是多少，然后返回；
//2. 函数体：先求出 x 的 n / 2 次⽅是多少，然后根据 n 的奇偶，得出 x 的 n 次⽅是多少；
//3. 递归出⼝：当 n 为 0 的时候，返回 1 即可。
class Solution {
public:
    double myPow(double x, int n) 
    {
        return n < 0 ? 1.0 / pow(x, -(long)n) : pow(x, (long)n);
    }

private:
    double pow(double x, long n) 
    {
        if (n == 0) 
        {
            return 1.0;                        // 基本情况：n 为 0 时返回 1
        }

        double temp = pow(x, n / 2);           // 递归计算一半的次方
        return n % 2 == 0 ? temp * temp        // 如果是偶数次方，返回 temp 的平方
            : temp * temp * x;                 // 如果是奇数次方，多乘一个 x
    }
};