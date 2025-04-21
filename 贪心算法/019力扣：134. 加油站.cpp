// 力扣：134. 加油站
// 链接：https://leetcode.cn/problems/gas-station/description/

// 方法一：暴力法（超时）
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();

        for (int i = 0; i < n; i++)
        {
            int rest = 0;                               // 表示每次剩余油量
            for (int step = 0; step < n; step++)
            {
                int index = (i + step) % n;             // 找出每轮加油站的下标，取模防止越界
                rest = rest + gas[index] - cost[index]; // 计算剩余油量
                if (rest < 0)
                {
                    break;                              // 如果剩余油量小于0，则跳出循环
                }
            }

            if (rest >= 0)
            {
                return i;                               // 如果能到达终点，则返回起点下标
            }
        }

        return -1;                                      // 如果没有找到起点，则返回-1
    }
};


// 方法二：贪心算法
class Solution
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n = gas.size();

        for (int i = 0; i < n; i++)
        {
            int rest = 0, step = 0;
            for (; step < n; step++)
            {
                int index = (i + step) % n;
                rest = rest + gas[index] - cost[index];
                if (rest < 0)
                {
                    break;
                }
            }

            if (rest >= 0)
            {
                return i;
            }

            i = i + step;                               // 贪心优化：跳过已经尝试过的加油站
        }

        return -1;
    }
};