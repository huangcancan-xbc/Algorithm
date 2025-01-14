//力扣：946. 验证栈序列
//链接：https://leetcode.cn/problems/validate-stack-sequences/description/


//方法：栈

//算法原理：
//⽤栈来模拟进出栈的流程。
//⼀直让元素进栈，进栈的同时判断是否需要出栈。当所有元素模拟完毕之后，如果栈中还有元素，
//那么就是⼀个⾮法的序列。否则，就是⼀个合法的序列。
class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> st;
        int i = 0, n = popped.size();

        for (auto x : pushed)
        {
            st.push(x);                                     // 让元素一直进栈

            while (st.size() && st.top() == popped[i])      // 如果栈顶元素等于出栈序列的当前元素
            {
                st.pop();                                   // 就出栈
                i++;                                        // 更新出栈序列的指针
            }
        }

        return i == n;                                      // 如果有不能出栈的元素，栈就不为空，指针长度也不会等于出栈序列的长度
    }
};