// 力扣：155. 最小栈
// 链接：https://leetcode.cn/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150

// 方法：栈
// 思路：最小栈维护：把辅助栈看作一个记录最小值的序列（栈从上往下升序）
// 主栈正常存所有数据，辅助栈只在栈空或者新值小于等于当前栈顶时才压入
// 如果 pop 时的值正好是最小栈的 top，说明这个最小值被移除了，那最小栈的 top 也得跟着弹出
class MinStack
{
public:
    stack<int> st;
    stack<int> min_st;

    MinStack()
    {

    }

    void push(int val)
    {
        st.push(val);
        if (min_st.empty() || val <= min_st.top())
        {
            min_st.push(val);
        }
    }

    void pop()
    {
        if (!st.empty())
        {
            if (st.top() == min_st.top())
            {
                min_st.pop();
            }

            st.pop();
        }


    }

    int top()
    {
        return st.top();
    }

    int getMin()
    {
        return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */