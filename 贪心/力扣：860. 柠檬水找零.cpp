// 力扣：860. 柠檬水找零
//https://leetcode.cn/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0; // 初始化五美元和十美元的数量

        // 遍历每一个顾客支付的钞票
        for (auto x : bills)
        {
            if (x == 5) // 如果顾客给的是五美元
            {
                five++; // 直接增加五美元的数量
            }
            else if (x == 10) // 如果顾客给的是十美元
            {
                if (five == 0) // 需要找零五美元，但是没有五美元
                {
                    return false; // 无法找零，返回 false
                }
                else
                {
                    five--; // 用一张五美元找零
                    ten++;  // 收入一张十美元
                }
            }
            else if (x == 20) // 如果顾客给的是二十美元
            {
                // 优先尝试用一张十美元和一张五美元找零
                if (five && ten)
                {
                    five--; // 减少一张五美元
                    ten--; // 减少一张十美元
                }
                // 如果没有十美元，用三张五美元找零
                else if (five >= 3)
                {
                    five -= 3; // 减少三张五美元
                }
                else
                {
                    return false; // 无法找零，返回 false
                }
            }
        }

        // 遍历结束，成功给每个顾客找零，返回 true
        return true;
    }
};
