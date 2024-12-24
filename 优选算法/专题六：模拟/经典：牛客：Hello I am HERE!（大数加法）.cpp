//牛客：Hello I am HERE!（大数加法）
//https://ac.nowcoder.com/acm/contest/98498/F


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string add(const string& s1, const string& s2)
{
    int len1 = s1.size(), len2 = s2.size();
    vector<int> arr(max(len1, len2) + 1, 0);            // 结果数组，长度为较长数字+1（考虑进位）

    int carry = 0;                                      // carry 表示进位
    int k = arr.size() - 1;                             // 从结果数组的最后一位开始存储结果
    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0; i--, j--, k--)
    {
        // 如果 i 或 j 已经小于 0，则对应的数字记为 0
        int step1 = (i >= 0) ? s1[i] - '0' : 0;
        int step2 = (j >= 0) ? s2[j] - '0' : 0;

        int cur = step1 + step2 + carry;                // 当前位的和
        arr[k] = cur % 10;                              // 当前位结果
        carry = cur / 10;                               // 计算进位
    }

    string ret;
    bool is = true;                                     // 是否还在处理前导零
    for (auto x : arr)
    {
        if (is && x == 0)                               // 如果前面都是零，则跳过
        {
            continue;
        }

        is = false;                                     // 遇到第一个非零数时结束跳过
        ret.push_back(x + '0');
    }

    return ret.empty() ? "0" : ret;                     // 如果结果为空，返回 "0"
}

int main()
{
    int n = 0;
    cin >> n;

    while (n--)
    {
        string s1, s2;
        cin >> s1 >> s2;                                // 输入两组大数
        cout << add(s1, s2) << endl;                    // 输出加法结果
    }

    return 0;
}