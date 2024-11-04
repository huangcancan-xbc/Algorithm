// 力扣：162. 寻找峰值
// https://leetcode.cn/problems/find-peak-element/description/

// 方法一：暴力法
// 时间复杂度：O(n)

// 算法思路：
// 从第一个位置开始，遍历数组，分情况讨论（nums[-1] = nums[n] = -∞）：
// 1. 如果当前位置的值比后一个位置的值大，说明当前位置是峰值，返回当前位置；
// 2. 如果当前位置的值比后一个位置的值小，说明后一个位置是峰值，继续向后走；
// 3. 如果当前位置的值和后一个位置的值相等，说明当前位置和后一个位置都可能是峰值，继续向后走；
// 4. 如果遍历到最后一个位置，说明最后一个位置是峰值，返回最后一个位置。

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return i;           // 返回峰值的位置
            }
        }

        return n - 1;              // 返回最后一个位置
    }
};





// 方法二：二分查找
// 时间复杂度：O(logn)

// 算法思路：
// 寻找二段性：
// 1. 任取一个点 i，与下一个点 i + 1，会有如下两种情况：
//    • arr[i] > arr[i + 1] ：此时「左侧区域」一定会存在山峰（因为最左侧是负无穷），我们可以去左侧寻找结果；
//    • arr[i] < arr[i + 1] ：此时「右侧区域」一定会存在山峰（因为最右侧是负无穷），我们可以去右侧寻找结果。
// 2. 当我们找到「二段性」时，就可以用「二分查找」算法来解决问题。

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;   // 计算中间位置

            if (nums[mid] < nums[mid + 1])
            {
                left = mid + 1;                    // 向右搜索
            }
            else
            {
                right = mid;                       // 向左搜索
            }
        }

        return left;                               // 返回找到的峰值位置
    }
};
