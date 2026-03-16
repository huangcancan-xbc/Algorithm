// 力扣：105. 从前序与中序遍历序列构造二叉树
// 链接：https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal

// 方法：递归/DFS
// 首先要知道一个结论：要想推导出唯一的树（或者第三个遍历），手里必须得有“中序遍历”。如果是“前序 + 后序”，是推不出来的（除非树很特殊）。
// 前序的第一个便是根节点，然后在中序中找到根节点的位置，左边是左子树，右边是右子树。
// 递归地构造左右子树，并返回根节点。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:

    unordered_map<int, int> hash;
    TreeNode* dfs(vector<int>& preorder, int pre_l, int pre_r, vector<int>& inorder, int in_l, int in_r)
    {
        if (pre_l > pre_r)
        {
            return nullptr;
        }

        int root_val = preorder[pre_l];
        TreeNode* root = new TreeNode(root_val);

        int k = hash[root_val];     // 当前根在中序的下标
        int left_size = k - in_l;   // 在中序中看左子树有多少个节点

        // pre_l, pre_r表示当前这棵子树在前序数组里的范围
        // in_l, in_r表示当前这棵子树在中序数组里的范围
        root->left = dfs(preorder, pre_l + 1, pre_l + left_size, inorder, in_l, k - 1);
        root->right = dfs(preorder, pre_l + left_size + 1, pre_r, inorder, k + 1, in_r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = preorder.size();

        for (int i = 0; i < n; i++)
        {
            hash[inorder[i]] = i;
        }

        return dfs(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};