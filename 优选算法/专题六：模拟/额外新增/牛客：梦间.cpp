// ţ�ͣ��μ�
// ���ӣ�https://ac.nowcoder.com/acm/contest/106318/B

// ��������ѧģ��
#include <iostream>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;
        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;

        // ������
        if (((b1 + c1) / 2 == 0 && a1 == 0) || ((a1 + c1) / 2 == 0 && b1 == 0) || ((a1 + b1) / 2 == 0 && c1 == 0))
        {
            cout << "YES" << endl;
            continue;
        }
        // ������
        if (((b2 + c2) / 2 == 0 && a2 == 0) || ((a2 + c2) / 2 == 0 && b2 == 0) || ((a2 + b2) / 2 == 0 && c2 == 0))
        {
            cout << "YES" << endl;
            continue;
        }

        cout << "NO" << endl;
    }

    return 0;
}