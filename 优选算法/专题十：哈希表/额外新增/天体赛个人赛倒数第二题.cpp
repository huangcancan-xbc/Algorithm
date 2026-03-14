// 天体赛个人赛倒数第二题
// 无链接

//输入 t 组数据。
//每组是一串数字， -1 代表结束。
//找 3 个连着的数并且这 3 个数在整个序列里得出现至少 3 次（也就是重复了 2 次及以上）。
//找到了就输出这 3 个数，每组只输最早满足条件的那组。
//要是没找到，输出 NONE。

// 样例：
//1 2 3 10 8 7 4 6 5 4 10 8 7 66 11 10 8 7 9 -1
//输出：10 8 7，因为10 8 7 是3个连续的，并且重复出现3次
//1 2 3 4 5 6 7 9 -1
//输出：NONE，没有任何重复的


// 方法：模拟、哈希，我觉得仅考验的是 STL 的功底
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Key
{
    long a, b, c;
    bool operator==(const Key& other) const
    {
        return a == other.a && b == other.b && c == other.c;
    }
};

struct Hash
{
    size_t operator()(const Key& k) const
    {
        return hash<long>()(k.a) ^ (hash<long>()(k.b) << 1) ^ (hash<long>()(k.c) << 2);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<long> v;
        long x;
        while (cin >> x && x != -1)
        {
            v.push_back(x);
        }

        unordered_map<Key, int, Hash> mp;
        bool flag = false;
        for (size_t i = 0; i + 2 < v.size(); ++i)
        {
            Key k = { v[i], v[i + 1], v[i + 2] };
            if (++mp[k] >= 3) // 重复 2 次及以上，也就是总共出现 3 次
            {
                cout << k.a << " " << k.b << " " << k.c << endl;
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            cout << "NONE" << endl;
        }
    }

    return 0;
}



// 使用三元组 tuple
#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
using namespace std;

struct TupleHash
{
    size_t operator()(const tuple<long, long, long>& t) const
    {
        return hash<long>()(get<0>(t)) ^ (hash<long>()(get<1>(t)) << 1) ^ (hash<long>()(get<2>(t)) << 2);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<long> v;
        long x;
        while (cin >> x && x != -1)
        {
            v.push_back(x);
        }

        unordered_map<tuple<long, long, long>, int, TupleHash> mp;
        bool flag = false;
        for (size_t i = 0; i + 2 < v.size(); ++i)
        {
            auto k = make_tuple(v[i], v[i + 1], v[i + 2]);
            if (++mp[k] >= 3)
            {
                cout << get<0>(k) << " " << get<1>(k) << " " << get<2>(k) << endl;
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            cout << "NONE" << endl;
        }
    }

    return 0;
}