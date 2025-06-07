// ��ȣ�U535982 J-A С�ε�AB����
// ���ӣ�https://www.luogu.com.cn/problem/U535982

// ������̰�ġ�ģ�⡢ö��
// 1. ABABAB...������λ��ΪA��ż��λ��ΪB����Ҫ����λ��ȫΪA����Ҫ n - counta �ν���
// 2. BABABA...������λ��ΪB��ż��λ��ΪA����Ҫ����λ��ȫΪB������λ���� counta ��A��Ҫ���滻ΪB����Ҫ counta �ν���
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        int n = 0;
        cin >> n;

        string s;
        cin >> s;

        int counta = 0;
        for (int i = 1; i < 2 * n; i += 2)
        {
            if (s[i] == 'A')
            {
                counta++;
            }
        }

        cout << min(n - counta, counta) << endl;
    }

    return 0;
}