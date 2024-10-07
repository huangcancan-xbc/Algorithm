// ���ۣ�860. ����ˮ����
//https://leetcode.cn/problems/lemonade-change/description/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0; // ��ʼ������Ԫ��ʮ��Ԫ������

        // ����ÿһ���˿�֧���ĳ�Ʊ
        for (auto x : bills)
        {
            if (x == 5) // ����˿͸���������Ԫ
            {
                five++; // ֱ����������Ԫ������
            }
            else if (x == 10) // ����˿͸�����ʮ��Ԫ
            {
                if (five == 0) // ��Ҫ��������Ԫ������û������Ԫ
                {
                    return false; // �޷����㣬���� false
                }
                else
                {
                    five--; // ��һ������Ԫ����
                    ten++;  // ����һ��ʮ��Ԫ
                }
            }
            else if (x == 20) // ����˿͸����Ƕ�ʮ��Ԫ
            {
                // ���ȳ�����һ��ʮ��Ԫ��һ������Ԫ����
                if (five && ten)
                {
                    five--; // ����һ������Ԫ
                    ten--; // ����һ��ʮ��Ԫ
                }
                // ���û��ʮ��Ԫ������������Ԫ����
                else if (five >= 3)
                {
                    five -= 3; // ������������Ԫ
                }
                else
                {
                    return false; // �޷����㣬���� false
                }
            }
        }

        // �����������ɹ���ÿ���˿����㣬���� true
        return true;
    }
};
