//力扣：303. 区域和检索 - 数组不可变
//https://leetcode.cn/problems/range-sum-query-immutable/description/


//方法：前缀和
class NumArray 
{
public:
    vector<int> v;                              // 前缀和数组
    NumArray(vector<int>& nums)
    {
        int n = nums.size();                    // 数组大小
        v.resize(n + 1);                        // 前缀和数组大小为数组大小+1

        for (int i = 0; i < n; i++)
        {
            v[i + 1] = v[i] + nums[i];          // 计算前缀和
        }
    }

    int sumRange(int left, int right)
    {
        return v[right + 1] - v[left];          // 计算区间和
    }
};




class NumArray 
{
public:
    vector<int> v;                              // 前缀和数组
    NumArray(vector<int>& nums)
    {
        int n = nums.size();
        v.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            v[i] = v[i - 1] + nums[i - 1];      // 计算前缀和
        }
    }

    int sumRange(int left, int right)
    {
        return v[right + 1] - v[left];          // 计算区间和
    }
};