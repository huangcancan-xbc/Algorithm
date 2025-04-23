// 力扣：435. 无重叠区间
// 链接：https://leetcode.cn/problems/non-overlapping-intervals/description/

// 方法：贪心 + 排序

//贪心策略：
//    a.按照「左端点」排序；
//    b.当两个区间「重叠」的时候，为了能够「在移除某个区间后，保留更多的区间」，我们应该把「区间范围较大」的区间移除。
//如何移除区间范围较大的区间：由于已经按照「左端点」排序了，因此两个区间重叠的时候，我们应该移除「右端点较大」的区间，
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());               // 先按照区间左端点排序
        int left = intervals[0][0], right = intervals[0][1];    // 预存第一个区间的左右端点
        int ret = 0, n = intervals.size();                      // 记录需要删除的区间数和计算区间数

        for (int i = 1; i < n; i++)
        {
            int a = intervals[i][0], b = intervals[i][1];       // 当前区间的左右端点
            if (a < right)
            {
                ret++;
                right = min(right, b);                          // 如果当前区间与上一个区间有重叠，则更新右端点，并记录需要删除的区间数
            }
            else
            {
                right = b;                                      // 如果当前区间与上一个区间无重叠，则更新右端点
            }
        }

        return ret;
    }
};