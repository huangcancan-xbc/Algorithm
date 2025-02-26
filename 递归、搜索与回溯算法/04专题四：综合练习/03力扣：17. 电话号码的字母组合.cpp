//力扣：17. 电话号码的字母组合
//链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/


//方法：DFS

//算法原理：
//每个位置可选择的字符与其他位置并不冲突，因此不需要标记已经出现的字符，只需要将每个数字对应的字符依次填⼊字符串中进⾏递归，
//在回溯是撤销填⼊操作即可。在递归之前我们需要定义⼀个字典 phoneMap，记录 2~9 各⾃对应的字符。
//
//递归函数流程如下：
//1. 递归结束条件：当 index 等于 digits 的⻓度时，将 ans 加⼊到 res 中并返回；
//2. 取出当前处理的数字 digit，根据 phoneMap 取出对应的字⺟列表 letters；
//3. 遍历字⺟列表 letters，将当前字⺟加⼊到组合字符串 ans 的末尾，然后递归处理下⼀个数字（传⼊ index + 1，表⽰处理下⼀个数字）；
//4. 递归处理结束后，将加⼊的字⺟从 ans 的末尾删除，表⽰回溯。
//5. 最终返回 res 即可。
class Solution
{
public:
    // 电话键盘的字母映射，index为数字，value为对应的字母组合(定义来源：题目图片上电话按键的字母组合)
    string hash[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    string path;                                // 当前路径
    vector<string> ret;                         // 存储结果的容器

    // 深度优先搜索，pos表示当前处理的数字位置
    void dfs(const string digits, int pos)
    {
        if (path.size() == digits.size())       // 当路径长度等于数字字符串的长度时，表示已完成一组字母组合
        {
            ret.push_back(path);                // 将当前字母组合加入结果
            return;
        }

        // 遍历当前数字对应的所有字母
        for (auto x : hash[digits[pos] - '0'])
        {
            // 相当于 path.push_back(x)，但使用 += 更加简洁
            path += x;                          // 将当前字母添加到路径中

            dfs(digits, pos + 1);               // 递归处理下一个数字

            path.pop_back();                    // 回溯，移除最后一个字母
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return ret;                         // 若输入为空，直接返回空结果
        }

        dfs(digits, 0);                         // 从第一个数字开始进行深度优先搜索
        return ret;
    }
};




//STL的unordered_map替代数组hash写法：
class Solution
{
public:
    // 使用 unordered_map 来替代原来的数组 hash，存储数字和字母组合
    unordered_map<char, string> hash = {
        { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" },
        { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" }
    };

    string path;                               // 当前路径
    vector<string> ret;                        // 存储结果的容器

    // 深度优先搜索，pos表示当前处理的数字位置
    void dfs(const string digits, int pos)
    {
        if (path.size() == digits.size())      // 当路径长度等于数字字符串的长度时，表示已完成一组字母组合
        {
            ret.push_back(path);               // 将当前字母组合加入结果
            return;
        }

        // 遍历当前数字对应的所有字母
        for (auto x : hash[digits[pos]])       // 使用 unordered_map 查找当前数字对应的字母
        {
            path += x;                         // 将当前字母添加到路径中
            dfs(digits, pos + 1);              // 递归处理下一个数字
            path.pop_back();                   // 回溯，移除最后一个字母
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return ret;                        // 若输入为空，直接返回空结果
        }

        dfs(digits, 0);                        // 从第一个数字开始进行深度优先搜索
        return ret;
    }
};