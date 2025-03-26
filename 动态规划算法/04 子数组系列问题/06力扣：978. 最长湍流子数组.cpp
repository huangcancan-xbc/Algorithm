// 力扣：978. 最长湍流子数组
// 链接：https://leetcode.cn/problems/longest-turbulent-subarray/description/

// 方法：动态规划
class Solution
{
public:
    int maxTurbulenceSize(vector<int>& arr)
    {
        int n = arr.size();             // 获取数组的长度
        if (n == 1) return 1;           // 如果数组只有一个元素，湍流子数组的长度为 1

        // f[i] 表示以 arr[i] 为结尾呈上升趋势的最大湍流子数组长度
        // g[i] 表示以 arr[i] 为结尾呈下降趋势的最大湍流子数组长度
        vector<int> f(n, 1), g(n, 1);   // 初始化，长度为 1

        int ret = 1;                    // 结果变量，最小湍流子数组长度为 1
        for (int i = 1; i < n; i++)     // 从第二个元素开始遍历
        {
            if (arr[i - 1] < arr[i])    // 如果 arr[i] 大于 arr[i-1]，说明湍流子数组的方向是上升
            {
                f[i] = g[i - 1] + 1;    // 以 i 为结尾的湍流子数组的长度是以 i-1 为下降的子数组长度 + 1
            }
            else if (arr[i - 1] > arr[i])       // 如果 arr[i] 小于 arr[i-1]，说明湍流子数组的方向是下降
            {
                g[i] = f[i - 1] + 1;    // 以 i 为结尾的湍流子数组的长度是以 i-1 为上升的子数组长度 + 1
            }

            ret = max(ret, max(f[i], g[i]));    // 更新最大湍流子数组长度
        }

        return ret;                             // 返回结果
    }
};