// 力扣：39. 组合总和
// https://leetcode.cn/problems/combination-sum/description/



// 方法：回溯法 (Backtracking)
// 时间复杂度：O(n^m)，n是候选数的数量，m是目标值与最小候选数的比值
class Solution
{
public:
    vector<vector<int>> ret;                            // 用于保存所有的组合
    vector<int> path;                                   // 当前路径

    // 回溯法核心函数
    void backtrack(vector<int>& candidates, int target, int sum, int index)
    {
        if (sum > target)                               // 如果当前和已经大于目标，剪枝
        {
            return;
        }

        // 找到符合条件的组合
        if (sum == target)
        {
            ret.push_back(path);
            return;
        }

        // 从当前索引开始，尝试所有候选数
        for (int i = index; i < candidates.size() && sum + candidates[i] <= target; i++)   // 剪枝：如果当前和加上候选数大于目标，提前结束循环
        {
            sum += candidates[i];                      // 加上候选数
            path.push_back(candidates[i]);             // 选择当前数字

            backtrack(candidates, target, sum, i);                                         // 递归回溯，注意i没有加1，表示可以重复选当前数字

            // 还原现场
            sum -= candidates[i];
            path.pop_back();
        }
    }

    // 主函数，初始化回溯
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());     // 排序优化剪枝
        backtrack(candidates, target, 0, 0);            // 开始回溯

        return ret;
    }
};
