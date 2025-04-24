// 力扣：354. 俄罗斯套娃信封问题
// 链接：https://leetcode.cn/problems/russian-doll-envelopes/description/

// 方法一：动态规划（通用方法）（和堆箱子有异曲同工之妙）
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        sort(envelopes.begin(), envelopes.end());               // 先根据宽度升序排序
        int n = envelopes.size();
        vector<int> dp(n, 1);                                   // dp[i]：代表以第 i 个信封为结尾的所有的套娃序列中，最长的套娃序列长度
        int ret = 1;                                            // 记录最大值，默认只有一个信封长度为 1 的套娃序列

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                // 如果第 i 个信封能包裹第 j 个信封
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);              // 更新 dp[i] 为当前最大值
                }
            }

            ret = max(ret, dp[i]);                              // 更新整个dp数组的最大值
        }

        return ret;
    }
};


// 方法二：重写排序 + 贪心 + 二分
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        // 重新排序：宽度升序，容量降序，确保宽度相同时只能被套一次
        sort(envelopes.begin(), envelopes.end(), [&](const vector<int>& v1, const vector<int>& v2)
            {
                return v1[0] != v2[0] ? v1[0]<v2[0] : v1[1]>v2[1];
            });

        vector<int> ret;                                        // 记录所有的套娃序列的最大值
        ret.push_back(envelopes[0][1]);                         // 第一个信封的容量作为第一个套娃序列的最大值

        for (int i = 1; i < envelopes.size(); i++)
        {
            int b = envelopes[i][1];                            // 当前信封的高度

            if (b > ret.back())
            {
                ret.push_back(b);                               // 如果 b 大于当前子集封中最大高度，直接加入
            }
            else
            {
                int left = 0, right = ret.size() - 1;           // 开始二分查找，找到第一个大于等于 b 的位置
                while (left < right)
                {
                    int mid = (left + right) / 2;
                    if (ret[mid] >= b)
                    {
                        right = mid;                            // 如果 mid 位置的高度大于等于 b，则更新 right 为 mid
                    }
                    else
                    {
                        left = mid + 1;                         // 如果 mid 位置的高度小于 b，则更新 left 为 mid+1
                    }
                }

                ret[left] = b;                                  // 找到的位置更新为 b
            }
        }

        return ret.size();                                      // 返回套娃序列的个数
    }
};