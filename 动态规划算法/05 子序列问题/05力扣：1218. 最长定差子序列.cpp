// 力扣：1218. 最长定差子序列
// 链接：https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/description/

// 方法：动态规划 + 哈希表优化
class Solution
{
public:
    int longestSubsequence(vector<int>& arr, int difference)
    {
        unordered_map<int, int> hash;           // 哈希表用于存储每个数的最长定差子序列长度
        hash[arr[0]] = 1;                       // 初始化第一个元素的最长子序列长度为 1
        int ret = 1;                            // 记录最长定差子序列的长度，初始化为 1

        for (int i = 1; i < arr.size(); i++)    // 遍历数组中的每个元素，从第二个元素开始
        {
            // 当前元素 arr[i] 如果能接上之前的元素 arr[i] - difference，说明它是一个定差子序列的延续
            hash[arr[i]] = hash[arr[i] - difference] + 1;   // 更新 arr[i] 的最长子序列长度

            // 更新最终结果 ret，取当前最长子序列的长度和当前记录的最大长度的较大值
            ret = max(ret, hash[arr[i]]);
        }

        return ret;                             // 返回最长定差子序列的长度
    }
};