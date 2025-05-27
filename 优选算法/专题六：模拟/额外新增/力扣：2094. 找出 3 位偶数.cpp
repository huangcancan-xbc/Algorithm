//力扣：2094. 找出 3 位偶数
//https://leetcode.cn/problems/finding-3-digit-even-numbers/description/


//方法：暴力枚举
//时间复杂度：O(n^3)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits)
    {
        unordered_set<int> nums;                        // 结果可能存在重复，使用 unordered_set 进行去重
        int n = digits.size();

        // 枚举三位数
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i == j || i == k || j == k)     // 排除重复数字
                    {
                        continue;
                    }

                    int sum = digits[i] * 100 + digits[j] * 10 + digits[k];     // 计算数字组成的数值

                    if (sum > 99 && sum % 2 == 0)       // 排除前导零的数字和奇数数字
                    {
                        nums.insert(sum);               // 加入结果集
                    }
                }
            }
        }

        vector<int> ret;
        for (auto x : nums)                             // 排序并返回结果
        {
            ret.push_back(x);
        }

        sort(ret.begin(), ret.end());
        return ret;
    }
};