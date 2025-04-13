// 力扣：96. 不同的二叉搜索树
// 链接：https://leetcode.cn/problems/unique-binary-search-trees/description/

// 方法：动态规划（卡特兰数）
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);           // 定义 DP 数组，dp[i] 表示由 i 个节点能组成的不同二叉搜索树（BST）的个数
        dp[0] = 1;                          // 空树也算一种有效 BST

        // 计算 dp[i] 的值
        for (int i = 1; i <= n; i++)        // 遍历节点总数 i
        {
            for (int j = 1; j <= i; j++)    // 选择 j 作为根节点
            {
                dp[i] += dp[j - 1] * dp[i - j];     // 左子树有 j-1 个节点，右子树有 i-j 个节点
            }
        }

        return dp[n];                       // 返回 n 个节点时的 BST 总数
    }
};