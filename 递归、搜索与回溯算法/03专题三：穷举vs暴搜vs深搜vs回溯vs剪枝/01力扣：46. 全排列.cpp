//力扣：46. 全排列
//https://leetcode.cn/problems/permutations/description/


//方法：回溯

//算法原理：
//典型的回溯题⽬，我们需要在每⼀个位置上考虑所有的可能情况并且不能出现重复。通过深度优先搜索的⽅式，
//不断地枚举每个数在当前位置的可能性，并回溯到上⼀个状态，直到枚举完所有可能性，得到正确的结果。

//每个数是否可以放⼊当前位置，只需要判断这个数在之前是否出现即可。具体地，在这道题⽬中，我们可以通过⼀个递归函数 backtrack 和标记数组 visited 来实现全排列。

//递归函数设计：void backtrack(vector<vector<int>>& res, vector<int>& nums,vector<bool>& visited, vector<int>& ans, int step, int len)
//             参数：step（当前需要填⼊的位置），len（数组⻓度）；
//             返回值：⽆；
//             函数作⽤：查找所有合理的排列并存储在答案列表中。

//递归流程如下：
//1. ⾸先定义⼀个⼆维数组 res ⽤来存放所有可能的排列，⼀个⼀维数组 ans ⽤来存放每个状态的排列，⼀个⼀维数组 visited 标记元素，然后从第⼀个位置开始进⾏递归；
//2. 在每个递归的状态中，我们维护⼀个步数 step，表⽰当前已经处理了⼏个数字；
//3. 递归结束条件：当 step 等于 nums 数组的⻓度时，说明我们已经处理完了所有数字，将当前数组存⼊结果中；
//4. 在每个递归状态中，枚举所有下标 i，若这个下标未被标记，则使⽤ nums 数组中当前下标的元素：
//    a.将 visited[i] 标记为 1；
//    b.ans 数组中第 step 个元素被 nums[i] 覆盖；
//    c.对第 step + 1 个位置进⾏递归；
//    d.将 visited[i] 重新赋值为 0，表⽰回溯；
//5. 最后，返回 res。
//    • 特别地，我们可以不使⽤标记数组，直接遍历 step 之后的元素（未被使⽤），然后将其与需要递归的位置进⾏交换即可。
class Solution {
public:
    vector<vector<int>> ret;                    // 存储所有全排列的结果
    vector<int> path;                           // 当前路径，表示一个排列
    bool check[7] = { false };                  // 标记数组，记录数字是否被使用过（初始化为 false）

    vector<vector<int>> permute(vector<int>& nums)
    {
        dfs(nums);                              // 调用深度优先搜索函数
        return ret;                             // 返回最终结果
    }

    void dfs(vector<int>& nums)
    {
        // 如果当前路径大小等于 nums 大小，说明完成了一个排列
        if (path.size() == nums.size())
        {
            ret.push_back(path);                // 将路径加入结果数组
            return;                             // 返回，结束当前递归
        }

        // 遍历 nums 数组的每一个元素
        for (int i = 0; i < nums.size(); i++)
        {
            if (check[i] == false)              // 如果当前数字未被使用
            {
                path.push_back(nums[i]);        // 将当前数字加入路径
                check[i] = true;                // 标记当前数字已被使用

                dfs(nums);                      // 递归调用，继续生成后续排列

                path.pop_back();                // 回溯，移除最后一个数字，恢复现场
                check[i] = false;               // 回溯，取消标记，恢复状态
            }
        }
    }
};
//代码解释：
//整体思路：
//    • 算法类型：回溯法（Backtracking）
//    • 核心思想： 通过递归枚举所有可能的排列，并在不符合条件时回溯恢复状态。
//        • 在每次递归中：
//        • 检查当前路径是否满足条件（路径长度是否等于输入数组大小）。
//        • 如果不满足，尝试添加未使用的数字到路径中。
//        • 添加后继续递归，生成下一层的排列。
//        • 递归返回后，通过回溯恢复到上一状态，尝试其他可能性。