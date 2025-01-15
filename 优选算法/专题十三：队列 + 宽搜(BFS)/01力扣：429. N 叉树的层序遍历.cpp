//力扣：429. N 叉树的层序遍历
//链接：https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/


//方法：BFS
class Solution 
{
public:
    vector<vector<int>> levelOrder(Node* root)
    {
        vector<vector<int>> ret;                    // 定义结果数组
        queue<Node*> q;                             // 定义队列

        if (root == nullptr)                        // 空树直接返回
        {
            return ret;
        }

        q.push(root);                               // 将根节点入队

        while (q.size())
        {
            int size = q.size();                    // 计算当前层节点数（每一层的节点数）
            vector<int> temp;

            for (int i = 0; i < size; i++)
            {
                Node* x = q.front();
                q.pop();
                temp.push_back(x->val);             // 分别将当前层节点的值存入临时数组

                for (auto child : x->children)      // 再将当前层节点的孩子节点入队（遍历下一层节点）
                {
                    if (child != nullptr)
                    {
                        q.push(child);              // 如果孩子节点不为空，则入队
                    }
                }
            }

            ret.push_back(temp);                    // 将当前层节点存入结果数组（将每一层的结果存入数组）
        }

        return ret;
    }
};