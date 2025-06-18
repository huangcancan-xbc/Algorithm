// 力扣：2712. 使所有字符相等的最小成本
// 链接：https://leetcode.cn/problems/minimum-cost-to-make-all-characters-equal/description/

// 方法：字符串
// 思路（摘自灵神）：
//如果 s[i−1]!= s[i]，那么必须反转，不然这两个字符无法相等。
//    要么反转前缀 s[0] 到 s[i−1]，成本为 i。
//    要么反转后缀 s[i] 到 s[n−1]，成本为 n−i。
//反转后 s[i−1] = s[i]。
//
//注意到，反转操作只会改变 s[i−1] 与 s[i] 是否相等，不会改变其他相邻字符是否相等（相等的都反转还是相等，
//不相等的都反转还是不相等），所以每对相邻字符其实是互相独立的，我们只需要分别计算这些不相等的相邻字符的最小成本，即 min(i, n−i)，累加即为答案。
class Solution
{
public:
    long long minimumCost(string s)
    {
        int n = s.size();
        long long ret = 0;

        for (int i = 1; i < n; i++)
        {
            if (s[i] != s[i - 1])
            {
                ret += min(i, n - i);
            }
        }

        return ret;
    }
};