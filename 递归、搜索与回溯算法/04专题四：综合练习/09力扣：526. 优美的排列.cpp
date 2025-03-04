//力扣：526. 优美的排列
//链接：https://leetcode.cn/problems/beautiful-arrangement/description/


//方法：DFS

//代码一：
class Solution
{
public:
    int ret;                            // 用于存储满足条件的美丽排列的数量
    int k;                              // 输入的数字 n，用于表示排列的最大值
    bool check[16];                     // 一个布尔数组，用于记录数字是否已经被使用，最多支持 n=15 的输入

    void dfs(int pos)
    {
        if (pos > k)                    // 如果当前的位置超出了 k，说明已经找到一个完整的美丽排列
        {
            ret++;                      // 计数加一并返回
            return;
        }

        for (int i = 1; i <= k; i++)    // 尝试将 1 到 k 中的每个数字放入当前的位置
        {
            if (check[i])
            {
                continue;               // 如果数字 i 已经被使用过，跳过
            }

            // 如果数字 i 可以放在位置 pos（满足美丽排列的条件）
            if (i % pos == 0 || pos % i == 0)
            {
                check[i] = true;        // 标记数字 i 已被使用
                dfs(pos + 1);           // 递归检查下一个位置
                check[i] = false;       // 回溯，撤销标记，尝试其他可能性
            }
        }
    }

    int countArrangement(int n)
    {
        k = n;
        dfs(1);                         // 注意从第 1 个位置开始进行深度优先搜索
        return ret;
    }
};




//代码二：

//算法原理：
//我们需要在每⼀个位置上考虑所有的可能情况并且不能出现重复。通过深度优先搜索的⽅式，
//不断地枚举每个数在当前位置的可能性，并回溯到上⼀个状态，直到枚举完所有可能性，得到正确的结果。
//我们需要定义⼀个变量 ⽤来记录所有可能的排列数量，⼀个⼀维数组 visited 标记元素，然后从第⼀个位置开始进⾏递归；
//
//递归流程如下：
//1. 递归结束条件：当 index 等于 n 时，说明已经处理完了所有数字，将当前数组存⼊结果中；
//2. 在每个递归状态中，枚举所有下标 x，若这个下标未被标记，并且满⾜题⽬条件之⼀：
//    a.将 visited[x] 标记为 1；
//    b.对第 index + 1 个位置进⾏递归；
//    c.将 visited[x] 重新赋值为 0，表⽰回溯；
class Solution
{
public:
    bool check[16];
    int ret;

    void dfs(int pos, int n)
    {
        if (pos == n + 1)               // 如果当前的位置等于 n+1，说明已经找到一个完整的美丽排列
        {
            ret++;                      // 计数加一并返回
            return;
        }

        for (int i = 1; i <= n; i++)    // 尝试将 1 到 n 中的每个数字放入当前的位置
        {
            if (!check[i] && (pos % i == 0 || i % pos == 0))    // 如果数字 i 可以放在位置 pos（满足美丽排列的条件）
            {
                check[i] = true;        // 标记数字 i 已被使用
                dfs(pos + 1, n);        // 递归检查下一个位置
                check[i] = false;       // 回溯，撤销标记，尝试其他可能性
            }
        }
    }

    int countArrangement(int n)
    {
        dfs(1, n);
        return ret;
    }
};