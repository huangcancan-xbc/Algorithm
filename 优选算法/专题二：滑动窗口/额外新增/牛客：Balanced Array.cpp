// 牛客：Balanced Array
// 链接：https://ac.nowcoder.com/acm/contest/129231/D

// 方法：滑动窗口 + 双端队列 + 单调栈
#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        deque<int> max_q;  // 单调递减，队头是最大值下标
        deque<int> min_q;  // 单调递增，队头是最小值下标

        int left = 0;
        long long ret = 0;

        for (int right = 0; right < n; right++)
        {
            // 维护最大值队列
            while (!max_q.empty() && a[max_q.back()] <= a[right])
            {
                max_q.pop_back();
            }
            max_q.push_back(right);

            // 维护最小值队列
            while (!min_q.empty() && a[min_q.back()] >= a[right])
            {
                min_q.pop_back();
            }
            min_q.push_back(right);

            // 窗口不平衡就移动左指针
            while (a[max_q.front()] - a[min_q.front()] > 1)
            {
                left++;
                while (!max_q.empty() && max_q.front() < left)
                {
                    max_q.pop_front();
                }
                while (!min_q.empty() && min_q.front() < left)
                {
                    min_q.pop_front();
                }
            }

            ret += right - left + 1;
        }

        cout << ret << endl;
    }

    return 0;
}