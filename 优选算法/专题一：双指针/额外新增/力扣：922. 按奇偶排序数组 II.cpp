//力扣：922. 按奇偶排序数组 II
//https://leetcode.cn/problems/sort-array-by-parity-ii/description/

//算法原理：
//输入是一个包含 n 个元素的数组 nums，其中每个元素可能是奇数或偶数。
//偶数索引（如 0, 2, 4...）需要存放偶数，奇数索引（如 1, 3, 5...）需要存放奇数。
//通过遍历数组，找出那些不符合条件的元素并交换位置。
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int begin = 0, end = 1, n = nums.size();  // 初始化三个变量：begin 指向偶数索引位置，end 指向奇数索引位置，n 为数组长度

        for (begin = 0; begin < n; begin += 2)    // 循环遍历偶数索引位置 (0, 2, 4, ...)
        {
            if (nums[begin] % 2 == 1)             // 如果在偶数索引处找到奇数
            {
                while (nums[end] % 2 == 1)        // 查找奇数索引处的偶数，end 逐步增加，跳过奇数（如果 end 处的元素是奇数，继续移动 end 直到找到偶数。end 每次增加 2，确保它只遍历奇数索引位置。）
                {
                    end += 2;                     // end 每次增加 2，确保始终指向奇数索引
                }
                swap(nums[begin], nums[end]);     // 找到符合条件的偶数，交换这两个元素的位置
            }
        }

        return nums;                              // 返回排序后的数组
    }
};
