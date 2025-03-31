// 力扣：1027. 最长等差数列
// 链接：https://leetcode.cn/problems/longest-arithmetic-subsequence/description/

// 方法：动态规划
class Solution
{
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        int n = nums.size();

        vector<unordered_map<int, int>> dp(n);      // dp[i][d]表示以nums[i]结尾，公差为d的等差数列的长度
        int ret = 2;                                // 最短的等差数列长度为2

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int d = nums[i] - nums[j];          // 计算公差d

                // 如果dp[j]中已经有了公差为d的等差数列，延续该数列，如果没有，意味着nums[j]和nums[i]是新的等差数列的起始，长度为2
                dp[i][d] = dp[j].count(d) ? dp[j][d] + 1 : 2;

                ret = max(ret, dp[i][d]);           // 更新最大长度
            }
        }

        return ret;                                 // 返回最大长度
    }
};


//优化思路：
//我们使用动态规划来记录以每对元素结尾的最长等差数列的长度。具体步骤如下：
//1. 状态定义：dp[i][j] 表示以 nums[i] 和 nums[j] 作为最后两个元素的最长等差数列的长度。
//2. 状态转移：对于每对(i, j)，计算前一个可能的元素值 a = 2 * nums[i] - nums[j]，并检查是否存在该元素且其索引 k 小于 i。
//3. 哈希表维护：在处理每个 j 时，逐步维护一个哈希表，记录当前处理的 i 之前的所有元素及其最后出现的索引，以确保正确性。
class Solution
{
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        int n = nums.size();                            // 获取数组的长度

        // dp[i][j] 表示以nums[i]和nums[j]为结尾的等差数列的最大长度，初始值为2，表示最短的等差数列的长度为2（即只包含nums[i]和nums[j]两个元素）
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ret = 2;                                    // 最长等差数列的长度，初始化为2

        for (int j = 0; j < n; ++j)                     // 外层循环，遍历每个nums[j]，作为等差数列的右端点
        {
            unordered_map<int, int> hash;               // 存储数值到索引的映射，用于查找是否存在合法的左端点（nums[k]）

            for (int i = 0; i < j; ++i)                 // 内层循环，遍历nums[i]，作为等差数列的左端点
            {
                // 计算公差d
                int a = 2 * nums[i] - nums[j];          // 求公差公式：d = nums[j] - nums[i] => d = 2 * nums[i] - nums[j]

                if (hash.count(a))                      // 如果a在哈希表中，说明存在一个符合条件的nums[k]，可以组成等差数列
                {
                    int k = hash[a];                    // k是符合条件的左端点，满足 nums[k] == a
                    dp[i][j] = dp[k][i] + 1;            // 通过延续之前的数列长度，更新当前的数列长度
                    ret = max(ret, dp[i][j]);           // 更新最长等差数列的长度
                }

                hash[nums[i]] = i;                      // 将当前的nums[i]和其索引i存入哈希表，供后续的i值使用
            }
        }

        return ret;                                     // 返回最长等差数列的长度
    }
};



// 优化：
class Solution
{
public:
    int longestArithSeqLength(vector<int>& nums)
    {
        
        unordered_map<int, int> hash;                   // hash 用来存储每个数及其对应的索引位置，初始化时将第一个元素加入
        hash[nums[0]] = 0;                              // 初始时，将第一个数nums[0]及其索引0加入哈希表

        int n = nums.size();                            // 获取数组的长度

        // dp[i][j] 表示以nums[i]和nums[j]为末尾的等差数列的最大长度，初始值为2，最短的等差数列长度为2（即nums[i]和nums[j]两个元素）
        vector<vector<int>> dp(n, vector<int>(n, 2));

        int ret = 2;                                    // 记录最长等差数列的长度，初始化为2（最小的有效长度）

        for (int i = 1; i < n; i++)                     // 外层循环，遍历nums中的每个元素，作为等差数列的右端点
        {
            for (int j = i + 1; j < n; j++)             // 内层循环，遍历每个i之前的元素，作为等差数列的左端点
            {
                int a = 2 * nums[i] - nums[j];          // 计算当前的公差a，公式：a = 2 * nums[i] - nums[j]

                if (hash.count(a))                      // 如果哈希表中存在a，说明可以延续之前的等差数列
                {
                    // 更新dp[i][j]，表示以nums[i]和nums[j]为末尾的等差数列的长度
                    dp[i][j] = dp[hash[a]][i] + 1;      // dp[hash[a]][i]是包含nums[i]的等差数列的长度
                }

                ret = max(ret, dp[i][j]);               // 更新最长的等差数列的长度
            }

            hash[nums[i]] = i;                          // 将nums[i]及其索引i加入哈希表，供后续的元素查找
        }

        return ret;                                     // 返回最长等差数列的长度
    }
};