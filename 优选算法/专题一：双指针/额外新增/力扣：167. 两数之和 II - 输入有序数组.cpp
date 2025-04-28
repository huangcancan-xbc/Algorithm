//力扣：167. 两数之和 II - 输入有序数组
//https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/description/


//方法一：暴力法
//时间复杂度：O(n^2)

//无法通过最后一个测试样例，超时
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++)
        {
            for (int j = i + 1; j < numbers.size(); j++)
            {
                if (numbers[i] + numbers[j] == target)
                {
                    return { i + 1,j + 1 };
                }
            }
        }
        return {};
    }
};



//方法二：双指针法
//时间复杂度：O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)           // 找到了两个数，就返回对应的下标
            {
                return { left + 1,right + 1 };
            }
            else if (numbers[left] + numbers[right] < target)       // 左边的数太小了，右移
            {
                left++;
            }
            else                                                    // 右边的数太大了，左移
            {
                right--;
            }
        }

        return {};
    }
};



//方法三：二分查找法
//时间复杂度：O(logn)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); i++)
        {
            int left = i + 1, right = numbers.size() - 1;           // 左右指针
            while (left <= right)
            {
                int mid = left + (right - left) / 2;                // 计算中间位置
                if (numbers[mid] == target - numbers[i])            // 如果中间位置的数等于目标值减去当前数，就找到了两个数，就返回对应的下标
                {
                    return { i + 1,mid + 1 };
                }
                else if (numbers[mid] < target - numbers[i])        // 目标值减去当前数太小了，右移
                {
                    left = mid + 1;
                }
                else                                                // 目标值减去当前数太大了，左移
                {
                    right = mid - 1;
                }
            }
        }

        return {};
    }
};