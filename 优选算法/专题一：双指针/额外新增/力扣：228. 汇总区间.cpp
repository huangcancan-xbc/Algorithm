// 力扣：228. 汇总区间
// 链接：https://leetcode.cn/problems/summary-ranges/description/?envType=study-plan-v2&envId=top-interview-150

// 方法一：模拟
class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> ret;
        if (nums.empty())
        {
            return ret;
        }

        int start = nums[0]; // 记录当前区间的起点

        for (int i = 1; i <= nums.size(); ++i)
        {
            // 如果到末尾了，或者不连续了，就处理前面的区间
            if (i == nums.size() || nums[i] != nums[i - 1] + 1)
            {
                if (start == nums[i - 1])       // 单个数字
                {
                    ret.push_back(to_string(start));
                }
                else                            // 区间范围
                {
                    ret.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                }

                // 更新下一个区间的起点
                if (i < nums.size())
                {
                    start = nums[i];
                }
            }
        }

        return ret;
    }
};




// 方法二：模拟（“双指针”）
class Solution
{
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> ret;
        if (nums.size() == 0)
        {
            return ret;
        }

        int i = 1, j = 0;
        while (i < nums.size())
        {
            // 连续就往后走
            if (nums[i] == nums[i - 1] + 1)
            {
                i++;
            }
            else                    // 不连续了，把 [j, i-1] 这一段存进去
            {
                string temp;
                if (j == i - 1)     // 只有一个数
                {
                    temp = to_string(nums[j]);
                }
                else                // 是区间，加个箭头
                {
                    temp = to_string(nums[j]) + "->" + to_string(nums[i - 1]);
                }
                ret.push_back(temp);

                // 下一段从 i 开始
                j = i;
                i++;
            }
        }

        // 处理最后剩下的一段！
        string temp;
        if (j == i - 1)
        {
            temp = to_string(nums[j]);
        }
        else
        {
            temp = to_string(nums[j]) + "->" + to_string(nums[i - 1]);
        }
        ret.push_back(temp);

        return ret;
    }
};