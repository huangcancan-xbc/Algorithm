//力扣：2331. 计算布尔二叉树的值
//https://leetcode.cn/problems/evaluate-boolean-binary-tree/description/


//方法：递归
//算法原理：
//本题可以被解释为：
//1. 对于规模为 n 的问题，需要求得当前节点值。
//2. 节点值不为 0 或 1 时，规模为 n 的问题可以被拆分为规模为 n - 1 的⼦问题：
//    a.所有⼦节点的值；
//    b.通过⼦节点的值运算出当前节点值。
//3. 当问题的规模变为 n = 1 时，即叶⼦节点的值为 0 或 1，我们可以直接获取当前节点值为 0 或 1。
//
//算法流程：
//递归函数设计：bool evaluateTree(TreeNode * root)
//1. 返回值：当前节点值；
//2. 参数：当前节点指针。
//3. 函数作⽤：求得当前节点通过逻辑运算符得出的值。
//递归函数流程：
//1. 当前问题规模为 n = 1 时，即叶⼦节点，直接返回当前节点值；
//2. 递归求得左右⼦节点的值；
//3. 通过判断当前节点的逻辑运算符，计算左右⼦节点值运算得出的结果；
class Solution 
{
public:
    bool evaluateTree(TreeNode* root) 
    {
        // 1. 叶子节点（n=1），直接返回值 0 或 1，分别对应 false 和 true
        if (root->left == nullptr)
        {
            return root->val == 0 ? false : true;                   
        }

        // 2. 递归获取左子树和右子树的值
        int left = evaluateTree(root->left);                            // 左子节点的值
        int right = evaluateTree(root->right);                          // 右子节点的值

        // 3. 根据当前节点的值执行逻辑运算
        //    节点值为 2：逻辑或运算（OR）
        //    节点值为 3：逻辑与运算（AND）
        return root->val == 2 ? left | right : left & right;
    }
};