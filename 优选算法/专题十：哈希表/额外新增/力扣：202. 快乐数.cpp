//力扣：202. 快乐数
//链接：https://leetcode.cn/problems/happy-number/description/


//方法：哈希表
//时间复杂度：O(log n)
//空间复杂度：O(log n)
class Solution 
{
public:
    // 计算一个数字各个位上数字的平方和
    int square(int n)
    {
        int sum = 0;
        while (n)
        {
            int x = n % 10;        // 取出当前数字的最后一位
            sum += x * x;          // 计算该位数字的平方，并累加到sum
            n /= 10;               // 去掉最低位，继续处理
        }
        return sum;                // 返回所有数字平方的和
    }

    // 判断一个数是否是快乐数
    bool isHappy(int n) 
    {
        unordered_set<int> hash;   // 用来存储中间结果，避免进入循环
        int sum = n;

        while (sum != 1)           // 只要sum不为1，继续计算
        {
            if (hash.count(sum))   // 如果当前sum已经在集合中，说明进入了循环
            {
                return false;
            }
            hash.insert(sum);      // 将sum加入集合
            sum = square(sum);     // 计算下一轮平方和
        }
        return true;               // 如果sum为1，说明是快乐数
    }
};
