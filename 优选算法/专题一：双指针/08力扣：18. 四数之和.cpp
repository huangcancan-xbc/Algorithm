//力扣：18. 四数之和
//https://leetcode.cn/problems/4sum/description/
//这道题与力扣：15. 三数之和非常相似，只不过多了一个维度。算法原理基本一致。


//解法一：排序+暴力枚举
//时间复杂度O(n^4)，最简单的思路往往超时不能通过。
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ret;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        // 四重循环枚举四个数
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int q = k + 1; q < n; q++) {
                        // 使用 long long 来计算四数之和，避免溢出
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[q];
                        if (sum == target) {
                            ret.insert({ nums[i], nums[j], nums[k], nums[q] });
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};






//解法二：排序+双指针
//时间复杂度O(n^3)
//算法原理：
//1.依次固定一个数a
//2.在a后面的区间内，利用“三数之和”找到三个数，使这三个数的和等于target-a即可
//      -依次固定一个数b
//      -在b后面的区间内，利用“双指针”找到两个数，使这两个数的和等于target-a-b即可
//**处理细节问题**
//1.去重：
//      -找到一种结果后，left和right指针要跳过重复元素
//      -当使用完一次双指针算法后，j也要跳过重复元素（即固定数跳过重复元素），当使用完一次三数之和算法后，i也要跳过重复元素
//2.不漏：
//      -找到一种结果后，不要“停”，缩小区间，继续寻找另一种结果


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;  // 保存最终的结果

        sort(nums.begin(), nums.end());  // 先对数组进行排序
        int n = nums.size();  // 获取数组的长度

        // 第一个循环，固定第一个元素
        for (int i = 0; i < n;) 
        {
            // 第二个循环，固定第二个元素
            for (int j = i + 1; j < n;) 
            {
                int left = j + 1;           // 左指针从j的下一个数开始，此时相当于三数之和，左指针指向固定数的后一个位置
                int right = n - 1;          // 右指针从数组末尾开始
                long long sum = (long long)target - nums[i] - nums[j];
                // 计算剩余两个数的目标和，即target减去nums[i]和nums[j]，为保证数据范围，使用long long类型，避免溢出

                // 双指针，寻找符合条件的两个数
                while (left < right) 
                {
                    int temp = nums[left] + nums[right];  // 当前左右指针的和

                    if (temp > sum) 
                    {
                        right--;  // 如果当前和大于目标，右指针左移
                    }
                    else if (temp < sum) 
                    {
                        left++;   // 如果当前和小于目标，左指针右移
                    }
                    else if (temp == sum) 
                    {
                        // 如果找到四个数的和等于目标
                        ret.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        left++, right--;  // 更新指针，继续寻找下一个可能的解

                        // 跳过重复元素
                        while (left < right && nums[left] == nums[left - 1]) 
                        {
                            left++;  // 确保left指针指向不同的元素
                        }
                        while (left < right && nums[right] == nums[right + 1]) 
                        {
                            right--;  // 确保right指针指向不同的元素
                        }
                    }
                }

                //对第二个数（b）进行去重
                j++;
                while (j < n && nums[j] == nums[j - 1]) 
                {
                    j++;
                }
            }

            //对第一个数(a)进行去重
            i++;
            while (i < n && nums[i] == nums[i - 1]) 
            {
                i++;
            }
        }

        return ret;
    }
};
