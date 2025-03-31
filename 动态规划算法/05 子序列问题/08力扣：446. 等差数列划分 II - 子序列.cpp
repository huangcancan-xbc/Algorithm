// 力扣：446. 等差数列划分 II - 子序列
// 链接：https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/description/

// 方法：动态规划 + 哈希表优化
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));       // dp[i][j]表示以nums[j]和nums[i]为结尾的等差数列的个数
        unordered_map<long long, vector<int>> hash;         // 用哈希表来存储每个数出现的索引
        for (int i = 0; i < n; i++)
        {
            hash[nums[i]].push_back(i);                     // 将当前的 nums[i] 索引添加到 hash 表中，以便以后查询
        }

        int sum = 0;                                        // 最终的结果
        for (int i = 2; i < n; i++)                         // 遍历数组，从第3个数开始（i >= 2），每次考虑一个新数字 nums[i]
        {
            for (int j = 1; j < i; j++)                     // 遍历所有在 nums[i] 之前的数 nums[j] (j < i)
            {
                // 计算公差 a = 2 * nums[j] - nums[i]，找前一个数 nums[k]（满足nums[k], nums[j], nums[i]是等差数列），注意数据范围！
                long long a = (long long)2 * nums[j] - nums[i];

                if (hash.count(a))                          // 如果a存在于hash表中，说明有可能构成等差数列
                {
                    for (auto k : hash[a])                  // 遍历a对应的所有索引 k，查找符合条件的k
                    {
                        if (k < j)                          // k 必须小于 j，才符合等差数列的条件
                        {
                            dp[j][i] += dp[k][j] + 1;       // 更新 dp[j][i]，如果nums[k]和nums[j]形成等差数列，就加上这个数量
                        }
                        //else
                        //{
                        //    break;                          // 否则，退出循环
                        //}
                    }
                }

                sum += dp[j][i];                            // 将更新后的 dp[j][i] 加入结果中
            }
        }

        return sum;                                         // 返回所有等差数列的个数
    }
};