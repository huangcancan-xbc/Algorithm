// 力扣：380. O(1) 时间插入、删除和获取随机元素
// 链接：https://leetcode.cn/problems/insert-delete-getrandom-o1?envType=study-plan-v2&envId=top-interview-150

// 方法：哈希 + 数组
// 直接用哈希似乎有些特别的样例很卡人，理论上能行，但是不满足O(1) 时间
// 此时加入一个辅助数组便能很好的解决，将值和下标进行绑定就是优解
// 需要注意的是：这个删除操作采用的策略是将数组当前最后一个位置的值覆盖掉要删除的值的位置，
// 并更新映射关系和直接删除最后一个位置的值
class RandomizedSet
{
public:
    unordered_map<int, int> hash;        // 哈希表用记录已经存在数据的下标
    vector<int> v;

    RandomizedSet()
    {

    }

    bool insert(int val)
    {
        if (hash.count(val))
        {
            return false;
        }

        int index = v.size();
        v.push_back(val);
        hash[val] = index;

        return true;
    }

    bool remove(int val)
    {
        if (!hash.count(val))
        {
            return false;
        }

        int index = hash[val];  // 先拿出这个值的下标
        int end_val = v.back(); // 暂存数组最后一个值
        v[index] = end_val;     // 用数组最后一个值覆盖当前值
        hash[end_val] = index;  // 同步更新哈希映射

        v.pop_back();           // 删除数组最后一个值
        hash.erase(val);        // 把这个值的哈希映射删除

        return true;
    }

    int getRandom()
    {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */