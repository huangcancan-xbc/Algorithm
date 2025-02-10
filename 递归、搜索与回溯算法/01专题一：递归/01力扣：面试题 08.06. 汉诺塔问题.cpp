//力扣：面试题 08.06. 汉诺塔问题
//https://leetcode.cn/problems/hAnota-lcci/description/


//方法一：不讲武德版，直接上代码：
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        C = A; // 直接将 A 的内容赋值给 C
    }
};




//方法二：递归
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        bfs(A, B, C, A.size());                             // 调用递归函数，将 A 中的 n 个盘子移动到 C
    }

    void bfs(vector<int>& A, vector<int>& B, vector<int>& C, int n)
    {
        if (n == 1)                                         // 基本情况：如果只有一个盘子，直接从 A 移动到 C
        {
            C.push_back(A.back());                          // 将 A 栈顶元素加入到 C
            A.pop_back();                                   // 从 A 中移除栈顶元素
            return;                                         // 返回结束递归
        }

        // 步骤 1：将 n-1 个盘子从 A 移动到 B，借助 C 作为辅助柱
        bfs(A, C, B, n - 1);                                
        
        // 步骤 2：将第 n 个盘子从 A 移动到 C
        C.push_back(A.back());                              // 将 A 栈顶元素加入到 C
        A.pop_back();                                       // 从 A 中移除栈顶元素

        // 步骤 3：将 n-1 个盘子从 B 移动到 C，借助 A 作为辅助柱
        bfs(B, A, C, n - 1);

    }
};