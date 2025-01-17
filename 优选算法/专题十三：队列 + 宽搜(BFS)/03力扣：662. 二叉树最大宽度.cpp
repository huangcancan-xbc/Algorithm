//力扣：662. 二叉树最大宽度
//链接：https://leetcode.cn/problems/maximum-width-of-binary-tree/description/


//方法一：硬来（暴力解法）
//算法原理：
//1. 第⼀种（会超过内存限制）：
//既然统计每⼀层的最⼤宽度，我们优先想到的就是利⽤层序遍历，把当前层的结点全部存在队列⾥⾯，
//利⽤队列的⻓度来计算每⼀层的宽度，统计出最⼤的宽度。但是，由于空节点也是需要计算在内的。
//因此，我们可以选择将空节点也存在队列⾥⾯。这个思路是我们正常会想到的思路，
//但是极端境况下，最左边⼀条⻓链，最右边⼀条⻓链，我们需要存⼏亿个空节点，会超过最⼤内存限制。





//方法二：BFS（模拟队列）

//算法原理：
//2. 第⼆种（利⽤⼆叉树的顺序存储 - 通过根节点的下标，计算左右孩⼦的下标）：
//依旧是利⽤层序遍历，但是这⼀次队列⾥⾯不单单存结点信息，
//并且还存储当前结点如果在数组中存储所对应的下标（在我们学习数据结构 - 堆的时候，计算左右孩⼦的⽅式）。
//这样我们计算每⼀层宽度的时候，⽆需考虑空节点，只需将当层结点的左右结点的下标相减再加 1 即可。
//
//但是，这⾥有个细节问题：如果⼆叉树的层数⾮常恐怖的话，我们任何⼀种数据类型都不能存下下标的值。但是没有问题，因为
//• 我们数据的存储是⼀个环形的结构；
//• 并且题⽬说明，数据的范围在 int 这个类型的最⼤值的范围之内，因此不会超出⼀圈；
//• 因此，如果是求差值的话，我们⽆需考虑溢出的情况。
class Solution 
{
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        vector<pair<TreeNode*, unsigned int>> q;                // 模拟队列，用于存储节点及其对应的"位置"标识
        q.push_back({ root,1 });                                // 初始化队列，根节点位置标识为1,(因为节点的数目范围是 [1, 3000],不存在为空的情况)
        unsigned int ret = 0;                                   // 记录二叉树每一层的最大宽度

        while (q.size())
        {
            auto& [x1, y1] = q[0];                              // 获取当前层(每一层)的第一个节点及其位置标识
            // 相当于auto& [x1, y1] = q.front();

            auto& [x2, y2] = q.back();                          // 获取当前层（每一层）的最后一个节点及其位置标识
            ret = max(ret, y2 - y1 + 1);                        // 更新最大宽度，y2 - y1 + 1是当前层的宽度

            vector<pair<TreeNode*, unsigned int>> temp;         // 临时队列，用于存储下一层的节点及其位置

            for (auto& [x, y] : q)                              // 遍历当前层(每一层)的所有节点
            {
                if (x->left)
                {
                    temp.push_back({ x->left,2 * y });          // 如果左子节点存在，就将左子节点位置标识为2 * y加入临时队列
                }
                if (x->right)
                {
                    temp.push_back({ x->right,2 * y + 1 });     // 如果右子节点存在，就将右子节点位置标识为2 * y + 1加入临时队列
                }
            }

            q = temp;                                           // 直接覆盖 q，即将下一层的节点队列赋值给q
        }

        return ret;
    }
};

//位置标识从 0 开始存：
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        vector<pair<TreeNode*, unsigned int>> q;
        q.push_back({ root,0 });                                // 初始化队列，根节点位置标识为0
        unsigned int ret = 0;

        while (q.size())
        {
            auto& [x1, y1] = q.front();
            auto& [x2, y2] = q.back();
            ret = max(ret, y2 - y1 + 1);

            vector<pair<TreeNode*, unsigned int>> temp;
            for (auto& [x, y] : q)
            {
                if (x->left)
                {
                    temp.push_back({ x->left,2 * y + 1 });      // 左子节点位置标识为2 * y + 1
                }
                if (x->right)
                {
                    temp.push_back({ x->right,2 * y + 2 });     // 右子节点位置标识为2 * y + 2
                }
            }

            q = temp;
        }

        return ret;
    }
};




//方法三：BFS（队列）
class Solution 
{
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned int>> q;
        q.push({ root, 1 });                                    // 初始化队列，根节点位置为1

        unsigned int ret = 0;                                   // 使用 unsigned int 类型，确保与右边界位置一致

        while (q.size())
        {
            int size = q.size();                                // 当前层的节点个数
            unsigned int left = q.front().second;               // 当前层最左节点的位置标识
            unsigned int right = q.back().second;               // 当前层最右节点的位置标识

            ret = max(ret, right - left + 1);                   // 更新最大宽度，right - left + 1 为当前层的宽度

            // 遍历当前层的所有节点
            for (int i = 0; i < size; ++i)
            {
                TreeNode* x = q.front().first;
                unsigned int y = q.front().second;              // 当前节点的位置标识
                q.pop();

                if (x->left)
                {
                    q.push({ x->left, 2 * y });                 // 如果左子节点存在，就将左子节点的位置标识为2 * y加入队列
                }
                if (x->right)
                {
                    q.push({ x->right, 2 * y + 1 });            // 如果右子节点存在，就将右子节点的位置标识为2 * y + 1加入队列
                }
            }
        }

        return ret;
    }
};
