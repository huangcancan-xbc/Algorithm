// 力扣：179. 最大数
// https://leetcode.cn/problems/largest-number/description/


//手动实现版本
// 自定义比较函数，用于排序
bool Compare(const string& s1, const string& s2)
{
    // 通过比较连接后的字符串来决定顺序
    return s1 + s2 > s2 + s1;
}

class Solution
{
public:
    // 将整数转换为字符串
    string Format_conversion(int x)
    {
        string s;

        // 特殊情况：如果输入为0，直接返回"0"
        if (x == 0)
        {
            return "0";
        }

        // 将整数的每一位转为字符，并拼接到字符串s
        while (x)
        {
            char tmp = '0' + x % 10; // 取当前位并转换为字符
            s = tmp + s; // 在字符串前面添加字符
            x /= 10; // 除以10，去掉当前位
        }

        return s; // 返回转换后的字符串
    }

    // 主函数：构造最大数字
    string largestNumber(vector<int>& nums)
    {
        vector<string> s; // 创建字符串向量来存储每个数字的字符串表示

        // 将每个整数转换为字符串并存入向量
        for (int x : nums)
        {
            s.push_back(Format_conversion(x));
        }

        // 按自定义比较函数对字符串向量进行排序
        sort(s.begin(), s.end(), Compare);

        string ret; // 用于存储最终结果

        // 将排序后的字符串拼接成一个大的数字
        for (const string& it : s)
        {
            ret += it;
        }

        // 特殊情况：如果结果以'0'开头，返回"0"
        if (ret[0] == '0')
        {
            return "0";
        }

        return ret; // 返回构造的最大数字
    }
};








//直接使用库函数版本
class Solution {
public:
    // 定义一个函数，输入一个整数数组，返回拼接成的最大数字
    string largestNumber(vector<int>& nums) {
        // 将所有数字转换成字符串
        vector<string> v;
        for (int x : nums) {
            // 将整数转换为字符串并添加到向量中
            v.push_back(to_string(x));
        }

        // 自定义排序规则
        sort(v.begin(), v.end(), [](const string& s1, const string& s2) {
            // 比较拼接结果，决定排序顺序
            return s1 + s2 > s2 + s1; // 若s1+s2大于s2+s1，s1排在前面
            });

        // 提取结果
        string ret;
        for (auto it : v) {
            // 将排序后的字符串连接起来
            ret += it;
        }

        // 处理特殊情况：如果结果的首字符是'0'，返回"0"
        if (ret[0] == '0') {
            return "0"; // 全是零的情况
        }

        // 返回最终结果
        return ret;
    }
};
