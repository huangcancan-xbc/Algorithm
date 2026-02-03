// 力扣：15. 三数之和
// 链接：https://leetcode.cn/problems/3sum/description/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i && nums[i] == nums[i - 1])
            {
                continue;
            }

            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                {
                    r--;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    ret.push_back({ nums[i], nums[l], nums[r] });
                    while (l < r && nums[l] == nums[++l]);
                    while (l < r && nums[r] == nums[--r]);
                }
            }
        }

        return ret;
    }
};