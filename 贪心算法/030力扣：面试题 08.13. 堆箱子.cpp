// 力扣：面试题 08.13. 堆箱子
// 链接：https://leetcode.cn/problems/pile-box-lcci/description/

// 方法：动态规划（和俄罗斯套娃信封问题有异曲同工之妙）
class Solution
{
public:
    int pileBox(vector<vector<int>>& box)
    {
        // 先对箱子进行排序：按照长（length）→ 宽（width）→ 高（height）降序排列，确保排序后箱子按体积从大到小排列，方便后续动态规划判断堆叠关系
        sort(box.begin(), box.end(), [&](const vector<int>& v1, const vector<int>& v2) {
            if (v1[0] != v2[0])                             // 首先按长度降序排序
            {
                return v1[0] > v2[0];
            }
            if (v1[1] != v2[1])                             // 若长度相同，按宽度降序排序
            {
                return v1[1] > v2[1];
            }
            
            return v1[2] > v2[2];                           // 若长度和宽度都相同，按高度降序排序
            });

        int n = box.size();                                 // 箱子数量
        vector<int> dp(n);                                  // dp[i] 表示以第 i 个箱子为顶时的最大堆叠高度
        int ret = 0;                                        // 记录最大堆叠高度

        for (int i = 0; i < n; i++)                         // 初始化 dp 数组，每个箱子单独堆放时的高度就是它本身的高度
        {
            dp[i] = box[i][2];                              // 初始状态：只放当前箱子
        }

        for (int i = 0; i < n; i++)                         // 动态规划：遍历每个箱子 i，将它放在 j 号箱子之上时，更新最大高度
        {
            for (int j = 0; j < i; j++)
            {
                // 如果 i 号箱子的长、宽、高都严格小于 j 号箱子，才能放在 j 的上面
                if (box[j][0] > box[i][0] && box[j][1] > box[i][1] && box[j][2] > box[i][2])
                {
                    
                    dp[i] = max(dp[i], dp[j] + box[i][2]);  // 更新 dp[i]：取当前高度和加上 i 号箱子的高度后的最大值
                }
            }
            
            ret = max(ret, dp[i]);                          // 更新最大堆叠高度
        }

        return ret;                                         // 返回最大堆叠高度
    }
};