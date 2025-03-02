//力扣：39. 组合总和
//链接：https://leetcode.cn/problems/combination-sum/description/


//方法：DFS

//算法原理：
//candidates 的所有元素 互不相同，因此我们在递归状态时只需要对每个元素进⾏如下判断：
//1. 跳过，对下⼀个元素进⾏判断；
//2. 将其添加⾄当前状态中，我们在选择添加当前元素时，之后仍可以继续选择当前元素（可以重复选择同⼀元素）。
//• 因此，我们在选择当前元素并向下传递下标时，应该直接传递当前元素下标。
//
//递归函数流程如下：
//1. 结束条件：
//    a.当前需要处理的元素下标越界；
//    b.当前状态的元素和已经与⽬标值相同；
//2. 跳过当前元素，当前状态不变，对下⼀个元素进⾏处理；
//3. 选择将当前元素添加⾄当前状态，并保留状态继续对当前元素进⾏处理，递归结束时撤销添加操作。

//方法一：DFS（枚举每一个元素）
class Solution 
{
public:
    vector<int> path;
    vector<vector<int>> ret;
    int dest;

    void dfs(vector<int>& candidates, int pos, int sum)
    {
        if (dest == sum)
        {
            ret.push_back(path);                    // 如找到目标和，则将当前路径加入结果，并返回
            return;
        }

        //if (sum > dest || pos >= candidates.size())
        if (sum > dest || pos == candidates.size())
        {
            return;                                 // 如当前路径和大于目标和，或当前位置已经超出候选数组范围，终止搜索（返回）
        }

        for (int i = pos; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);          // 选择当前数字

            dfs(candidates, i, sum + candidates[i]);// 继续搜索，允许重复使用当前数字

            path.pop_back();                        // 回溯，移除当前数字
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        dest = target;
        dfs(candidates, 0, 0);                      // 从索引0开始搜索，初始和为0
        return ret;
    }
};



//方法二：DFS（枚举每一个元素 “出现” 次数）
class Solution
{
public:
    vector<int> path;                               // 存储当前的组合路径
    vector<vector<int>> ret;                        // 存储最终的所有组合
    int dest;                                       // 目标和

    void dfs(vector<int>& candidates, int pos, int sum)
    {
        if (dest == sum)
        {
            ret.push_back(path);                    // 如果当前和等于目标，记录路径并返回
            return;
        }

        if (sum > dest || pos >= candidates.size())
        {
            return;                                 // 超过目标或遍历完所有元素时停止（返回）
        }

        for (int i = 0; i * candidates[pos] <= dest; i++)
        {
            if (i)
            {
                path.push_back(candidates[pos]);    // i不为0时，加入当前元素
            }

            dfs(candidates, pos + 1, sum + i * candidates[pos]);// DFS，继续遍历下一个元素
        }

        for (int i = 1; i * candidates[pos] <= dest; i++)
        {
            path.pop_back();                        // 回溯，移除最后加入的元素
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        dest = target;                              // 记录目标和
        dfs(candidates, 0, 0);
        return ret;
    }
};



//优化版：
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> ret;
    int dest;

    void dfs(vector<int>& candidates, int pos, int sum)
    {
        if (dest == sum)
        {
            ret.push_back(path);
            return;
        }

        if (sum > dest || pos >= candidates.size())
        {
            return;
        }

        for (int i = 0; sum + i * candidates[pos] <= dest; i++) // 优化：只枚举到当前元素可以凑够目标和的最大值
        {
            if (i)
            {
                path.push_back(candidates[pos]);
            }

            dfs(candidates, pos + 1, sum + i * candidates[pos]);
        }

        for (int i = 1; sum + i * candidates[pos] <= dest; i++) // 优化：回溯时，只回溯到当前元素可以凑够目标和的最大值
        {
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        dest = target;
        dfs(candidates, 0, 0);
        return ret;
    }
};