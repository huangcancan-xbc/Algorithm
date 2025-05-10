//力扣：344. 反转字符串
//https://leetcode.cn/problems/reverse-string/description/


//方法一：库函数reverse()
//时间复杂度：O(n)
class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        reverse(s.begin(), s.end());
    }
};



//方法二：双指针
//时间复杂度：O(n)
class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int left = 0, right = s.size() - 1;         //左指针 left 指向字符串的第一个字符，右指针 right 指向字符串的最后一个字符
        while (left < right)
        {
            swap(s[left++], s[right--]);            //交换左右指针所指向的字符，并将左指针向右移动，右指针向左移动
        }
    }
};