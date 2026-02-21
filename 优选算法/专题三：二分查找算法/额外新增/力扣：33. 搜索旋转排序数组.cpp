// 力扣：33. 搜索旋转排序数组
// 链接：https://leetcode.cn/problems/search-in-rotated-sorted-array/description/

// 方法：二分
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.empty())
        {
            return -1;
        }

        // 1.先找断层点
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        int m = left;

        // cout<<nums[m];

        // 2. 判断 target 在哪个区间
        if (target >= nums[m] && target <= nums.back())
        {
            left = m;
            right = nums.size() - 1;
        }
        else
        {
            left = 0;
            right = m - 1;
        }

        // 3. 二分
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};


// 优化：
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                return mid;
            }

            if (nums[left] <= nums[mid])    // 注意：这里要加=，如果数组只剩2个数，left和mid指向的是同一个数，一个数字即有序，避免误判另一边有序
            {
                // 假设目标就在有序的一边
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};