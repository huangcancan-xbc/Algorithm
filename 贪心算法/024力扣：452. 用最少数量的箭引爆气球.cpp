// 力扣：452. 用最少数量的箭引爆气球
// 链接：https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/

// 方法：贪心 + 排序

//贪心策略：
//    a.按照左端点排序，我们发现，排序后有这样一个性质：「互相重叠的区间都是连续的」；
//    b.这样，我们在射箭的时候，要发挥每一支箭「最大的作用」，应该把「互相重叠的区间」统一引爆。
//如何求互相重叠区间？
//由于我们是按照「左端点」排序的，因此对于两个区间，我们求的是它们的「交集」：
//    a.左端点为两个区间左端点的「最大值」（但是左端点不会影响我们的合并结果，所以可以忽略）；
//    b.右端点为两个区间右端点的「最小值」。
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        sort(points.begin(), points.end());                     // 按照左端点排序
        int right = points[0][1], ret = 1, n = points.size();   // 右端点初始化为第一个区间的右端点，ret初始化为1，n为区间数量

        for (int i = 1; i < n; i++)
        {
            int a = points[i][0], b = points[i][1];             // 取出当前区间的左右端点
            if (a <= right)
            {
                right = min(right, b);                          // 如果当前区间和上一个区间有交集，则更新右端点
            }
            else
            {
                ret++;                                          // 如果当前区间和上一个区间没有交集，则增加射箭数量
                right = b;                                      // 更新右端点
            }
        }

        return ret;
    }
};