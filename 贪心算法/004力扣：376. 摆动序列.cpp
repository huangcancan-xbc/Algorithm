//力扣：376. 摆动序列
//https://leetcode.cn/problems/wiggle-subsequence/description/


//解题思路
// 1.差值计算：遍历数组，通过计算相邻元素的差值判断序列的摆动。
// 2.摆动条件：通过 left* right <= 0 判断当前差值与上一个差值是否方向不同。若两个方向不同，说明摆动序列可延续。
//    *通过差值的符号来判断方向：
//        *方向判断：两个差值 left 和 right 的符号决定了序列的摆动方向：
//            1.如果 left 和 right 都是正数，表示序列一直在增大，不满足摆动条件。
//            2.如果 left 和 right 都是负数，表示序列一直在减小，也不满足摆动条件。
//            3.如果 left 是正数而 right 是负数，或 left 是负数而 right 是正数，表示序列发生了摆动。
//        *表达式解析：
//            1.left* right < 0 表示方向不同，即一个是正一个是负。
//            2.left * right == 0 表示至少有一个差值为零，这种情况下可以看作是首次找到差值，仍然可以计入。
//        *因此，left * right <= 0 的条件有效地涵盖了这两种情况，确保了只有在摆动发生时才增加计数。
// 3.边界处理：对于连续相等的元素，直接跳过，避免无效计数。
//这个方法高效且简洁，能正确处理大多数情况。

class Solution {
public:
    // 计算摆动序列的最长长度
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(); // 获取数组大小

        // 如果数组元素少于2，返回其大小
        if (n < 2) {
            return n;
        }

        int ret = 0; // 记录摆动序列的长度
        int left = 0; // 记录上一个非零差值

        // 遍历数组，计算相邻元素的差值
        for (int i = 0; i < n - 1; i++) {
            int right = nums[i + 1] - nums[i]; // 计算当前差值

            // 如果当前差值为零，跳过
            if (right == 0) {
                continue;
            }

            // 检查上一个差值和当前差值是否方向不同
            // left * right <= 0 说明要么 left 为零（第一次有差值），要么两个差值方向不同
            if (left * right <= 0) {
                ret++; // 计数增加
            }

            left = right; // 更新 left 为当前差值
        }

        // 返回最长摆动序列的长度
        return ret + 1; // 加一是因为起始元素也算在内
    }
};






//使用动态规划来解决这个问题。这种方法通过维护两个状态，分别表示以当前元素结尾的摆动序列的最长长度，具体如下：
//
//1.定义状态：
//    *up[i]：以 nums[i] 结尾的摆动序列的最长长度，最后一个差值为正。
//    *down[i]：以 nums[i] 结尾的摆动序列的最长长度，最后一个差值为负。
//2.状态转移：
//
//    1.如果 nums[i] > nums[i - 1]，那么：
//            *up[i] = down[i - 1] + 1（上升的情况下，必须在之前是下降）
//            *down[i] = down[i - 1]（仍然保持下降）
//    2.如果 nums[i] < nums[i - 1]，那么：
//            *down[i] = up[i - 1] + 1（下降的情况下，必须在之前是上升）
//            *up[i] = up[i - 1]（仍然保持上升）
//    3.如果相等，保持不变。
//3.结果：最终结果为 max(up[n - 1], down[n - 1])。

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) 
        {
            return n;
        }

        vector<int> up(n, 1); // 上升序列长度
        vector<int> down(n, 1); // 下降序列长度

        for (int i = 1; i < n; i++) 
        {
            if (nums[i] > nums[i - 1]) 
            {
                up[i] = down[i - 1] + 1; // 形成上升
                down[i] = down[i - 1]; // 保持下降
            }
            else if (nums[i] < nums[i - 1]) 
            {
                down[i] = up[i - 1] + 1; // 形成下降
                up[i] = up[i - 1]; // 保持上升
            }
            else 
            {
                up[i] = up[i - 1]; // 保持上升
                down[i] = down[i - 1]; // 保持下降
            }
        }

        return max(up[n - 1], down[n - 1]); // 返回最长摆动序列长度
    }
};
