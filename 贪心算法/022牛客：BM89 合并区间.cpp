// ţ�ͣ�BM89 �ϲ�����
// ���ӣ�https://www.nowcoder.com/practice/69f4e5b7ad284a478777cb2a17fb5e6a?tpId=295&tqId=691&sourceUrl=%2Fexam%2Foj%3FquestionJobId%3D10%26subTabName%3Donline_coding_page

// ������̰�� + ����

/**
 * struct Interval {
 *	int start;
 *	int end;
 *	Interval(int s, int e) : start(start), end(e) {}
 * };
 */
#include <vector>

// �Զ���ȽϺ�������������
bool cmp(const Interval& a, const Interval& b)
{
    return a.start < b.start;
}

class Solution
{
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param intervals Interval��vector
     * @return Interval��vector
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