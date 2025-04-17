// 力扣：870. 优势洗牌（田忌赛马问题）
// 链接：https://leetcode.cn/problems/advantage-shuffle/description/

// 方法：贪心 + “按身高排序”
class Solution
{
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums2.size();
        sort(nums1.begin(), nums1.end());           // 对 nums1 进行升序排序，方便后续利用最小值和次优解

        vector<int> index(n);
        for (int i = 0; i < n; i++)
        {
            index[i] = i;                           // 创建 nums2 的索引数组 index，用于记录 nums2 原始下标位置
        }

        // 按照 nums2 的值升序对索引数组 index 进行排序，这样可以按照 nums2 的从小到大顺序，逐一匹配 nums1 的最佳值
        sort(index.begin(), index.end(), [&](int i, int j)
            {
                return nums2[i] < nums2[j];
            });

        vector<int> ret(n);                         // 创建结果数组 ret，保存最终的优势洗牌结果
        int left = 0, right = n - 1;                // 使用双指针策略，left 指向 nums2 中当前最小值的位置，right 指向最大值的位置

        // 遍历 nums1（已排序），逐个分配给 nums2 的最佳位置
        for (auto x : nums1)
        {
            // 若当前 nums1 的值 x 能击败 nums2 的最小值（nums2[index[left]]），则将 x 分配给 nums2 的最小值对应位置，获取优势
            if (x > nums2[index[left]])
            {
                ret[index[left++]] = x;
            }
            // 若无法击败，则把 x 分配给 nums2 的最大值位置（田忌赛马策略），用次优解去“消耗”掉 nums2 的较大值，保留更强的值去击败对方的小值
            else
            {
                ret[index[right--]] = x;
            }
        }

        return ret;                                 // 返回最终优势洗牌的结果数组
    }
};