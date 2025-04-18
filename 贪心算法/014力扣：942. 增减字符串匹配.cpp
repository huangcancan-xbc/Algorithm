// 力扣：942. 增减字符串匹配
// 链接：https://leetcode.cn/problems/di-string-match/description/

// 方法：贪心 + 双指针
// 1. 当遇到“I”时，选择当前最小的数
// 2. 当遇到“D”时，选择当前最大的数
class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.size();
        vector<int> ret;
        int left = 0, right = n;            // 定位当前区间的最大值和最小值

        for (auto x : s)                    // 遍历字符串
        {
            if (x == 'I')
            {
                ret.push_back(left++);      // 如果当前字符为'I'，添加当前区间的最小值，准备形成“上升”
            }
            else
            {
                ret.push_back(right--);     // 如果当前字符为'D'，添加当前区间的最大值，准备形成“下降”
            }
        }
        // 任选一个：
        ret.push_back(left);
        // ret.push_back(right);

        return ret;
    }
};