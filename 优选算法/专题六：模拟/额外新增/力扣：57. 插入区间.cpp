// 力扣：57. 插入区间
// 链接：https://leetcode.cn/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：数组模拟
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> ret;
        int i = 0, n = intervals.size();

        while (i < n && intervals[i][1] < newInterval[0])
        {
            ret.push_back(intervals[i]);
            i++;
        }

        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ret.push_back(newInterval);

        while (i < n)
        {
            ret.push_back(intervals[i]);
            i++;
        }

        return ret;
    }
};