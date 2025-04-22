// 牛客：BM89 合并区间
// 链接：https://www.nowcoder.com/practice/69f4e5b7ad284a478777cb2a17fb5e6a?tpId=295&tqId=691&sourceUrl=%2Fexam%2Foj%3FquestionJobId%3D10%26subTabName%3Donline_coding_page

// 方法：贪心 + 排序

/**
 * struct Interval {
 *	int start;
 *	int end;
 *	Interval(int s, int e) : start(start), end(e) {}
 * };
 */
#include <vector>

// 自定义比较函数，用于排序
bool cmp(const Interval& a, const Interval& b)
{
    return a.start < b.start;
}

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param intervals Interval类vector
     * @return Interval类vector
     */

    vector<Interval> merge(vector<Interval>& intervals)
    {
        // write code here
        if (intervals.empty())
        {
            return {};
        }

        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();

        int left = intervals[0].start, right = intervals[0].end;
        vector<Interval> ret;

        for (int i = 1; i < n; i++)
        {
            int a = intervals[i].start, b = intervals[i].end;
            if (a <= right)
            {
                right = max(b, right);
            }
            else
            {
                ret.push_back({ left,right });
                left = a;
                right = b;
            }
        }

        ret.push_back({ left,right });

        return ret;
    }
};