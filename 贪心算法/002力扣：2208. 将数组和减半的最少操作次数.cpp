// 力扣：2208. 将数组和减半的最少操作次数
//https://leetcode.cn/problems/minimum-operations-to-halve-array-sum/description/

//思路：贪心+大根堆
//具体策略：每次挑选当前数组中最大的数，除以2，然后将除以2的数放入大根堆中，直到数组和减半。
//这样做的原因是：每次挑选最大的数，可以保证每次除以2的数都大于等于当前数组和的一半。
//这样，我们只需要将数组中的数都除以2，然后将除以2的数放入大根堆中，最后堆中剩下的数的个数就是最少操作次数。


class Solution {
public:
    // 主函数：计算将数组和减半的最少操作次数
    int halveArray(vector<int>& nums) {
        priority_queue<double> heap; // 创建一个大根堆，用于存储当前数组中的元素
        double num = 0.0; // 用于存储数组的总和

        // 遍历数组，初始化大根堆和总和
        for (int i = 0; i < nums.size(); i++) 
        {
            int x = nums[i]; // 获取当前元素
            heap.push(x); // 将元素放入大根堆
            num += x; // 更新数组总和
        }

        int count = 0; // 操作次数计数器
        num /= 2.0; // 计算目标：数组和的二分之一

        // 当当前总和大于0时，继续进行操作
        while (num > 0) 
        {
            double tmp = heap.top() / 2.0; // 获取堆顶（当前最大的数）并除以2
            num -= tmp; // 从目标总和中减去这个值
            heap.pop(); // 移除堆顶元素
            count++; // 计数器加1，表示进行了一个操作
            heap.push(tmp); // 将减半后的数重新放入大根堆
        }

        return count; // 返回最少操作次数
    }
};
