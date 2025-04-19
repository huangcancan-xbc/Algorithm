// 力扣：455. 分发饼干（2410. 运动员和训练师的最大匹配数）
// 链接：https://leetcode.cn/problems/assign-cookies/description/

// 方法：贪心
// 先将两个数组排序
// 针对胃口小的孩子，从小到大挑选饼干：
//    1. 如果饼干尺寸刚好满足，则吃掉该饼干，并继续下一个孩子（最小的饼干都能满足，就不要浪费大饼干了）
//    2. 如果饼干尺寸大于胃口，则跳过该饼干，继续下一个孩子（胃口大的孩子，小饼干无法满足；当前的饼干连小胃口的孩子都无法满足，就更别说那些胃口大的孩子了）
class Solution
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)
    {
        sort(g.begin(), g.end());               // 先对g排序
        sort(s.begin(), s.end());               // 再对s排序

        int ret = 0, n = g.size(), m = s.size();
        for (int i = 0, j = 0; i < n && j < m; i++, j++)
        {
            while (j<m && g[i]>s[j])
            {
                j++;                            // 如果在合法范围内，尺寸小于胃口，就 j++ 去尝试下一个饼干
            }

            if (j < m)
            {
                ret++;                          // 上面已经排除了不能被吃的饼干，所以剩下的都是可以吃的
            }
        }

        return ret;
    }
};


// 力扣：2410. 运动员和训练师的最大匹配数
// 链接：https://leetcode.cn/problems/maximum-matching-of-players-with-trainers/description/
class Solution
{
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int ret = 0, n = players.size(), m = trainers.size();
        for (int i = 0, j = 0; i < n && j < m; i++, j++)
        {
            while (j<m && players[i]>trainers[j])
            {
                j++;
            }
            if (j < m)
            {
                ret++;
            }
        }

        return ret;
    }
};