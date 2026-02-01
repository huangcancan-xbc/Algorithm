// 力扣：146. LRU 缓存
// 链接：https://leetcode.cn/problems/lru-cache/description/

// 方法：哈希表 + 链表 + 模拟
class LRUCache
{
public:
    list<pair<int, int>> cache;  // 缓存数据
    list<pair<int, int>> st;     // 使用顺序，前边是新的，后面是最久未使用
    unordered_map<int, list<pair<int, int>>::iterator> st_map;  // 用于查找顺序缓存中的位置
    int sz;

    LRUCache(int capacity)
    {
        sz = capacity;    // 记录容量
    }

    int get(int key)
    {
        // 如果缓存中有该项
        if (st_map.find(key) != st_map.end())
        {
            auto it = st_map[key];      // 获取迭代器
            int value = it->second;     // 获取值

            st.splice(st.begin(), st, it);  // 移动该项到前面

            return value;
        }

        return -1;  // 没有缓存则返回-1
    }

    void put(int key, int value)
    {
        // 如果缓存中已有该项
        if (st_map.find(key) != st_map.end())
        {
            auto it = st_map[key];
            it->second = value;

            st.splice(st.begin(), st, it);  // 移动该项到前面
        }
        else
        {
            // 如果缓存已满，移除最久未使用的项
            if (st.size() == sz)
            {
                // 删除缓存的最旧项
                auto right = st.back();
                st_map.erase(right.first);  // 从映射中删除
                st.pop_back();  // 从缓存中删除
            }

            // 插入新项到缓存前面
            st.push_front({ key, value });
            st_map[key] = st.begin();
        }
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */