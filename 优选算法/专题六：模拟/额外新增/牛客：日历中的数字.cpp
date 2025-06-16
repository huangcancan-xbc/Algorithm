//牛客：日历中的数字
//https://ac.nowcoder.com/acm/contest/98498/B


#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int is(int num, int target) 
{
    int count = 0;
    string s = to_string(num);
    char target_char = target + '0';
    for (char c : s) 
    {
        if (c == target_char) 
        {
            count++;
        }
    }
    return count;
}

bool nian(int year) 
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int tian(int year, int month) 
{
    if (month == 2) 
    {
        return nian(year) ? 29 : 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) 
    {
        return 30;
    }
    return 31;
}

int main() 
{
    int y, m, x;

    while (scanf("%d %d %d", &y, &m, &x) == 3) 
    {
        int ret = 0;
        int ttian = tian(y, m);

   
        for (int i = 1; i <= ttian; i++) 
        {
            // 构造日期字符串 "YYYY-MM-DD"
            char date[11];
            sprintf(date, "%04d-%02d-%02d", y, m, i);

            for (int i = 0; i < 10; i++) 
            {
                if (date[i] == x + '0') 
                {
                    ret++;
                }
            }
        }

        cout << ret << endl;
    }

    return 0;
}
