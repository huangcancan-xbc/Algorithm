//力扣：47. 全排列 II
//链接：https://leetcode.cn/problems/permutations-ii/description/


//方法：DFS + 剪枝（核心是剪枝）

//算法原理见配套图片

//1. 只关心"不合法"的分支
class Solution
{
public:
    vector<int> path;                   // 存储当前路径
    vector<vector<int>> ret;            // 存储所有的排列结果
    bool check[8];                      // 标记元素是否已被使用

    void dfs(vector<int>& nums, int pos)
    {
        if (path.size() == nums.size()) // 如果路径的大小等于nums的大小，说明已生成一个排列
        {
            ret.push_back(path);        // 将当前路径加入结果集中
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 如果元素已被使用或前一个相同的元素未被使用，则跳过
            if (check[i] == true || (i != 0 && nums[i] == nums[i - 1] && check[i - 1] == false))
            {
                continue;
            }

            path.push_back(nums[i]);     // 将当前元素加入路径
            check[i] = true;             // 标记元素已使用

            dfs(nums, pos + 1);          // 递归处理下一个元素

            path.pop_back();             // 回溯，移除当前元素
            check[i] = false;            // 重置标记，允许再次使用该元素
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());  // 对输入数组进行排序，确保重复元素能够被处理
        dfs(nums, 0);                    // 从第一个位置开始深度优先搜索
        return ret;                      // 返回所有的排列结果
    }
};



//2. 只关心"合法"的分支
class Solution
{
public:
    vector<int> path;                    // 存储当前路径
    vector<vector<int>> ret;             // 存储所有的排列结果
    bool check[8];                       // 标记元素是否已被使用

    void dfs(vector<int>& nums, int pos)
    {
        if (path.size() == nums.size())  // 如果路径的大小等于nums的大小，说明已生成一个排列
        {
            ret.push_back(path);         // 将当前路径加入结果集中
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            // 剪枝条件： 
            // 1. 当前元素 nums[i] 未被使用 (check[i] == false)
            // 2. 如果是第一个元素 (i == 0)，或者当前元素与前一个元素不同 (nums[i] != nums[i - 1])
            // 3. 如果当前元素与前一个元素相同，则前一个元素必须已经被使用 (check[i - 1] == true)，以避免重复排列
            if (check[i] == false && (i == 0 || nums[i] != nums[i - 1] || check[i - 1] == true))
            {
                path.push_back(nums[i]); // 将当前元素加入路径
                check[i] = true;         // 标记元素已使用

                dfs(nums, pos + 1);      // 递归处理下一个元素

                path.pop_back();         // 回溯，移除当前元素
                check[i] = false;        // 重置标记，允许再次使用该元素
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());  // 对输入数组进行排序，确保重复元素能够被处理
        dfs(nums, 0);                    // 从第一个位置开始深度优先搜索
        return ret;                      // 返回所有的排列结果
    }
};