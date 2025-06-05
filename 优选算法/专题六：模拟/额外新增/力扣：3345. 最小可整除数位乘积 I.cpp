//力扣：3345. 最小可整除数位乘积 I
//https://leetcode.cn/problems/smallest-divisible-digit-product-i/description/


//方法：暴力法
//时间复杂度：O(n^2)
class Solution {
public:
    int smallestNumber(int n, int t) 
    {
        for (int i = n; i <= n * t; i++)            //枚举所有可能的数字
        {
            int tmp = 1, sum = i;                   //注意：tmp和sum都要初始化为1，否则会出现除数为0的情况；
                                                    //还有不要直接对 i 进行操作，会影响到后面的循环，要用临时变量暂存一下
            while (sum)                             //计算数字各位的乘积
            {
                tmp *= sum % 10;
                sum /= 10;
            }

            if (tmp % t == 0)                       //如果乘积能整除 t，则返回当前数字
            {
                return i;
            }
        }

        return -1;                                  //理论上不会走到这里，但为了返回值和正确性，还是要加上
    }
};