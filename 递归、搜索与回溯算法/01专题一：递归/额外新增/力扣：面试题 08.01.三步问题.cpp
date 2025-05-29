//力扣：面试题 08.01.三步问题
//链接：https://leetcode.cn/problems/three-steps-problem-lcci/description/
//可参考 斐波那契 解法（https://ac.nowcoder.com/acm/contest/97845/L（参赛密码：517acm））


// 方法一：循环
// 时间复杂度：O(n)
class Solution 
{
public:
    int waysToStep(int n) 
    {
        if (n == 1 || n == 2)
        {
            return n;
        }

        if (n == 3)
        {
            return 4;
        }

        int dp1 = 1, dp2 = 2, dp3 = 4, dp4;
        for (int i = 4; i <= n; ++i) 
        {
            dp4 = ((dp1 + dp2) % 1000000007 + dp3) % 1000000007;
            dp1 = dp2;
            dp2 = dp3;
            dp3 = dp4;
        }

        return dp4;
    }
};


// 方法二：递归
// 时间复杂度：O(n)
class Solution 
{
public:
    int waysToStep(int n) 
    {
        if (n == 1 || n == 2)
        {
            return n;
        }

        if (n == 3)
        {
            return 4;
        }

        return ((waysToStep(n - 1) + waysToStep(n - 2)) % 1000000007 + waysToStep(n - 3)) % 1000000007;
    }
};


// 方法:递归优化
// 时间复杂度：O(n)

//思想：用数组存储中间结果，避免重复计算。
class Solution 
{
public:
    int arr[1000005];
    int steps(int n)
    {
        if (arr[n] != 0)
        {
            return arr[n];
        }

        if (n < 3)
        {
            return n;
        }

        if (n == 3)
        {
            return 4;
        }

        return arr[n] = ((steps(n - 1) + steps(n - 2)) % 1000000007 + steps(n - 3)) % 1000000007;
    }

    int waysToStep(int n) 
    {
        int ret = steps(n);
        return ret;
    }
};