// 力扣：12. 整数转罗马数字
// 链接：https://leetcode.cn/problems/integer-to-roman/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：直接暴力模拟（气笑了）
class Solution
{
public:
    string intToRoman(int num)
    {
        string ret;
        while (num > 0)
        {
            if (num >= 1000)
            {
                ret += "M";
                num -= 1000;
            }
            else if (num >= 900)
            {
                ret += "CM";
                num -= 900;
            }
            else if (num >= 500)
            {
                ret += "D";
                num -= 500;
            }
            else if (num >= 400)
            {
                ret += "CD";
                num -= 400;
            }
            else if (num >= 100)
            {
                ret += "C";
                num -= 100;
            }
            else if (num >= 90)
            {
                ret += "XC";
                num -= 90;
            }
            else if (num >= 50)
            {
                ret += "L";
                num -= 50;
            }
            else if (num >= 40)
            {
                ret += "XL";
                num -= 40;
            }
            else if (num >= 10)
            {
                ret += "X";
                num -= 10;
            }
            else if (num >= 9)
            {
                ret += "IX";
                num -= 9;
            }
            else if (num >= 5)
            {
                ret += "V";
                num -= 5;
            }
            else if (num >= 4)
            {
                ret += "IV";
                num -= 4;
            }
            else if (num >= 1)
            {
                ret += "I";
                num -= 1;
            }
        }

        return ret;
    }
};




// 写法优化：
class Solution
{
public:
    string intToRoman(int num)
    {
        string ret;
        vector<int> v = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
        vector<string> s = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

        for (int i = 0; i < 13; i++)
        {
            while (num >= v[i])
            {
                ret += s[i];
                num -= v[i];
            }
        }

        return ret;
    }
};