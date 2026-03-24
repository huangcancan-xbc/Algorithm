// 力扣：189. 轮转数组
// 链接：https://leetcode.cn/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150

// 方法一：直接暴力（39/40，一个超时）
// 时间复杂度：O(n*k)，如果直接使用：
//nums.insert(nums.begin(), nums.end() - k, nums.end());
//nums.erase(nums.end() - k, nums.end());
// 理论上是对的，但是力扣测评应该涉及到内存拷贝导致原始迭代器失效的问题过不了，但是本地测试没问题
class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        if (k > nums.size())
        {
            k %= nums.size();
        }

        while (k--)
        {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }

        return;
    }
};



// 方法二：原地反转
// 时间复杂度：O(n)
//先把整个数组翻转一下，再把前 k 个翻转一下，最后把剩下的翻转一下
//比如 1 2 3 4 5，k = 2
//全翻变成 5 4 3 2 1
//前 2 个翻变成 4 5 3 2 1
//后 3 个翻变成 4 5 1 2 3
class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        k %= nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        return;
    }
};



// 方法三：使用额外数组
class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        k %= nums.size();
        vector<int> temp(nums.end() - k, nums.end());

        nums.insert(nums.begin(), temp.begin(), temp.end());
        nums.erase(nums.end() - k, nums.end());

        return;
    }
};