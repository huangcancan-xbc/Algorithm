//力扣：230. 二叉搜索树中第 K 小的元素
//https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/


//方法：中序遍历、递归、计数器剪枝
//时间复杂度：O(N)，其中 N 是二叉搜索树的节点数。

//算法原理：
//直接中序遍历二叉搜索树（递归），不仅使⽤⼤量额外空间存储数据，并且会将所有的结点都遍历⼀遍。
//但是，我们可以根据中序遍历的过程，只需扫描前 k 个结点即可。
//因此，我们可以创建⼀个全局的计数器 count，将其初始化为 k，每遍历⼀个节点就将 count--。直到某次递归的时候，count 的值等于 1，说明此时的结点就是我们要找的结果。

//算法流程：
//1. 定义⼀个全局的变量 count，在主函数中初始化为 k 的值（不⽤全局也可以，当成参数传⼊递归过程中）；
//递归函数的设计：int dfs(TreeNode * root)：返回值为第 k 个结点；

//递归函数流程（中序遍历）：
//1. 递归出⼝：空节点直接返回 -1，说明没有找到；
//2. 去左⼦树上查找结果，记为 retleft：
//    a.如果 retleft == -1，说明没找到，继续执⾏下⾯逻辑；
//    b.如果 retleft != -1，说明找到了，直接返回结果，⽆需执⾏下⾯代码（剪枝）；
//3. 如果左⼦树没找到，判断当前结点是否符合：
//    a.如果符合，直接返回结果
//4. 如果当前结点不符合，去右⼦树上寻找结果。
class Solution {
public:
    int ret = 0;                                    // 用于存储结果（第 k 小的元素）
    int count;                                      // 全局计数器，表示剩余需要查找的节点数

    int kthSmallest(TreeNode* root, int k) 
    {
        count = k;                                  // 初始化计数器为目标值 k
        dfs(root);                                  // 调用深度优先搜索函数
        return ret;                                 // 返回结果
    }

    void dfs(TreeNode* root) 
    {
        if (root == nullptr || count == 0)         // 如果当前节点为空或已经找到结果，终止递归
        {
            return;
        }

        dfs(root->left);                           // 递归查找左子树

        count--;                                   // 每访问一个节点，计数器减 1
        if (count == 0)                            // 如果计数器为 0，说明当前节点是第 k 小的节点
        {
            ret = root->val;                       // 保存结果值
            return;                                // 剪枝：直接返回，避免无意义的递归
        }

        dfs(root->right);                          // 递归查找右子树
    }
};
