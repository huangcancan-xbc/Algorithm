// 力扣：873. 最长的斐波那契子序列的长度
// 链接：https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/description/

// 方法：动态规划 + 哈希表优化
class Solution
{
public:
    int lenLongestFibSubseq(vector<int>& arr)
    {
        int n = arr.size();                         // 获取数组的长度
        unordered_map<int, int> hash;               // 哈希表，用于存储每个元素及其对应的索引
        for (int i = 0; i < n; i++)                 // 遍历数组，填充哈希表
        {
            hash[arr[i]] = i;                       // hash[x] = i，表示元素 x 在数组中的索引位置
        }

        // dp[i][j] 表示以 arr[i] 和 arr[j] 为结尾的斐波那契子序列的长度，初始值为 2，因为任何两个数本身就可以构成一个长度为 2 的斐波那契子序列
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ret = 2;                                // 最长斐波那契子序列的长度，初始为 2

        for (int j = 2; j < n; j++)                 // 遍历数组，从第三个元素开始
        {
            for (int i = 1; i < j; i++)             // 对于每个 j，遍历之前的元素 i
            {
                int a = arr[j] - arr[i];            // 计算当前元素 arr[j] 和 arr[i] 的差值 a（即 a < arr[i] < arr[j]）
                if (a < arr[i] && hash.count(a))    // 如果差值 a 存在于数组中，且 a 小于 arr[i]（即 a 在 i 之前）
                {
                    dp[i][j] = dp[hash[a]][i] + 1;  // 更新 dp[i][j]，即以 arr[i] 和 arr[j] 为结尾的斐波那契子序列长度
                }

                ret = max(ret, dp[i][j]);           // 更新最大长度
            }
        }

        return ret < 3 ? 0 : ret;                   // 如果最大长度小于 3，说明没有有效的斐波那契子序列，返回 0
    }
};