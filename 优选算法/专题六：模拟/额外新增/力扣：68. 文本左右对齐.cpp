// 力扣：68. 文本左右对齐
// 链接：https://leetcode.cn/problems/text-justification/?envType=study-plan-v2&envId=top-interview-150

// 方法：模拟
// 思路：最后一行要保证左对齐，其他情况保证左右对齐
// 要先找到每行最多能放置的单词数，根据单词数的长度算出需要补的空格的数量，要保证左侧放置的空格数要多于右侧的空格数，则：
// 在保证空格总数不为0的情况下，优先分配：（空格数 / 空隙数（即单词数 - 1））向上取整的数量，最后要么正好分配要么不够分
// 不够分就是空格总数为0了，此时正好保证了左侧放置的空格数要多于右侧的空格数
class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> ret;
        int n = words.size(), i = 0;
        while (i < n)
        {
            int j = i + 1;
            int len = words[i].size();

            while (j < n && len + 1 + words[j].size() <= maxWidth)
            {
                len += 1 + words[j].size();
                j++;
            }

            string line;            // 开始构造每一行的string
            int count = j - i;      // 一行可以放置的单词个数

            // 最后一行或者只有一个单词：左对齐
            if (j == n || count == 1)
            {
                for (int k = i; k < j; k++)
                {
                    line += words[k];
                    if (k < j - 1)
                    {
                        line += " ";
                    }
                }

                // 末尾补空格
                line += string(maxWidth - line.size(), ' ');
            }
            else        // 正常情况，左右对齐
            {
                // 单词长度
                int eng_len = 0;
                for (int k = i; k < j; k++)
                {
                    eng_len += words[k].size();
                }

                // 空格总数
                int space = maxWidth - eng_len;

                int gaps = count - 1;       // 空隙数

                for (int k = i; k < j; k++)
                {
                    line += words[k];
                    if (k < j - 1)          // 不是最后一个单词
                    {
                        int value = ceil((double)space / gaps); // 理论分配当前空隙向上取整的空格数
                        value = min(value, space);              // 实际分配要保证总空格数space不为0
                        line += string(value, ' ');
                        space -= value;                         // 更新剩余空格
                        gaps--;                                 // 剩余空隙减1
                    }
                }
            }

            ret.push_back(line);
            i = j;
        }

        return ret;
    }
};