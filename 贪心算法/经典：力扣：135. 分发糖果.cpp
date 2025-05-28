// 力扣：135. 分发糖果
// 链接：https://leetcode.cn/problems/candy/description/

// 方法：贪心
//当从前向后遍历时，需要确保当前孩子的糖果数不仅比前一个孩子多（如果评分更高），而且要刚好比它多一个。
//同理，当从后向前遍历时，需要确保这种关系也成立。
//因此，在这两个遍历过程中，应该使用max函数来确保糖果的数量是足够的。
class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();                 // 获取孩子人数
        if (n < 2)
        {
            return n;                           // 如果只有一个孩子，直接返回 1
        }
        vector<long long> v(n, 1);              // 初始化每个孩子至少分配 1 个糖果

        // 左到右遍历，确保比子上一个评分高的孩子糖果更多
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
            {
                v[i] = v[i - 1] + 1;            // 如果当前孩子评分高，糖果数 +1
            }
        }

        // 右到左遍历，确保比子下一个评分高的孩子糖果更多
        for (int i = n - 1; i > 0; i--)
        {
            if (ratings[i - 1] > ratings[i])
            {
                v[i - 1] = max(v[i] + 1, v[i - 1]);     // 如果左边评分高，确保左边糖果比右边多
            }
        }

        int ret = 0;                            // 计算总糖果数量
        for (auto x : v)
        {
            ret += x;                           // 累加每个孩子的糖果数
        }

        return ret;                             // 返回总糖果数量
    }
};