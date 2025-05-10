//力扣：541. 反转字符串 II
//https://leetcode.cn/problems/reverse-string-ii/description/


// 方法一：模拟法
// 时间复杂度：O(n)，n 是字符串的长度，每次处理最多 k 个字符，循环次数为 n/(2k)。
class Solution {
public:
    string reverseStr(string s, int k)
    {
        int n = s.size();                       // 获取字符串长度
        for (int i = 0; i < n; i += k * 2)
        {
            // 反转每段前 k 个字符
            // 起始位置为 s.begin() + i
            // 结束位置取 min(i + k, n)，避免越界
            reverse(s.begin() + i, s.begin() + min(i + k, n));
        }

        return s;                               // 返回处理后的字符串
    }
};





// 方法二：双指针法
// 时间复杂度：O(n)，n 是字符串的长度，每次处理最多 k 个字符，循环次数为 n/(2k)。
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        for (int i = 0; i < n; i += k * 2)                  //设置步长为2k
        {
            int left = i, right = min(i + k - 1, n - 1);    //设置左右指针，同时确保不会越界和交叉
            while (left < right)
            {
                swap(s[left++], s[right--]);                //交换字符
            }
        }

        return s;
    }
};