//牛客：宝石手串（牛客周赛 Round 71）
//链接：https://ac.nowcoder.com/acm/contest/97443/B


#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

// 核心函数：计算最短非重叠子串长度
int is(string& s)
{
    int n = s.size();
    int len = INT_MAX;                          // 初始化最小长度为最大值
    unordered_map<char, int> map;               // 用于记录字符上次出现的位置
    string ss = s + s;                          // 模拟环形字符串

    for (int right = 0; right < ss.size(); ++right)
    {
        char c = ss[right];
        if (map.count(c))
        {
            len = min(len, right - map[c] - 1); // 计算当前窗口的子串长度并更新最小值
        }
        
        map[c] = right;                         // 更新字符的最新出现位置
    }

    
    return (len + 2 > n) ? -1 : len;            // 如果找到的最小长度不符合条件，返回 -1
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ret = is(s);
        cout << ret << endl;
    }

    return 0;
}





#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    while (n--) 
    {
        int m;
        string k;
        cin >> m >> k;

        unordered_map<char, int> map;            // 用于记录字符上次出现的位置
        int ans = m;                             // 初始化结果为字符串长度
        string s = k + k;
        int right = 0;                           // 遍历字符串的指针

        while (right < s.size()) 
        {
            // 如果字符已出现，计算当前子串长度，并更新最小值
            if (map.count(s[right])) 
            {
                ans = min(ans, right - map[s[right]] - 1);
            }

            map[s[right]] = right;               // 更新字符的最新出现位置
            right++;
        }

        // 检查答案是否符合条件
        if (ans + 2 > m) 
        {
            ans = -1;
        }
        
        cout << ans << endl;
    }

    return 0;
}
