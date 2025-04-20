// 力扣：55. 跳跃游戏
// 链接：https://leetcode.cn/problems/jump-game/description/

// 方法：贪心（类似层序遍历）
// 和跳跃游戏 II 类似，只不过这里不需要考虑最少跳几次，只需要判断能否跳到最后。
class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int n = nums.size(), left = 0, right = 0, maxpos = 0;

        while (left <= right)                       // 当当前区间 [left, right] 内还可以继续跳跃时，执行循环
        {
            if (maxpos >= n - 1)
            {
                return true;                        // 如果当前的最远可达位置已经覆盖了终点说明可以跳到最后，返回 true
            }

            for (int i = left; i <= right; i++)
            {
                maxpos = max(maxpos, nums[i] + i);  // 更新最远可达位置
            }

            left = right + 1;                       // 更新下一次跳跃左边界为当前右边界 +1
            right = maxpos;                         // 更新下一次跳跃右边界为最远可达位置
        }

        return false;                               // 如果循环结束仍然没有跳到最后，说明不能跳到最后，返回 false
    }
};