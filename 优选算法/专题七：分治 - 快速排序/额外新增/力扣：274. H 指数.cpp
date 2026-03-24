// 力扣：274. H 指数
// 链接：https://leetcode.cn/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：排序
// 对于题意我感觉非常模糊，有点难理解，但是可以隐约感觉到：
// 想让我们找一个数，这个目标数要保证数组中大于这个目标数的值的个数等于这个目标数
// 感觉有点抽象了……
class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());

        int ret = 0;
        for (int i = 0; i < citations.size(); i++)
        {
            if (citations[i] < i + 1)
            {
                break;
            }

            ret++;
        }

        return ret;
    }
};