### 小 demo

![小demo](https://cdn.jsdelivr.net/gh/huangcancan-xbc/Drawing-bed@master/Algorithm/image-20250223160240088.png)

代码示例：

```cpp
#include <iostream>
#include <vector>

using namespace std;

// 题目：求出一个数组中“最大值”出现的“次数”
// 要求：一次遍历解决问题

int main()
{
    vector<int> nums = { 7, 2, 7, 9, 8, 1, 1, 2, 9, 0, 6, 9, 1 };
    int maxval = nums[0], count = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == maxval)
        {
            count++;
        }
        else if (nums[i] > maxval)
        {
            maxval = nums[i], count = 1;
        }
    }

    cout << maxval << " " << count;
}
```

