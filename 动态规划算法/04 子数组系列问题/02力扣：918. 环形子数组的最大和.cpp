// 力扣：918. 环形子数组的最大和
// 链接：https://leetcode.cn/problems/maximum-sum-circular-subarray/description/

// 方法一：动态规划
class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> f(n + 1, 0);                    // f[i] 表示以第 i 个元素结尾的普通子数组的最大和
        auto g = f;                                 // g[i] 表示以第 i 个元素结尾的普通子数组的最小和

        int fmax = INT_MIN, gmin = INT_MAX, sum = 0;// 初始化变量，用于存储最大子数组和、最小子数组和以及总和

        for (int i = 1; i <= n; i++)                // 遍历数组，计算普通子数组的最大和、最小和以及总和
        {
            // 更新 f[i]：以第 i 个元素结尾的最大子数组和
            f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);    // 当前元素单独作为子数组，或与前面的子数组结合
            fmax = max(fmax, f[i]);                 // 更新全局最大子数组和

            // 更新 g[i]：以第 i 个元素结尾的最小子数组和
            g[i] = min(nums[i - 1], g[i - 1] + nums[i - 1]);    // 当前元素单独作为子数组，或与前面的子数组结合
            gmin = min(gmin, g[i]);                 // 更新全局最小子数组和

            sum += nums[i - 1];                     // 累加总和
        }

        // 如果总和等于最小子数组和，说明所有元素都是负数，环形子数组的最大和即为普通子数组的最大和。否则，环形子数组的最大和可以通过全体元素总和减去最小子数组和得到
        return sum == gmin ? fmax : max(fmax, sum - gmin);
    }
};
// 简化写法：
class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> f(n + 1, 0);
        auto g = f;

        int fmax = INT_MIN, gmin = INT_MAX, sum = 0;
        for (int i = 1; i <= n; i++)
        {
            int x = nums[i - 1];                    // 将当前元素提取出来
            f[i] = max(x, f[i - 1] + x);
            fmax = max(fmax, f[i]);
            g[i] = min(x, g[i - 1] + x);
            gmin = min(gmin, g[i]);
            sum += x;
        }

        return sum == gmin ? fmax : max(fmax, sum - gmin);
    }
};



// 方法二：通过拼接数组和Kadane算法
class Solution
{
public:
    // 计算最大子数组和（普通的Kadane算法）
    int maxSubArraySum(vector<int>& nums)
    {
        int n = nums.size();
        int max_sum = nums[0], current_sum = nums[0];

        for (int i = 1; i < n; i++)
        {
            current_sum = max(nums[i], current_sum + nums[i]);  // Kadane算法
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }

    int maxSubarraySumCircular(vector<int>& nums)
    {
        int n = nums.size();

        // 第一步：计算数组的总和
        int sum = 0;
        for (int num : nums)
        {
            sum += num;
        }

        // 第二步：计算原始数组的最大子数组和
        int maxNormal = maxSubArraySum(nums);

        // 第三步：计算原数组的最小子数组和
        
        for (int i = 0; i < n; i++)
        {
            nums[i] = -nums[i];                     // 计算最小子数组和，方法与最大子数组和类似。将所有元素取反
        }
        int minSubArray = maxSubArraySum(nums);     // 使用已定义的maxSubArraySum来计算最小子数组和

        // 第四步：处理环形子数组的情况
        // 最大子数组和可以是普通子数组的最大和，或者是通过环绕得到的最大和（即总和 - 最小子数组和）
        // 需要排除 sum == minSubArray 的情况，因为这意味着所有元素为负，环绕没有意义
        if (sum == -minSubArray)
        {
            return maxNormal;                       // 所有元素为负时，环形子数组无效
        }

        return max(maxNormal, sum + minSubArray);   // 返回两者的较大值
    }
};
// 简化写法：
class Solution
{
public:
    int maxSubarraySumCircular(vector<int>& nums)
    {
        int max_sub = nums[0], current_max = nums[0];   // 最大子数组和的初始化
        int min_sub = nums[0], current_min = nums[0];   // 最小子数组和的初始化
        int total_sum = nums[0];                        // 数组总和的初始化
        int n = nums.size();

        for (int i = 1; i < n; ++i)
        {
            // 更新当前最大和：选择当前元素或加上当前元素
            current_max = max(nums[i], current_max + nums[i]);
            
            max_sub = max(max_sub, current_max);        // 更新全局最大和

            // 更新当前最小和：选择当前元素或加上当前元素（处理负数环绕情况）
            current_min = min(nums[i], current_min + nums[i]);
            
            min_sub = min(min_sub, current_min);        // 更新全局最小和

            total_sum += nums[i];                       // 累加总和
        }

        if (max_sub < 0)
        {
            return max_sub;                             // 如果所有数都是负数，最大子数组和即为最大的负数
        }
        else
        {
            
            return max(max_sub, total_sum - min_sub);   // 比较非环形子数组的最大和与环形子数组可能的最大和
        }
    }
};