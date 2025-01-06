//���ۣ�14. �����ǰ׺
//���ӣ�https://leetcode.cn/problems/longest-common-prefix/description/


//����һ�������Ƚ�
//ʱ�临�Ӷȣ�O��nm)

//˼·��
//1. ��ȡ��һ���ַ����ĵ�һ���ַ����������ַ������ν��бȽ�
//2. �����ͬ�Ҳ������϶��ַ����ĳ��ȣ�������Ƚ���һ���ַ�
//3. �����ͬ���򷵻ص�ǰ�ַ�����ǰ׺
//4. ֱ�������ַ������Ƚ��꣬�򷵻������ǰ׺
class Solution 
{
public:
    string common_prefix(string& s1, string& s2)
    {
        int i = 0;                                      // ��¼�ַ�����ͬ�ĳ���
        while (s1[i] == s2[i] && i < min(s1.size(), s2.size()))//����Ҳ�Խ��
        {
            i++;                                        //���ӳ��ȣ������Ƚ�
        }

        return s1.substr(0, i);                         // ��ȡǰ׺
    }

    string longestCommonPrefix(vector<string>& strs)
    {
        string ret = strs[0];                           // ȡ��һ���ַ�����Ϊ��ʼֵ
        for (int i = 1; i < strs.size(); i++)           // �����������ַ����Ƚ�
        {
            ret = common_prefix(ret, strs[i]);          // ��Ҫ�Ƚϵ������ַ�
        }

        return ret;
    }
};

class Solution 
{
public:
    string common_prefix(string& s1, string& s2)
    {
        int i = 0;
        string ret;                                     // ��¼����ǰ׺���𰸣�
        while (s1[i] == s2[i] && i < min(s1.size(), s2.size()))
        {
            ret += s1[i];                               // ����ͬ���ַ���ӵ�����ǰ׺��
            i++;
        }

        return ret;
    }

    string longestCommonPrefix(vector<string>& strs)
    {
        string ret = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            ret = common_prefix(ret, strs[i]);
        }

        return ret;
    }
};




//��������ͳһ�Ƚϣ�����ɨ�裩
//ʱ�临�Ӷȣ�O(nm)

//˼·��
//1. ȡ��һ���ַ����ĵ�һ���ַ����������ַ������ν��бȽ�
//2. �����ͬ�Ҳ������϶��ַ����ĳ��ȣ�������Ƚ���һ���ַ�
//3. �����ͬ���򷵻ص�ǰ�ַ�����ǰ׺
//4. ֱ�������ַ������Ƚ��꣬�򷵻������ǰ׺
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        for (int i = 0; i < strs[0].size(); i++)        //��һ���ַ���
        {
            char temp = strs[0][i];                     //ȡ��һ���ַ�
            for (int j = 1; j < strs.size(); j++)       //�����ַ���
            {
                if (i == strs[j].size() || strs[j][i] != temp)  // Խ�����ͬ������ǰ׺
                {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];                                 // �����ַ�������ͬ�����ص�һ���ַ���
    }
};