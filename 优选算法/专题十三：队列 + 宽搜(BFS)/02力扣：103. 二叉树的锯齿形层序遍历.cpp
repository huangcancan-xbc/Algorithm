//力扣：103. 二叉树的锯齿形层序遍历
//链接：https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/


//方法：BFS
class Solution 
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        queue<TreeNode*> q;
        int Level = 1;                          // 层级，用于判断是否需要翻转
        if (root == nullptr)
        {
            return ret;
        }

        q.push(root);

        while (q.size())
        {
            int size = q.size();                // 计算当前层的节点数量
            vector<int> temp;                   // 临时存放当前层节点值

            for (int i = 0; i < size; i++)
            {
                auto x = q.front();
                q.pop();
                temp.push_back(x->val);         // 存放当前层节点值

                if (x->left)
                {
                    q.push(x->left);            // 如果有左子节点（不为空），入队
                }

                if (x->right)
                {
                    q.push(x->right);           // 如果有右子节点（不为空），入队
                }
            }

            if (Level % 2 == 0)
            {
                reverse(temp.begin(), temp.end());  // 如果是偶数层，需要翻转
            }

            ret.push_back(temp);                // 存放当前层节点值
            Level++;                            // 层级+1
        }

        return ret;
    }
};