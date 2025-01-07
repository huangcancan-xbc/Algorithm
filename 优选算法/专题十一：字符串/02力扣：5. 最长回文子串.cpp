//力扣：5. 最长回文子串
//链接：https://leetcode.cn/problems/longest-palindromic-substring/description/


//方法：中心扩展算法
//时间复杂度：O(n^2)

//算法原理：
//枚举每⼀个可能的⼦串⾮常费时，有没有⽐较简单⼀点的⽅法呢？
//对于⼀个⼦串⽽⾔，如果它是回⽂串，并且⻓度⼤于 2，那么将它⾸尾的两个字⺟去除之后，
//它仍然是个回⽂串。如此这样去除，⼀直除到⻓度⼩于等于 2 时呢？⻓度为 1 的，⾃⾝与⾃⾝就构成回⽂；
//⽽⻓度为 2 的，就要判断这两个字符是否相等了。
//从这个性质可以反推出来，从回⽂串的中⼼开始，往左读和往右读也是⼀样的。那么，是否可以枚举
//
//回⽂串的中⼼呢？
//从中⼼向两边扩展，如果两边的字⺟相同，我们就可以继续扩展；
//如果不同，我们就停⽌扩展。这样只需要⼀层 for 循环，我们就可以完成先前两层 for 循环的⼯作量。
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int begin = 0, len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 奇数扩展
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])    // 字符相等且不越界，更新位置继续扩展
            {
                left--;
                right++;
            }
            if (right - left - 1 > len)
            {
                begin = left + 1;                   // 记录回文串的起始位置
                len = right - left - 1;             // 更新回文串的长度
            }

            // 偶数扩展
            left = i, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
            }
            if (right - left - 1 > len)
            {
                begin = left + 1;
                len = right - left - 1;
            }
        }

        return s.substr(begin, len);
    }
};
//潜在问题：
//在计算回文子串的起始位置时，begin = left 会有问题。因为 left 在退出循环时会比实际的回文串的起始位置小 1
//（因为循环条件是 left >= 0），所以我们需要调整 begin 的位置。
//
//解决方案：
//正确的 begin 应该是 left + 1，因为 left 在退出循环时会多减 1。
//
//总结：
//1. right - left - 1 计算当前回文串的长度，因为 left 和 right 在最后一轮循环时已经分别超出了回文子串的实际边界。
//2. begin 应该更新为 left + 1，这样才能确保回文串的起始位置正确。