//力扣：43. 字符串相乘（大数乘法）
//链接：https://leetcode.cn/problems/multiply-strings/description/


//方法一：模拟竖式乘法
//算法原理：整体思路就是模拟⼩学列竖式计算两个数相乘的过程
class Solution 
{
public:
    string multiply(string num1, string num2)
    {
        int len1 = num1.size(), len2 = num2.size();             // 字符串长度
        vector<int> ret(len1 + len2, 0);                        // 构建结果数组 

        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                int cur = (num2[j] - '0') * (num1[i] - '0');    // 计算当前位的乘积
                int sum = cur + ret[i + j + 1];                 // 计算当前位的和

                ret[i + j + 1] = sum % 10;                      // 当当前位的和大于9时，需要进位，将取余结果保存到此
                ret[i + j] += sum / 10;                         // 进位的位置等于当前位乘积 + 进位值
            }
        }

        string ans;
        for (auto x : ret)
        {
            if (!(ans.empty() && x == 0))                       // 如果字符串不为空且当前位不为0，则添加到结果字符串中
            {
                ans.push_back(x + '0');
            }
        }

        return ans.empty() ? "0" : ans;                         // 如果结果字符串为空，则返回"0"
    }
};




//方法二：无进位相乘，然后相加，最后处理进位
//算法原理：在计算两数相乘的时候，先不考虑进位，等到所有结果计算完毕之后，再去考虑进位。
class Solution 
{
public:
    string multiply(string num1, string num2)
    {
        // 先无进位相乘，再相加，最后处理进位
        reverse(num1.begin(), num1.end());                      // 反转 num1
        reverse(num2.begin(), num2.end());                      // 反转 num2
        string ret;                                             // 用于存储最终结果
        vector<int> temp(num1.size() + num2.size(), 0);         // 临时存储每位相乘的结果

        // 先无进位相乘，然后相加
        for (int i = 0; i < num1.size(); i++)
        {
            for (int j = 0; j < num2.size(); j++)
            {
                temp[i + j] += (num1[i] - '0') * (num2[j] - '0'); // num1[i] 和 num2[j] 逐位相乘，并累加到 temp[i + j]
            }
        }

        // 处理进位
        int cur = 0, sum = 0;                                   // cur 为当前处理的位置，sum 为进位
        while (cur < num1.size() + num2.size() || sum != 0)
        {
            if (cur < num1.size() + num2.size())
            {
                sum += temp[cur++];                             // 将 temp[cur] 加到进位 sum 中，并向后移动 cur
            }
            ret += sum % 10 + '0';                              // 将当前位的数字加入结果字符串
            sum /= 10;                                          // 更新进位
        }

        // 处理前导零
        while (ret.size() > 1 && ret.back() == '0')
        {
            ret.pop_back();                                     // 删除结果字符串中的前导零
        }

        reverse(ret.begin(), ret.end());                        // 反转结果字符串，恢复正确顺序
        return ret;
    }
};
//ret.size() > 1：
//确保 ret 中不止一个字符。这样做是为了防止单独的 0 被错误地去除。
//如果 ret 中只有一个字符，且这个字符是 '0'，我们不希望去掉它，因为 "0" 是合法的结果。如果去掉了 "0"，会导致错误的结果。
//    如果 ret 中只有一个字符，即 0，那就不需要去除，因为数字 0 本身就表示 0。
//    如果 ret 中有多个字符，但最后一个字符是 0，就说明可能有多余的前导零。