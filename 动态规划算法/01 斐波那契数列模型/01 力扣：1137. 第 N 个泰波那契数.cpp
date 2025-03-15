//力扣：1137. 第 N 个泰波那契数
//链接：https://leetcode.cn/problems/n-th-tribonacci-number/description/


//方法：动态规划
//状态转移方程：f(n) = f(n-1) + f(n-2) + f(n-3)
//初始条件：f(0) = 0, f(1) = 1, f(2) = 1
//时间复杂度：O(n)
//空间复杂度：O(n)
class Solution 
{
public:
    int tribonacci(int n) 
    {
        //1.创建 dp 表
        //2.初始化
        //3.填表
        //4.返回结果

        //处理边界情况
        if (n == 0)
        {
            return 0;
        }

        if (n == 1 || n == 2)
        {
            return 1;
        }

        //创建 dp 表
        vector<int> dp(n + 1);

        //初始化
        dp[0] = 0, dp[1] = 1, dp[2] = 1;

        //从左往右填表
        for (int i = 3; i < n + 1; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        //返回结果
        return dp[n];
    }
};




//滚动数组优化
//时间复杂度：O(n)
//空间复杂度：O(1)
class Solution 
{
public:
    int tribonacci(int n) 
    {
        if (n == 0)
        {
            return 0;
        }

        if (n == 1 || n == 2)
        {
            return 1;
        }


        int a = 0, b = 1, c = 1, d = 0;             //滚动数组
        for (int i = 3; i < n + 1; i++)
        {
            d = a + b + c;                          //计算当前值

            //更新滚动数组
            a = b;
            b = c;
            c = d;
        }

        return d;
    }
};