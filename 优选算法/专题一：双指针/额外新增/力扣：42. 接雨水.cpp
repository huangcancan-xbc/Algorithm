//力扣：42. 接雨水
//https://leetcode.cn/problems/trapping-rain-water/description/


// 方法：双指针
// 时间复杂度：O(n)
//算法原理：
//1. 初始化两个指针 left = 0和 right = height.length – 1。
//2. 当 left < right 时向中间移动两个指针 :
//• 如果 height[left] < height[right] 说明储水量依赖于 height[left] 的高度(可能构成低洼的右边界很大)
//    - 如果 height[left] > leftmax 说明没有或超出左边边界, 不构成低洼, leftmax = height[left]。
//    - 如果 height[left] <= leftmax说明构成低洼, 往答案中累加积水量。 ans += leftmax - height[left]
//    - 前进 left。 left ++
//    • 如果 height[left] >= height[right] 说明储水量依赖于 height[right] 的高度(可能构成低洼的左边界很大)
//    - 如果 height[right] > rightmax说明没有或超出右边边界, 不构成低洼, rightmax = height[right]
//    - 如果 height[right] <= rightmax 说明构成低洼, 往答案中累加积水量。 ans += rightmax - height[right]
//    前进 right。 right - -
class Solution {
public:
    int trap(vector<int>& height)
    {
        int ret = 0;
        int left = 0, right = height.size() - 1;
        int leftmax = 0, rightmax = 0;                      //左右边界的最大值
        while (left < right)
        {
            if (height[left] < height[right])               //左边界更低
            {
                if (height[left] > leftmax)                 //左边界更低, 且左边界更高
                {
                    leftmax = height[left];                 //更新左边界的最大值
                }
                else
                {
                    ret += leftmax - height[left];          //左边界更低, 但左边界更低, 积水量为左边界最大值减去当前高度
                }
                left++;                                     //前进左边界
            }
            else                                            //右边界更低
            {
                if (height[right] > rightmax)               //右边界更低, 且右边界更高
                {
                    rightmax = height[right];               //更新右边界的最大值
                }
                else
                {
                    ret += rightmax - height[right];         //右边界更低, 但右边界更低, 积水量为右边界最大值减去当前高度
                }
                right--;                                     //前进右边界
            }
        }

        return ret;
    }
};