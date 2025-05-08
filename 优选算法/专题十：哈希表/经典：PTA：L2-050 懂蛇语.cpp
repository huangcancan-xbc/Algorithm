// PTA：L2-050 懂蛇语
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?page=1&problemSetProblemId=1781658570803388425

// 方法：哈希表 + 排序 + 字符串处理
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    getchar();                                      // 读取换行符
    unordered_map<string, vector<string>> hash;     // 存储首字母缩写对应的完整行

    while (n--)                                     // 处理 n 行
    {
        string s;
        getline(cin, s);                            // 读取一行
        istringstream ss(s);                        // 用 stringstream 来按空格分割
        string temp;
        string head;                                // 用来存储首字母缩写
        while (ss >> temp)
        {
            head += temp[0];                        // 拼接每个单词的首字母
        }

        hash[head].push_back(s);                    // 使用 head 作为键，s 作为值存储到哈希表中
    }

    // 对每个首字母缩写对应的句子列表进行排序
    for (auto& [a, b] : hash)
    {
        sort(b.begin(), b.end());                   // 按字母序排序
    }

    int m = 0;
    cin >> m;
    getchar();

    while (m--)
    {
        string s;
        getline(cin, s);                            // 读取一行查询
        istringstream ss(s);                        // 用 stringstream 来按空格分割
        string temp;
        string head;                                // 用来存储首字母缩写
        while (ss >> temp)
        {
            head += temp[0];                        // 拼接每个单词的首字母
        }

        // 查找是否有对应的缩写，如果有，输出对应的所有行
        if (hash.find(head) == hash.end())          // 如果找不到
        {
            cout << s << endl;                      // 输出原始查询内容
        }
        else
        {
            // 输出所有对应的行，使用 "|" 分隔
            const vector<string>& ret = hash[head];
            for (size_t i = 0; i < ret.size(); i++)
            {
                cout << ret[i];
                if (i != ret.size() - 1)
                {
                    cout << "|";                    // 如果不是最后一个，输出分隔符
                }
            }
            cout << endl;
        }
    }

    return 0;
}