// 力扣：2418. 按身高排序
// 链接：https://leetcode.cn/problems/sort-the-people/description/

// 方法一：使用二元组 (pair) 存储姓名和身高，并按身高降序排序
class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        vector<pair<int, string>> v;                    // 创建存储身高和姓名的二元组数组

        for (int i = 0; i < names.size(); i++)
        {
            v.push_back({ heights[i], names[i] });      // 将身高和姓名存入二元组数组
        }

        // 按身高降序排序（Lambda 表达式自定义比较规则）
        sort(v.begin(), v.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;                   // 按 first（即身高）降序排列
            });

        vector<string> ret;                             // 存储排序后的姓名列表
        for (auto x : v)
        {
            ret.push_back(x.second);                    // 提取排序后的姓名
        }

        return ret;
    }
};

// 优化存储结构，使用 transform 提取姓名
class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        vector<pair<int, string>> v(heights.size());    // 直接初始化指定大小的二元组数组

        for (int i = 0; i < heights.size(); i++)
        {
            v[i] = { heights[i], names[i] };            // 直接初始化 v，减少 push_back 操作，提高效率
        }

        sort(v.begin(), v.end(), greater<>());          // 按身高降序排序，默认按 first（身高）降序排序

        // 使用 transform 提取排序后的姓名
        vector<string> ret(heights.size());
        transform(v.begin(), v.end(), ret.begin(), [](const pair<int, string>& p) {
            return p.second;                            // 只提取姓名部分
            });

        /* 等价于：
        vector<string> ret;
        for (auto& p : v)
        {
            ret.push_back(p.second);
        }
        */

        return ret;
    }
};



// 方法二：用哈希表存储身高和姓名，按身高排序（注意：本题姓名不重复，所以可以用哈希表，如果有重复的姓名，则需要用 vector 存储）
class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        unordered_map<int, string> hash;                // 哈希表，存储身高和姓名

        for (int i = 0; i < names.size(); i++)
        {
            hash[heights[i]] = names[i];                // 将身高和姓名存入哈希表
        }

        sort(heights.begin(), heights.end(), greater<int>());   // 对身高进行降序排序

        vector<string> ret;
        for (int h : heights)
        {
            ret.push_back(hash[h]);                     // 根据排序后的身高从哈希表提取姓名
        }

        return ret;
    }
};



// 方法三：贪心算法，使用索引数组，对索引进行排序，避免直接操作原数组
class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        int n = names.size();                           // 获取人数

        // 创建索引数组，记录原始索引
        vector<int> index(n);
        for (int i = 0; i < n; i++)
        {
            index[i] = i;                               // 初始化索引数组，使索引与 names、heights 对应
        }

        // 按身高降序对索引数组进行排序，不直接改变 names 和 heights 的顺序
        sort(index.begin(), index.end(), [&](int i, int j)
            {
                return heights[i] > heights[j];         // 根据身高降序排序索引
            });

        // 根据排序后的索引数组提取姓名，生成排序后的姓名列表
        vector<string> ret;
        for (int i = 0; i < n; i++)
        {
            ret.push_back(names[index[i]]);             // 使用排序后的索引寻找对应 names
        }

        return ret;
    }
};