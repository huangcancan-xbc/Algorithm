// 力扣：56. 合并区间
// 链接：https://leetcode.cn/problems/merge-intervals/description/

// 方法：贪心 + 排序

//贪心策略：
//    a.先按照区间的「左端点」排序：此时我们会发现，能够合并的区间都是连续的；
//    b.然后从左往后，按照求「并集」的方式，合并区间。
//如何求并集：由于区间已经按照「左端点」排过序了，因此当两个区间「合并」的时候，合并后的区间：
//    a.左端点就是「前一个区间」的左端点；
//    b.右端点就是两者「右端点的最大值」。
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());               // 先按照左端点排序
        int n = intervals.size();
        int left = intervals[0][0], right = intervals[0][1];    // 预存第一个区间的左右端点
        vector<vector<int>> ret;

        for (int i = 1; i < n; i++)
        {
            int a = intervals[i][0], b = intervals[i][1];       // 当前区间的左右端点
            if (a <= right)
            {
                right = max(right, b);                          // 如当前区间与上一个区间有交集，则更新右端点
            }
            else
            {
                ret.push_back({ left,right });                  // 否则，将上一个区间加入结果，并更新左右端点
                left = a;
                right = b;
            }
        }

        ret.push_back({ left,right });                          // 不要忘记最后一个区间要加入结果
        return ret;
    }
};