// 力扣：102. 二叉树的层序遍历
// 链接：https://leetcode.cn/problems/binary-tree-level-order-traversal/description/

// 方法：广搜
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        if (root == nullptr)
        {
            return ret;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> temp;               // 用于存放每一层的非空节点
            int size = q.size();            // 计算每层节点数
            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();                    // 将上一层的第i个节点出队
                temp.push_back(node->val);  // 但将上一层第i个节点的值保存下来

                // 开始处理下一层节点，只要非空就入队
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            ret.push_back(temp);            // 将当前层的节点存入结果
        }

        return ret;
    }
};