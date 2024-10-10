// ���ۣ�179. �����
// https://leetcode.cn/problems/largest-number/description/


//�ֶ�ʵ�ְ汾
// �Զ���ȽϺ�������������
bool Compare(const string& s1, const string& s2)
{
    // ͨ���Ƚ����Ӻ���ַ���������˳��
    return s1 + s2 > s2 + s1;
}

class Solution
{
public:
    // ������ת��Ϊ�ַ���
    string Format_conversion(int x)
    {
        string s;

        // ����������������Ϊ0��ֱ�ӷ���"0"
        if (x == 0)
        {
            return "0";
        }

        // ��������ÿһλתΪ�ַ�����ƴ�ӵ��ַ���s
        while (x)
        {
            char tmp = '0' + x % 10; // ȡ��ǰλ��ת��Ϊ�ַ�
            s = tmp + s; // ���ַ���ǰ������ַ�
            x /= 10; // ����10��ȥ����ǰλ
        }

        return s; // ����ת������ַ���
    }

    // �������������������
    string largestNumber(vector<int>& nums)
    {
        vector<string> s; // �����ַ����������洢ÿ�����ֵ��ַ�����ʾ

        // ��ÿ������ת��Ϊ�ַ�������������
        for (int x : nums)
        {
            s.push_back(Format_conversion(x));
        }

        // ���Զ���ȽϺ������ַ���������������
        sort(s.begin(), s.end(), Compare);

        string ret; // ���ڴ洢���ս��

        // ���������ַ���ƴ�ӳ�һ���������
        for (const string& it : s)
        {
            ret += it;
        }

        // �����������������'0'��ͷ������"0"
        if (ret[0] == '0')
        {
            return "0";
        }

        return ret; // ���ع�����������
    }
};








//ֱ��ʹ�ÿ⺯���汾
class Solution {
public:
    // ����һ������������һ���������飬����ƴ�ӳɵ��������
    string largestNumber(vector<int>& nums) {
        // ����������ת�����ַ���
        vector<string> v;
        for (int x : nums) {
            // ������ת��Ϊ�ַ�������ӵ�������
            v.push_back(to_string(x));
        }

        // �Զ����������
        sort(v.begin(), v.end(), [](const string& s1, const string& s2) {
            // �Ƚ�ƴ�ӽ������������˳��
            return s1 + s2 > s2 + s1; // ��s1+s2����s2+s1��s1����ǰ��
            });

        // ��ȡ���
        string ret;
        for (auto it : v) {
            // ���������ַ�����������
            ret += it;
        }

        // ������������������������ַ���'0'������"0"
        if (ret[0] == '0') {
            return "0"; // ȫ��������
        }

        // �������ս��
        return ret;
    }
};
