//力扣:216. 组合总和III
//https://leetcode.cn/problems/combination-sum-iii/description/


class Solution 
{
public:
    vector<vector<int>> ret;                                // 存储所有满足条件的组合结果
    vector<int> path;                                       // 当前路径（用于存储当前递归状态的组合）

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        dfs(1, 9, k, n);                                    // 从数字 1 开始递归搜索，最大数字为 9
        return ret;
    }

    void dfs(int cur, int n, int k, int sum) 
    {
        if (path.size() + (n - cur + 1) < k)                // 剪枝条件 1：剩余可用数字不足以组成 k 个数
        {
            return;
        }

        if (path.size() > k)                                // 剪枝条件 2：当前路径长度已经超过 k
        {
            return;
        }

        // 终止条件：路径长度为 k，且路径和等于目标值 sum
        if (path.size() == k && accumulate(path.begin(), path.end(), 0) == sum) 
        {
            ret.push_back(path);                            // 将符合条件的组合加入结果集
            return;
        }

        // 选择当前数字 cur
        path.push_back(cur);                                // 添加当前数字到路径中
        dfs(cur + 1, n, k, sum);                            // 递归处理下一数字
        path.pop_back();                                    // 回溯，移除当前数字

        // 不选择当前数字 cur
        dfs(cur + 1, n, k, sum);                            // 递归处理下一数字
    }
};