//力扣：495. 提莫攻击
//https://leetcode.cn/problems/teemo-attacking/description/


//方法：模拟 + 分情况讨论
//时间复杂度：O(n)
//算法原理：
//计算相邻两个时间点的差值：
//	i.如果差值⼤于等于中毒时间，说明上次中毒可以持续 duration 秒；
//	ii.如果差值⼩于中毒时间，那么上次的中毒只能持续两者的差值。
class Solution
{
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int totalTime = 0;                                // 记录总的中毒时间

        for (int i = 1; i < timeSeries.size(); i++)       // 遍历每次攻击的时间点
        {
            int interval = timeSeries[i] - timeSeries[i - 1];  // 相邻攻击时间的间隔

            // 判断上次中毒的持续时间
            if (interval >= duration)                     // 如果间隔 >= 中毒时间
            {
                totalTime += duration;                    // 累加完整的中毒时间
            }
            else                                          // 否则，间隔 < 中毒时间
            {
                totalTime += interval;                    // 中毒持续间隔的时间
            }
        }

        return totalTime + duration;                      // 加上最后一次攻击的完整中毒时间
    }
};