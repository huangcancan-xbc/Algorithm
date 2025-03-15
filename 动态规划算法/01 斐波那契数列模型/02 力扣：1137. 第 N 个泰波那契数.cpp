//力扣：面试题 08.01. 三步问题
//链接：https://leetcode.cn/problems/three-steps-problem-lcci/description/


//方法：动态规划
//时间复杂度：O(n)
//空间复杂度：O(n)
class Solution
{
public:
    int waysToStep(int n)
    {
        //1.创建 dp 表
        //2.初始化
        //3.填表
        //4.返回结果

        const int MOD = 1e9 + 7;

        //边界条件判断
        if (n == 1 || n == 2)
        {
            return n;
        }

        if (n == 3)
        {
            return 4;
        }

        vector<int> dp(n + 1);
        dp[1] = 1, dp[2] = 2, dp[3] = 4;
        for (int i = 4; i < n + 1; i++)             //遍历到第 n 个元素
        {
            dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
            //注意：这里的 % MOD 运算是为了防止溢出，每一步都要取模，防止结果太大溢出
        }

        return dp[n];
    }
};




//滚动数组优化
//时间复杂度：O(n)
//空间复杂度：O(1)
class Solution
{
public:
    int waysToStep(int n)
    {
        const int MOD = 1e9 + 7;

        //边界条件判断
        if (n == 1 || n == 2)
        {
            return n;
        }

        if (n == 3)
        {
            return 4;
        }

        int a = 1, b = 2, c = 4, d = 0;             //滚动数组
        for (int i = 4; i < n + 1; i++)             //从第四个元素开始，遍历到第 n 个元素
        {
            d = ((a + b) % MOD + c) % MOD;          //计算当前元素的有效值（不超过 int 范围的结果）

            //更新滚动数组
            a = b;
            b = c;
            c = d;
        }

        return d;
    }
};