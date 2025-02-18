//力扣：98. 验证二叉搜索树
//https://leetcode.cn/problems/validate-binary-search-tree/description/


//方法一：（利⽤中序遍历）：中序遍历按照左⼦树、根节点、右⼦树的顺序遍历⼆叉树的所有节点，通常⽤于⼆叉搜索树相关题⽬。
// 二叉搜索数的中序遍历结果是一个有序的序列（是严格递增的），因此我们可以⽤中序遍历来判断⼀棵树是否是⼆叉搜索树。

//算法原理：
//如果⼀棵树是⼆叉搜索树，那么它的中序遍历的结果⼀定是⼀个严格递增的序列。因此，我们可以初始化⼀个⽆穷⼩的全区变量，
//⽤来记录中序遍历过程中的前驱结点。那么就可以在中序遍历的过程中，先判断是否和前驱结点构成递增序列，然后修改前驱结点为当前结点，传⼊下⼀层的递归中。

//算法流程：
//1. 初始化⼀个全局的变量 prev，⽤来记录中序遍历过程中的前驱结点的 val；
//2. 中序遍历的递归函数中：
//    a.设置递归出⼝：root == nullptr 的时候，返回 true；
//    b.先递归判断左⼦树是否是⼆叉搜索树，⽤ retleft 标记；
//    c.然后判断当前结点是否满⾜⼆叉搜索树的性质，⽤ retcur 标记：
//        ▪ 如果当前结点的 val ⼤于 prev，说明满⾜条件，retcur 改为 true；
//        ▪ 如果当前结点的 val ⼩于等于 prev，说明不满⾜条件，retcur 改为 false；
//    d.最后递归判断右⼦树是否是⼆叉搜索树，⽤ retright 标记；
//3. 只有当 retleft、 retcur 和 retright 都是 true 的时候，才返回 true。
class Solution {
public:
    long prev = LONG_MIN;                           // 初始化一个比最小数据范围还小的无穷小值
    bool isValidBST(TreeNode* root) 
    {
        if (root == nullptr)                        // 如果当前节点为空，直接返回 true（空树是合法的BST）
        {
            return true;
        }

        bool left = isValidBST(root->left);         // 递归检查左子树是否是合法的BST

        bool cur = false;                           // 当前节点值必须大于前一个节点值，否则返回 false
        if (root->val > prev)
        {
            cur = true;
        }
        prev = root->val;                           // 更新 prev 为当前节点值

        bool right = isValidBST(root->right);       // 递归检查右子树是否是合法的BST

        return left && right && cur;                // 只有左右子树和当前节点都合法时才返回 true
    }
};




//方法二：剪枝
class Solution {
public:
    long prev = LONG_MIN;                           // 初始化一个比最小数据范围还小的无穷小值
    bool isValidBST(TreeNode* root) {
        if (root == nullptr)                        // 如果当前节点为空，直接返回 true
        {
            return true;
        }
        
        bool left = isValidBST(root->left);         // 递归检查左子树

        if (left == false)                          // 剪枝：如果左子树不合法，直接返回 false
        {
            return false;
        }
        
        bool cur = false;                           // 检查当前节点是否合法（值必须大于前一个节点值）
        if (root->val > prev)
        {
            cur = true;
        }

        if (cur == false)                           // 剪枝：如果当前节点不合法，直接返回 false
        {
            return false;
        }

        prev = root->val;                           // 更新 prev 为当前节点值

        bool right = isValidBST(root->right);       // 递归检查右子树

        return right;                               // 因为前面已剪枝，这里直接返回右子树结果即可
    }
};
