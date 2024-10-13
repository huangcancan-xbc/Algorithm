//力扣：1089. 复写零
//https://leetcode.cn/problems/duplicate-zeros/description/

//算法原理：
//找到最后一个“复写”的数
//双指针算法：
//1.先判断cur的位置，如果cur位置的数不为0，dest往后移动一位，如果cur位置的数为0，dest往后移动两位
//2.决定dest向后移动的位数
//3.判断dest是否到达结束位置
//4.cur++
//5.边界情况处理：例：[1,0,2,3,0,4]，dest会走到结束后一个的越界位置，需要特殊处理
//处理方法：数组最后一个位置的数为0（即dest越界的前一个位置），cur--,dest-=2（当前位置分别回退一次）

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cur = 0, dest = -1;       // 初始化cur和dest指针，cur用于遍历数组，dest用于跟踪处理结果的位置
        int n = arr.size();           // 获取数组的大小n

        while (cur < n)               // 第一遍扫描数组，决定每个元素最终应该移动到哪里
        {
            if (arr[cur])             // 如果当前元素不是0
            {
                dest++;               // dest往后移动一位，表示复制该非零元素
            }
            else                      // 如果当前元素是0
            {
                dest += 2;            // dest往后移动两位，因为0需要被复制两次
            }

            if (dest >= n - 1)        // 检查dest是否超出数组范围（即已越界）
            {
                break;                // 超过边界后，停止扫描
            }

            cur++;                    // cur指针移动到下一个元素
        }

        // 边界情况：当最后一个元素是0时，需要特殊处理
        if (dest == n)
        {
            arr[n - 1] = 0;           // 将数组最后一位设为0
            dest -= 2;                // dest指针回退两位，处理越界
            cur--;                    // cur指针回退一位
        }

        // 从后往前复制元素，确保所有元素被正确移动
        while (cur >= 0)              // 遍历至cur为0（遍历完毕）
        {
            if (arr[cur])             // 如果当前元素不是0
            {
                arr[dest--] = arr[cur--];  // 复制非零元素到dest指针所在位置，两个指针都递减
            }
            else                      // 如果当前元素是0
            {
                arr[dest--] = 0;      // 复制一个0到dest指针
                arr[dest--] = 0;      // 再复制一个0，因为0需要复写两次
                cur--;                // cur指针递减
            }
        }
    }
};







//采用暴力解法：
//对元素为0的地方进行复写，并且后面的元素依次往后移动即可。

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (arr[i])
            {
                continue;   // 如果当前元素不是0，跳过该元素，继续下一个循环
            }

            // 当arr[i]是0时，进入此循环，将i之后的元素统一右移一位
            // 注意：arr.size()-2 覆盖最后一个元素位置，这里是边界。
            for (int j = arr.size() - 2; j > i; j--)
            {
                arr[j + 1] = arr[j];  // 将0之后的所有元素统一右移一位
            }

            arr[++i] = 0;             // 将0复写到下一个位置，并跳过复写的0
        }
    }
};
