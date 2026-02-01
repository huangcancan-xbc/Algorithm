// 力扣：236. 二叉树的最近公共祖先
// 链接：https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//如果 root == nullptr，返回 nullptr
//如果 root == p 或 root == q，返回 root
//递归 left = dfs(root->left), right = dfs(root->right)
//若 left && right，说明 p、q 在两侧，返回 root
//否则返回 left ? left : right

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr || root == p || root == q)  // !root
        {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
        {
            return root;
        }

        return left ? left : right;
    }
};