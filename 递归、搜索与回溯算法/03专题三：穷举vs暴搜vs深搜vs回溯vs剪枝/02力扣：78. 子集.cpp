//力扣：78. 子集
//https://leetcode.cn/problems/subsets/description/


//算法原理：
//为了获得 nums 数组的所有⼦集，我们需要对数组中的每个元素进⾏选择或不选择的操作，即 nums数组⼀定存在 2 ^ (数组⻓度)个⼦集。
//对于查找⼦集，具体可以定义⼀个数组，来记录当前的状态，并对其进⾏递归。

//对于每个元素有两种选择：1.不进⾏任何操作；2.将其添加⾄当前状态的集合。在递归时我们需要保证递归结束时当前的状态与进⾏递归操作前的状态不变，
//⽽当我们在选择进⾏步骤 2 进⾏递归时，当前状态会发⽣变化，因此我们需要在递归结束时撤回添加操作，即进⾏回溯。

//递归函数设计：void dfs(vector<vector<int>>&res, vector<int>&ans, vector<int>&nums, int step)
//    参数：step（当前需要处理的元素下标）；
//    返回值：⽆；
//    函数作⽤：查找集合的所有⼦集并存储在答案列表中。

//递归流程如下：
//    1. 递归结束条件：如果当前需要处理的元素下标越界，则记录当前状态并直接返回；
//    2. 在递归过程中，对于每个元素，我们有两种选择：
//        ◦ 不选择当前元素，直接递归到下⼀个元素；
//        ◦ 选择当前元素，将其添加到数组末尾后递归到下⼀个元素，然后在递归结束时撤回添加操作；
//    3. 所有符合条件的状态都被记录下来，返回即可。


//方法一：回溯法
//时间复杂度：O(2^n)

//解释:
// · Backtracking 是递归思想的一种应用。
// · 每个元素有两种状态：选择(include) 或 不选择(exclude)。
// · 递归完成所有可能的组合，构造结果。
class Solution {
public:
    vector<vector<int>> ret;                        // 存储最终结果 (Result set)
    vector<int> path;                               // 当前路径 (Current subset)

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        dfs(nums, 0);                               // 从第 0 个元素开始回溯
        return ret;                                 // 返回所有子集
    }

    void dfs(vector<int>& nums, int pos)
    {
        // 递归终止条件 (Termination condition)
        if (pos == nums.size())
        {
            ret.push_back(path);                    // 将当前路径加入结果集
            return;
        }

        // 包含当前元素 (Include nums[pos])
        path.push_back(nums[pos]);                  // 将元素加入当前路径
        dfs(nums, pos + 1);                         // 递归到下一层
        path.pop_back();                            // 回溯 (Remove the element)
        
        // 不包含当前元素 (Exclude nums[pos])
        dfs(nums, pos + 1);                         // 直接递归到下一层
    }
};



//方法二：DFS
//时间复杂度：O(2^n)

//解释:
// · 使用 DFS 构造所有子集。
// · 每层循环中，尝试将当前元素加入路径，并递归寻找后续子集。
class Solution {
public:
    vector<vector<int>> ret;                        // 存储最终结果 (Result set)
    vector<int> path;                               // 当前路径 (Current subset)

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        dfs(nums, 0);                               // 从第 0 个元素开始 DFS
        return ret;                                 // 返回所有子集
    }

    void dfs(vector<int>& nums, int pos)
    { 
        ret.push_back(path);                        // 每次递归都将当前路径加入结果集

        // 遍历每个可能的选择 (Iterate through possible choices)
        for (int i = pos; i < nums.size(); i++)
        {
            path.push_back(nums[i]);                // 将元素加入当前路径
            dfs(nums, i + 1);                       // 递归下一层 (DFS to next level)
            path.pop_back();                        // 回溯 (Backtrack)
        }
    }
};
//两种方法的对比
//1. 回溯法(Backtracking) :
//    · 逻辑清晰，分两种情况处理每个元素：包含 和 不包含。
//    · 代码结构较为简单，但每层递归分支更多。
//2. DFS(深度优先搜索) :
//    · 在每层递归中动态构造子集。
//    · 每次递归都直接保存当前路径，无需考虑两种分支逻辑。
//总结：两种方法都能够生成所有子集，但使用场景略有不同。回溯法更适合需要显式构造“选 / 不选”逻辑的问题，而 DFS 对于类似遍历树结构的问题更直观。