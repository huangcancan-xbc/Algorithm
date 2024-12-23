//牛客：233（大数乘法）
//https://ac.nowcoder.com/acm/contest/98498/E


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string multiplication(const string& s1, const string s2)
{
    int len1 = s1.size(), len2 = s2.size();             // 字符串长度
    vector<int> ret(len1 + len2, 0);                    // 构建结果数组 

    for (int i = len1 - 1; i >= 0; i--)
    {
        for (int j = len2 - 1; j >= 0; j--)
        {
            int cur = (s2[j] - '0') * (s1[i] - '0');    // 计算当前位的乘积
            int sum = cur + ret[i + j + 1];             // 计算当前位的和

            ret[i + j + 1] = sum % 10;                  // 当当前位的和大于9时，需要进位，将取余结果保存到此
            ret[i + j] += sum / 10;                     // 进位的位置等于当前位乘积 + 进位值
        }
    }

    string ans;
    for (auto x : ret)
    {
        if (!(ans.empty() && x == 0))                   // 如果字符串不为空且当前位不为0，则添加到结果字符串中
        {
            ans.push_back(x + '0');
        }
    }

    return ans.empty() ? "0" : ans;                     // 如果结果字符串为空，则返回"0"
}

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;                                // 以字符串形式读入两个数

        cout << multiplication(s1, s2) << endl;         // 输出结果
    }

    return 0;
}