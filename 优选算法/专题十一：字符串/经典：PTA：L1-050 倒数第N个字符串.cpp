// PTA��L1-050 ������N���ַ���
// ���ӣ�https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805080346181632&page=0

// �������ַ���ģ�⡢26����
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int l, n;
    cin >> l >> n;
    string s;
    int sum = pow(26, l) - n;       // ���������� sum + 1 ���ַ�������0��ʼ��

    while (sum > 0)
    {
        s += sum % 26 + 'a';        // ȡ��ǰ���λ
        sum /= 26;                  // ȥ�����λ
    }

    while (s.size() < l)
    {
        s += 'a';                   // ��ȫǰ�� 'a'���൱�������е�ǰ���㣩
    }

    reverse(s.begin(), s.end());    // ��ת�ַ�������Ϊ֮ǰ�Ǵӵ�λ����λ�����

    cout << s << endl;
    return 0;
}