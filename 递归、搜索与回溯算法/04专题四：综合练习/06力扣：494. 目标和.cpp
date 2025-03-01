//力扣：494. 目标和
//链接：https://leetcode.cn/problems/target-sum/description/


//方法：DFS

//算法原理：
//对于每个数，可以选择加上或减去它，依次枚举每⼀个数字，在每个数都被选择时检查得到的和是否等于⽬标值。
//如果等于，则记录结果。需要注意的是，为了优化时间复杂度，可以提前计算出数组中所有数字的和 sum，以及数组的⻓度len。
//这样可以快速判断当前的和减去剩余的所有数是否已经超过了⽬标值 target ，或者当前的和加上剩下的数的和是否⼩于⽬标值 target，如果满⾜条件，则可以直接回溯。
//
//递归流程：
//1. 递归结束条件：index 与数组⻓度相等，判断当前状态的 sum 是否与⽬标值相等，若是计数加⼀；
//2. 选择当前元素进⾏加操作，递归下⼀个位置，并更新参数 sum；
//3. 选择当前元素进⾏减操作，递归下⼀个位置，并更新参数 sum；
//
//• 特别地，此问题可以转化为另⼀个问题：若所有元素初始状态均为减，选择其中⼏个元素将他们的状态修改为加，计算修改后的元素和与⽬标值相等的⽅案个数。
//1. 选择其中 x 个元素进⾏修改，并且这 x 个元素的和为 y；
//2. 检查使得 - sum + 2 * y = target（移项：y = (sum + target) / 2）成⽴的⽅案个数，即选择 x 个元素和为(sum + target) / 2 的⽅案个数；
//    a.若 sum + target 为奇数，则不存在这种⽅案；
//3. 递归流程：
//    a.传⼊参数：index（当前要处理的元素下标），sum（当前状态和），nums（元素数组），aim（⽬标值：(sum + target) / 2）；
//    b.递归结束条件：index 与数组⻓度相等，判断当前 sum 是否与⽬标值相等，若是返回 1，否则返回 0；
//    c.返回 递归选择当前元素 以及 递归不选择当前元素 函数值的和。


//path 作为全局变量的写法（理论上当 path 作为全局变量时，代码会超时，但是很幸运还是通过了测试用例）：
class Solution
{
public:
    int path, ret, dest;                // path 当前路径的和，ret 满足条件的方案数，dest 目标值

    // 深度优先搜索 (DFS) 函数
    void dfs(vector<int>& nums, int pos)
    {
        if (pos == nums.size())         // 如果遍历到最后一个元素
        {
            if (path == dest)           // 判断当前路径的和是否等于目标值
            {
                ret++;                  // 如果符合条件，方案数加一
            }
            return;
        }

        // 尝试将当前元素加到路径中（加法）
        path += nums[pos];
        dfs(nums, pos + 1);             // 继续递归到下一个元素
        path -= nums[pos];              // 回溯，撤销选择

        // 尝试将当前元素减去路径中（减法）
        path -= nums[pos];
        dfs(nums, pos + 1);             // 继续递归到下一个元素
        path += nums[pos];              // 回溯，撤销选择
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        dest = target;                  // 设置目标值
        dfs(nums, 0);                   // 从第一个元素开始递归
        return ret;
    }
};



//path 作为局部变量（当作函数参数）的写法：
class Solution
{
public:
    int ret, dest;                      // ret 满足条件的方案数，dest 目标值

    void dfs(vector<int>& nums, int pos, int path)// path：当前路径的和
    {
        if (pos == nums.size())
        {
            if (path == dest)
            {
                ret++;                  // 如果符合条件，方案数加一
            }
            return;
        }

        dfs(nums, pos + 1, path + nums[pos]);   // 尝试将当前元素加到路径中（加法）

        dfs(nums, pos + 1, path - nums[pos]);   // 尝试将当前元素减去路径中（减法）

    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        dest = target;
        int path = 0;// 可不要（用下面的 dfs(nums, 0, 0) 替代）
        dfs(nums, 0, path);                     // 从第一个元素开始递归，path 作为局部变量传递
        return ret;
    }
};

class Solution
{
public:
    int ret, dest;

    void dfs(vector<int>& nums, int pos, int path)
    {
        if (pos == nums.size())
        {
            if (path == dest)
            {
                ret++;
            }
            return;
        }

        dfs(nums, pos + 1, path + nums[pos]);

        dfs(nums, pos + 1, path - nums[pos]);

    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        dest = target;
        dfs(nums, 0, 0);
        return ret;
    }
};