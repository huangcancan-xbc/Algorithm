// PTA：L1-042 日期格式化
// 链接：https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805088529268736&page=0

// 方法：字符串
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string s;
    cin >> s;

    string month = s.substr(0, 2);
    string day = s.substr(3, 2);
    string year = s.substr(6, 4);

    cout << year << '-' << month << '-' << day << endl;

    return 0;
}


#include <iostream>
#include <cstdio>           // 用于 sscanf 解析字符串
using namespace std;

int main()
{
    char input[11];         // 存储输入的日期字符串，例如 "03-15-2017"
    int mm, dd, yyyy;

    cin >> input;           // 读取输入

    sscanf(input, "%d-%d-%d", &mm, &dd, &yyyy);     // 解析字符串，按照 "mm-dd-yyyy" 格式拆分成三个整数
    printf("%04d-%02d-%02d\n", yyyy, mm, dd);       // 按照 "yyyy-mm-dd" 格式输出，保证月和日是两位数

    return 0;
}


// 流提取的几种写法：

#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    string s;
    cin >> s;

    stringstream ss(s);
    int year = 0, month = 0, day = 0;
    char char1, char2;

    ss >> month >> char1 >> day >> char2 >> year;
    printf("%4d-%02d-%02d\n", year, month, day);

    return 0;
}


#include <iostream>
using namespace std;
int main()
{
    int mm, dd, yyyy;
    char dash1, dash2;          // 存储 `-`

    // 直接从 `cin` 读取时解析
    cin >> mm >> dash1 >> dd >> dash2 >> yyyy;

    printf("%04d-%02d-%02d\n", yyyy, mm, dd);

    return 0;
}


#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    string date;
    cin >> date;

    istringstream ss(date);
    string mm, dd, yyyy;

    // 使用 getline 按 `-` 号拆分字符串
    getline(ss, mm, '-');
    getline(ss, dd, '-');
    getline(ss, yyyy, '-');

    cout << yyyy << "-" << mm << "-" << dd << endl;

    return 0;
}


#include <iostream>
#include <istream>
using namespace std;
int main()
{
    string year, month, day;

    getline(cin, month, '-');
    getline(cin, day, '-');
    getline(cin, year);

    cout << year << '-' << month << '-' << day << endl;

    return 0;
}