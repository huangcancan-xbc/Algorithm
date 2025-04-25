// 力扣 1262. 可被三整除的最大和
// 链接：https://leetcode.cn/problems/greatest-sum-divisible-by-three/description/

// 方法一：正难则反 + 贪心 + 分类讨论
class Solution
{
public:
    int maxSumDivThree(vector<int>& nums)
    {
        const int INF = 0x3f3f3f3f;                 // 定义无穷大值，用于初始化最小值比较
        int sum = 0;                                // 记录所有元素的总和
        int x1 = INF, x2 = INF;                     // 记录余数为 1 的最小值和次小值
        int y1 = INF, y2 = INF;                     // 记录余数为 2 的最小值和次小值

        for (auto x : nums)                         // 遍历数组，计算总和并分类记录最小值
        {
            sum += x;                               // 累加总和

            // 分类讨论：根据 x 除以 3 的余数进行处理
            if (x % 3 == 1)
            {
                // 更新余数为 1 的最小值和次小值
                if (x < x1)
                {
                    x2 = x1;
                    x1 = x;
                }
                else if (x < x2)
                {
                    x2 = x;
                }
            }
            else if (x % 3 == 2)
            {
                // 更新余数为 2 的最小值和次小值
                if (x < y1)
                {
                    y2 = y1;
                    y1 = x;
                }
                else if (x < y2)
                {
                    y2 = x;
                }
            }
        }

        // 根据总和的余数分类讨论，确定调整策略
        if (sum % 3 == 0)
        {
            
            return sum;                             // 若总和是 3 的倍数，直接返回总和
        }
        else if (sum % 3 == 1)
        {
            // 若总和余数为 1：
            // 1. 减去最小的余数为 1 的数
            // 2. 或者减去两个最小的余数为 2 的数
            return max(sum - x1, sum - y1 - y2);
        }
        else
        {
            // 若总和余数为 2：
            // 1. 减去最小的余数为 2 的数
            // 2. 或者减去两个最小的余数为 1 的数
            return max(sum - y1, sum - x1 - x2);
        }
    }
};



// 方法二：动态规划
class Solution
{
public:
    int maxSumDivThree(vector<int>& nums)
    {
        int n = nums.size();

        // 初始化 dp 数组：dp0、dp1、dp2 分别记录余数 0、1、2 的最大和
        vector<int> dp0(n + 1, INT_MIN);
        vector<int> dp1(n + 1, INT_MIN);
        vector<int> dp2(n + 1, INT_MIN);

        dp0[0] = 0;                                     // 初始状态：dp0[0] = 0（空子序列和为 0，模 3 余数为 0）

        for (int i = 1; i <= n; ++i)                    // 动态转移：逐个遍历数组元素
        {
            int num = nums[i - 1];                      // 当前元素
            int mod = num % 3;                          // 当前数的模 3 余数

            // 分类讨论更新 dp（用上一轮状态来更新本轮状态）
            if (mod == 0)
            {
                dp0[i] = max(dp0[i - 1], dp0[i - 1] + num);
                dp1[i] = max(dp1[i - 1], dp1[i - 1] + num);
                dp2[i] = max(dp2[i - 1], dp2[i - 1] + num);
            }
            else if (mod == 1)
            {
                dp0[i] = max(dp0[i - 1], dp2[i - 1] + num);
                dp1[i] = max(dp1[i - 1], dp0[i - 1] + num);
                dp2[i] = max(dp2[i - 1], dp1[i - 1] + num);
            }
            else if (mod == 2)
            {
                dp0[i] = max(dp0[i - 1], dp1[i - 1] + num);
                dp1[i] = max(dp1[i - 1], dp2[i - 1] + num);
                dp2[i] = max(dp2[i - 1], dp0[i - 1] + num);
            }
        }

        return dp0[n];                                  // 返回余数为0的最大和
    }
};

// 这类题的动态规划的通用模板：（可被 2/5/10... 整除的最大和），将 3 替换成 2/5/10... 即可
class Solution
{
public:
    int maxSumDivThree(vector<int>& nums)
    {
        vector<int> dp(3, INT_MIN);                     // DP 数组，记录余数为 i 的最小值，长度为 3
        dp[0] = 0;                                      // 模3余数为 0 的情况，初始化为 0

        for (auto x : nums)                             // 遍历数组，更新 DP 数组
        {
            vector<int> temp = dp;                      // 临时数组，用于记录更新后的 DP 数组

            for (int j = 0; j < 3; j++)                 // 更新 DP 数组，根据当前数值模 3 余数进行分类讨论
            {
                int mod = (j + x % 3) % 3;              // 计算新的余数的位置
                dp[mod] = max(dp[mod], temp[j] + x);    // 更新 DP 数组
            }
        }

        return dp[0];                                   // 返回余数为 0 的最小值
    }
};