//力扣：127. 单词接龙（LCR 108. 单词接龙）
//链接：https://leetcode.cn/problems/word-ladder/description/
//（https://leetcode.cn/problems/om3reC/description/）


//方法：BFS

//算法原理：和上题一样，只是把单词变成了字符串，然后用字符串的操作来替换字符，然后判断是否在hash表中。
class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> vis;
        unordered_set<string> hash(wordList.begin(), wordList.end());

        if (!hash.count(endWord))
        {
            return 0;
        }

        queue<string> q;
        q.push(beginWord);
        vis.insert(beginWord);
        int ret = 1;

        while (q.size())
        {
            int size = q.size();
            ret++;

            while (size--)
            {
                string t = q.front();
                q.pop();

                for (int i = 0; i < t.size(); i++)
                {
                    string temp = t;

                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        temp[i] = ch;

                        if (!vis.count(temp) && hash.count(temp))
                        {
                            if (temp == endWord)
                            {
                                return ret;
                            }

                            q.push(temp);
                            vis.insert(temp);
                        }
                    }
                }
            }
        }

        return 0;
    }
};