//力扣：15. 三数之和
//https://leetcode.cn/problems/3sum/description/

//解法一：排序+暴力枚举+set去重
//时间复杂度O(n^3)，仅适用于小规模数据

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ret;   // 用set自动去重
        int n = nums.size();

        // 1. 排序，方便后续处理
        sort(nums.begin(), nums.end());

        // 2. 三重循环暴力枚举每个三元组
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    // 3. 检查当前三元组是否满足和为0
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        ret.insert({ nums[i], nums[j], nums[k] });  // 使用set去重
                    }
                }
            }
        }

        // 将set转换为vector进行返回
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};






//解法二：双指针+排序
//时间复杂度O(n^2)
//算法原理：
//1.排序
//2.固定一个数。优化：数组有序，当固定数为正数时，固定数右侧的数都大于0，就不存在和为0的三元组，直接返回。
//3.在该数后面的区间内，利用“双指针算法”快速找到两个数的和为-固定数（固定数的相反数），并将结果加入结果集中。
//双指针分别指向数组两端(固定数从数组第一个数开始，左指针从数组第二个数开始，右指针从数组最后一个数开始)，向中间移动，判断是否存在和为0的三元组

//重中之重的处理细节问题：
//1.去重：
//      -找到一种结果后，left和right指针要跳过重复元素
//      -当使用完一次双指针算法后，i也要跳过重复元素（即固定数跳过重复元素）
//      -避免越界，当数组全是0的时候，指针会一直移动导致越界，这需要进行判断
//2.不漏：
//      -找到一种结果后，不要“停”，缩小区间，继续寻找另一种结果


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;  // 存放结果的容器
        int n = nums.size();

        // 1. 排序，方便利用双指针和去重
        sort(nums.begin(), nums.end());

        // 2. 固定一个数，遍历所有可能的三元组
        for (int i = 0; i < n; )
        {
            // 如果固定数已经大于0，直接返回结果
            if (nums[i] > 0)
            {
                break;
            }

            int left = i + 1, right = n - 1;  // 初始化双指针
            int target = -nums[i];            // 目标是找和为 -nums[i] 的两个数

            // 3. 双指针寻找两个数的和等于 -nums[i]
            while (left < right)
            {
                int temp = nums[left] + nums[right];

                // 如果和大于目标值，右指针左移
                if (temp > target)
                {
                    right--;
                }
                // 如果和小于目标值，左指针右移
                else if (temp < target)
                {
                    left++;
                }
                // 如果和等于目标值，找到一个三元组
                else
                {
                    ret.push_back({ nums[i], nums[left], nums[right] });
                    left++;
                    right--;

                    // 跳过重复的left元素
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    // 跳过重复的right元素
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }

            // 跳过重复的i元素，避免三元组重复
            i++;
            while (i < n && nums[i] == nums[i - 1])
            {
                i++;
            }
        }

        return ret;
    }
};
