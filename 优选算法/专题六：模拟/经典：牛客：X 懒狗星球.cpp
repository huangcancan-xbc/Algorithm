//牛客：X 懒狗星球
//https://ac.nowcoder.com/acm/contest/97845/J
//参赛密码：517acm


#include <iostream>
#include <string>
#include <sstream>                              // 包含stringstream类
using namespace std;

int tominute(string time)
{
    int hour = 0, minute = 0;
    char colon = ':';

    stringstream ss(time);
    ss >> hour >> colon >> minute;              // 解析时分

    return hour * 60 + minute;                  // 返回总分钟数
}

int main()
{
    int t = 0;
    cin >> t;                                   // 读取测试案例数

    while (t--)
    {
        string begin, end;
        cin >> begin >> end;                    // 读取开始和结束时间

        int begintime = tominute(begin);        // 转换开始时间为分钟
        int endtime = tominute(end);            // 转换结束时间为分钟

        // 如果结束时间小于开始时间，说明跨天，需加一天的分钟数
        if (endtime < begintime)
        {
            endtime += (24 * 60);               // 加一天的分钟数
        }

        int ret = endtime - begintime;          // 计算时间差

        int hour = ret / 60;                    // 计算小时
        int minute = ret % 60;                  // 计算分钟
        printf("%02dh%02dmin\n", hour, minute); // 输出结果
    }

    return 0;
}
