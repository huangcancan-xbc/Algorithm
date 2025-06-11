//牛客：小苯的最小整数
//https://ac.nowcoder.com/acm/contest/93847/C

//方法一：滑动窗口+字典序比较
#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int T;
    cin >> T;                                   // 读取测试用例数量
    while (T--) 
    {
        string s;
        cin >> s;                               // 读取字符串
        string ss = s + s;                      // 创建重复字符串以模拟循环
        string min = s;                         // 初始化最小字符串为原始字符串
        int len = s.length();                   // 原始字符串长度

        // 检查每一个可能的循环移位
        for (int i = 0; i < len; ++i) 
        {
            string window = ss.substr(i, len);  // 取得当前循环移位
            if (window < min)                   // 字典序比较
            { 
                min = window;                   // 更新最小字符串
            }
        }

        cout << min << endl; // 输出最小字符串
    }
    return 0;
}






//方法二：生成所有可能的循环移位并进行字典序比较
#include <iostream>
#include <string>
using namespace std;

string getMinimalRotation(const string& s) 
{
    string minRotation = s;                                 // 初始化为原字符串
    int len = s.length();

    // 生成每个可能的循环移位并进行比较
    for (int i = 1; i < len; ++i) 
    {
        string rotation = s.substr(i) + s.substr(0, i);     // 生成循环移位
        if (rotation < minRotation) 
        {
            minRotation = rotation;                         // 更新最小循环字符串
        }
    }

    return minRotation;                                     // 返回最小循环字符串
}

int main() 
{
    int T;
    cin >> T;                                               // 读取测试用例数量
    while (T--) 
    {
        string s;
        cin >> s;                                           // 读取字符串
        cout << getMinimalRotation(s) << endl;              // 输出最小循环字符串
    }
    return 0;
}
