//力扣：67. 二进制求和
//链接：https://leetcode.cn/problems/add-binary/description/


//方法：模拟竖式运算
//算法原理：
//模拟⼗进制中我们列竖式计算两个数之和的过程。但是这⾥是⼆进制的求和，我们不是逢⼗进⼀，⽽是逢⼆进⼀。
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ret;

        // cur1, cur2 分别指向 a, b 最后一个字符位置，sum 记录当前位的进位
        int cur1 = a.size() - 1, cur2 = b.size() - 1, sum = 0;
        while (cur1 >= 0 || cur2 >= 0 || sum)
        {
            if (cur1 >= 0)
            {
                sum += a[cur1--] - '0';         // 减去 '0' 转为 int 类型（数字字面值）
            }
            if (cur2 >= 0)
            {
                sum += b[cur2--] - '0';
            }

            ret += sum % 2 + '0';               // 取模 2 得到当前位的值，并转为字符类型
            sum /= 2;                           // 取整除 2 得到进位值
        }

        reverse(ret.begin(), ret.end());        // 倒序输出
        return ret;
    }
};
//为什么 || sum 需要存在？
//我们在处理二进制加法时，可能存在进位的情况。
// 即使 cur1 和 cur2 都已经访问完了（即 cur1 < 0 和 cur2 < 0），进位 sum 仍然可能不为零。
// 在这种情况下，我们仍然需要继续计算并添加这个进位。
// 因此，sum 在加法完成后，可能会影响到下一次计算。