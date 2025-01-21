## TOP-K问题

在TOP-K问题中，我们需要从一组数据中找到前K个最大或最小的元素。通常可以使用多种方法来解决，例如队列（Queue）、快速选择排序（Quickselect）、堆（Heap）等。其中，使用大根堆（Max Heap）或小根堆（Min Heap）是非常常见的一种解决方式。我们可以分别讨论一下为什么使用大根堆或小根堆。

### 小根堆（Min Heap）

#### 小根堆的定义：

小根堆是一种完全二叉树结构，其中每个节点的值都小于或等于其子节点的值。

#### 为什么使用小根堆？

小根堆非常适合用于维护前K大的元素。具体原因如下：

1. **堆的根节点是当前K个元素中的最小值**。当我们遍历数据时，若新元素比堆顶的元素大，我们将堆顶元素移除，并将新元素插入堆中。这样，堆始终保持K个最大的元素，而堆顶始终是这K个元素中的最小值。
2. **时间复杂度**：每次插入或删除堆的操作时间复杂度是O(log K)，处理N个元素时，整体时间复杂度为**O(N log K)**，当K远小于N时，这种方法比排序整个数组更高效。

#### 应用场景：

- 查找一个流数据流中的前K大元素。
- 从一组不固定大小的数据中实时提取K个最大元素。

#### 示例：使用小根堆求前K大元素

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> topKElements(const vector<int>& nums, int k) 
{
    // 小根堆，默认是最小堆
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) 
    {
        minHeap.push(num);
        if (minHeap.size() > k) 
        {
            minHeap.pop();   // 保证堆的大小为K
        }
    }
    
    vector<int> result;
    while (!minHeap.empty()) 
    {
        result.push_back(minHeap.top());
        minHeap.pop();
    }
    
    return result;
}

int main() 
{
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int k = 3;
    vector<int> result = topKElements(nums, k);
    
    for (int num : result) 
    {
        cout << num << " ";
    }
    
    return 0;
}
```

在上面的示例中，我们使用小根堆来维护前3个最大的元素。

------

### 大根堆（Max Heap）

#### 大根堆的定义：

大根堆是一种完全二叉树结构，其中每个节点的值都大于或等于其子节点的值。

#### 为什么使用大根堆？

大根堆适用于找前K小的元素，原因如下：

1. **堆的根节点是当前K个元素中的最大值**。当新元素比堆顶元素小时，我们将堆顶元素移除，插入新元素，使得堆中始终保持K个最小的元素，而堆顶始终是这K个元素中的最大值。
2. **时间复杂度**：与小根堆类似，插入和删除操作的时间复杂度是O(log K)，整体时间复杂度是**O(N log K)**。

#### 应用场景：

- 查找数据流中的前K小元素。
- 维护一组数据中的K个最小值。

#### 示例：使用大根堆求前K小元素

```cpp
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> topKSmallestElements(const vector<int>& nums, int k) 
{
    // 大根堆，默认是最大堆
    priority_queue<int> maxHeap;
    
    for (int num : nums) 
    {
        maxHeap.push(num);
        if (maxHeap.size() > k) 
        {
            maxHeap.pop();   // 保证堆的大小为K
        }
    }
    
    vector<int> result;
    while (!maxHeap.empty()) 
    {
        result.push_back(maxHeap.top());
        maxHeap.pop();
    }
    
    return result;
}

int main() 
{
    vector<int> nums = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int k = 3;
    vector<int> result = topKSmallestElements(nums, k);
    
    for (int num : result) 
    {
        cout << num << " ";
    }
    return 0;
}
```

在这个例子中，我们使用大根堆来维护前3个最小的元素。

------

### 为什么不直接用大根堆或小根堆？

事实上，维护第K大元素创建小根堆，或者维护第K小元素创建大根堆是解决 **TOP-K** 问题的常见方法，但是关于为什么不直接维护第K大元素使用大根堆，或者直接维护第K小元素使用小根堆，确实是有一些细节上的考虑。

我们可以通过对比两种方法来理解为什么有时不直接用大根堆或小根堆来维护第K大或第K小元素。

#### **1. 直接使用大根堆维护第K大元素：**

可以通过以下步骤使用大根堆来找第K大的元素：

1. **构建大根堆**：将所有元素放入大根堆中。
2. **连续弹出K次**：从堆中弹出K个最大元素，第K个被弹出的元素即为第K大元素。

**缺点**：

- **时间复杂度**：构建大根堆的时间复杂度是**O(N log N)**，每次弹出堆顶元素的时间复杂度是**O(log N)**，所以总时间复杂度为**O(N log N + K log N)**。这比维护小根堆要低效，尤其是在K比N小的时候。如果K接近N，整体复杂度会接近 **O(N log N)**，这比维护一个K大小的小根堆要差。
- **不必要的堆构建**：对于TOP-K问题来说，我们并不需要全量的排序。创建一个大根堆后，要执行 **N log N** 的构建操作，而只需要找到前K个元素时，我们完全可以避免这么昂贵的操作。

#### **2. 直接使用小根堆维护第K小元素：**

类似的，可以使用小根堆来维护前K小的元素，堆顶即为当前K个元素中的最大值。

**缺点**：

- **时间复杂度**：每次维护一个小根堆的操作需要**O(log K)**时间，维护K个元素时，时间复杂度是**O(N log K)**，比全排序要高。
- **不必要的堆构建**(同上)。

---

所以，如果直接使用大根堆或小根堆来维护第K大的或第K小的元素，确实是可行的，但 **不如小根堆或大根堆的常规操作更高效**。使用堆来解决TOP-K问题的优势在于，其时间复杂度较低，特别是在K远小于N时，比起全排序更为高效。

------

### 快速选择排序（Quickselect）

使用 **快速选择排序（Quickselect）** 来解决 **TOP-K问题** 也是一种非常高效的方法，尤其是在需要查找前K个元素时。它基于 **快速排序** 的思想，但是只关注找到第K小或第K大的元素，而不是对整个数组进行排序，因此能够显著减少不必要的排序操作。它通过分区操作来逐步缩小搜索范围，直到找到目标元素。

#### 快速选择排序的步骤：

1. **选择一个主元（pivot）**：选择一个元素作为主元。
2. **分区操作**：将数组分成两部分，左侧部分小于主元，右侧部分大于主元。
3. 递归查找：
   - 如果主元正好是第K个元素，返回该元素。
   - 否则，根据主元的位置递归地在左侧或右侧子数组中查找。

#### 快速选择排序的时间复杂度：

- **平均时间复杂度**：O(N)
- **最坏时间复杂度**：O(N²)（但通过随机选择主元可以避免这种情况）
- **空间复杂度**：O(1)（原地排序）

| **复杂度类型** | **时间复杂度**  |             **空间复杂度**              |
| :------------: | :-------------: | :-------------------------------------: |
|    平均情况    |      O(N)       | O(1) (非递归实现) / O(log N) (递归实现) |
|    最坏情况    |      O(N²)      | O(1) (非递归实现) / O(log N) (递归实现) |
|   空间复杂度   | O(1) (原地排序) | O(1) (非递归实现) / O(log N) (递归实现) |

#### 快速选择排序 vs 堆 vs 排序

| **对比项**     | **快速选择排序**                                          | **堆**                                         | **排序**                       |
| :------------- | :-------------------------------------------------------- | :--------------------------------------------- | :----------------------------- |
| **时间复杂度** | 平均时间复杂度 O(N)，最坏 O(N²)                           | O(N log K)，K较小时更高效                      | O(N log N)                     |
| **空间复杂度** | O(1)（原地排序）                                          | O(K)                                           | O(N)                           |
| **适应性强**   | 对于K较小的情况非常高效，尤其在需要找第K小或第K大的元素时 | 适用于动态数据流的情况，维护前K大或前K小的元素 | 用于全排序，计算所有元素的顺序 |

#### 堆与快速选择排序的对比

| **对比项**     | **堆**                                   | **快速选择排序**                               |
| -------------- | ---------------------------------------- | ---------------------------------------------- |
| **时间复杂度** | O(N log K)                               | 平均时间复杂度 O(N)，最坏时间复杂度 O(N²)      |
| **空间复杂度** | O(K)                                     | 空间复杂度 O(1)                                |
| **适用场景**   | 适用于动态流数据中维护前 K 大或 K 小元素 | 适用于一次性处理静态数据，尤其是 K 不接近 N 时 |

#### 数据量非常大时的表现

- **快速选择排序的空间复杂度**：虽然它的平均空间复杂度为 O(log n)，但最坏情况下，递归的栈深度可能达到 O(n)，这在数据量非常大的时候会导致栈溢出，尤其是在栈空间有限的环境中。对于大规模数据集，特别是当数据非常庞大且接近排序时，空间复杂度可能会变得不可接受。
- **堆的空间复杂度**：堆的空间复杂度为 O(K)，如果 K 相对较小（比如 K 比 n 小得多），那么堆是一个比较稳定的选择。对于 TOPK 问题来说，堆的空间复杂度不会随着数据量的增大而显著增加。

#### 示例代码：快速选择排序

以下是一个简单的实现，用来找到第K大的元素：

```cpp
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void swap(vector<int>& arr, int i, int j) 
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(vector<int>& arr, int left, int right) 
{
    int pivotIndex = left + rand() % (right - left + 1);
    int pivotValue = arr[pivotIndex];
    swap(arr, pivotIndex, right);
    int storeIndex = left;

    for (int i = left; i < right; i++) 
    {
        if (arr[i] < pivotValue) 
        {
            swap(arr, storeIndex, i);
            storeIndex++;
        }
    }
    swap(arr, storeIndex, right);
    return storeIndex;
}

int quickSelect(vector<int>& arr, int left, int right, int K) 
{
    if (left == right) return arr[left];

    int pivotIndex = partition(arr, left, right);

    if (K == pivotIndex) 
    {
        return arr[K];
    } 
    else if (K < pivotIndex) 
    {
        return quickSelect(arr, left, pivotIndex - 1, K);
    } 
    else 
    {
        return quickSelect(arr, pivotIndex + 1, right, K);
    }
}

int main() 
{
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int k = 3;
    cout << "The " << k << "rd largest element is: " << quickSelect(arr, 0, arr.size() - 1, arr.size() - k) << endl;
    return 0;
}

```

### 总结

- **小根堆**适合维护前K大的元素，能够高效地处理动态数据流。
- **大根堆**适合维护前K小的元素，且处理复杂度也较为高效。
- **快速选择排序**适合找第K小或第K大的元素，尤其是在只需要获取K个元素时比排序更加高效。
- 对于 **非常大的数据集**，如果希望避免栈溢出等问题，**堆**的方法在空间方面通常比快速选择排序**更稳定**。
- 快速选择排序的空间复杂度在最坏情况下可能变得非常大（O(n)），但在平均情况下，空间复杂度为 O(log n)，比堆的 O(K) 更高效。如果 K 很小，使用堆的方法更加合适，因为堆的空间复杂度是 O(K)，而不受输入数据量大小的影响。

所以，在数据量非常大的情况下，**快速选择排序的空间复杂度有时会非常大**，尤其是在最坏情况下。如果 K 很小并且你关心空间效率，使用堆会更加合适。不同的方法适用于不同的场景，选择合适的算法取决于数据量大小、K的值以及是否需要实时更新。所以，对于**TOPK**问题一般会**优先选择堆来解决**。