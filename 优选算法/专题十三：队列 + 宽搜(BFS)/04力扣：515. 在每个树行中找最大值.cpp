//力扣：515. 在每个树行中找最大值
//链接：https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/


//方法：BFS

//算法原理：
//层序遍历过程中，在执⾏让下⼀层节点⼊队的时候，我们是可以在循环中统计出当前层结点的最⼤值的。
//因此，可以在 bfs 的过程中，统计出每⼀层结点的最⼤值。
class Solution
{
public:
    vector<int> largestValues(TreeNode* root)
    {
        queue<TreeNode*> q;
        vector<int> ret;
        if (root == nullptr)
        {
            return ret;
        }

        q.push(root);

        while (q.size())
        {
            int size = q.size();
            int temp = INT_MIN;                 // 记录当前层的最⼤值，初始化为 INT_MIN（因为有负数）

            for (int i = 0; i < size; i++)
            {
                auto x = q.front();
                q.pop();

                // 相当于temp = max(temp, x->val)，更新当前层的最⼤值
                if (x->val > temp)
                {
                    temp = x->val;
                }

                if (x->left)
                {
                    q.push(x->left);
                }
                if (x->right)
                {
                    q.push(x->right);
                }
            }

            ret.push_back(temp);
        }

        return ret;
    }
};