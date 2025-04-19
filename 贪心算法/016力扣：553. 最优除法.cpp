// 力扣：553. 最优除法
// 链接：https://leetcode.cn/problems/optimal-division/description/

// 方法：贪心
class Solution
{
public:
    string optimalDivision(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return to_string(nums[0]);                                  // 特判：只有一个数，直接返回该数
        }
        if (n == 2)
        {
            return to_string(nums[0]) + '/' + to_string(nums[1]);       // 特判：只有两个数，直接返回两个数的商
        }

        string ret = to_string(nums[0]) + "/(" + to_string(nums[1]);    // 定义结果字符串，先将第一个数和第二个数的商写进去
        for (int i = 2; i < n; i++)
        {
            ret += '/' + to_string(nums[i]);                            // 接着将后面的数按贪心策略写进去
        }
        ret += ')';                                                     // 不要忘了加上括号

        return ret;
    }
};