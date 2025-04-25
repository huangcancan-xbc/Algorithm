// 力扣：1054. 距离相等的条形码
// 链接：https://leetcode.cn/problems/distant-barcodes/description/

// 方法：贪心
class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes)
    {
        unordered_map<int, int> hash;               // 哈希表，用于统计每种条形码的出现次数
        int maxval = 0, maxcount = 0;               // maxval 记录出现最多的条形码，maxcount 记录它的出现次数
        int n = barcodes.size();                    // n 为条形码的数量

        for (auto x : barcodes)                     // 统计每个条形码的出现次数，并更新出现次数最多的条形码
        {
            
            if (maxcount < ++hash[x])               // 如果当前条形码的出现次数大于 maxcount，则更新 maxval 和 maxcount
            {
                maxval = x;
                maxcount = hash[x];
            }
        }

        int index = 0;                              // 创建索引，用于填充结果数组
        vector<int> ret(n);                         // 结果数组，存储重新排列后的条形码

        for (int i = 0; i < maxcount; i++)          // 将出现次数最多的条形码放置到结果数组中的偶数索引位置
        {
            ret[index] = maxval;                    // 填充条形码
            index += 2;                             // 索引递增 2，确保是偶数位置
        }

        hash.erase(maxval);                         // 删除 maxval，以便后续处理其他条形码

        for (auto& [x, y] : hash)                   // 处理剩余的条形码，将它们按照出现次数依次放置到数组中
        {
            for (int i = 0; i < y; i++)
            {
                
                if (index >= n)                     // 如果当前索引超过数组长度，重新从奇数位置开始填充
                {
                    index = 1;                      // 重新从奇数位置开始填充
                }

                ret[index] = x;                     // 填充当前条形码
                index += 2;                         // 索引递增 2，确保是奇数位置
            }
        }

        return ret;                                 // 返回重新排列后的条形码
    }
};