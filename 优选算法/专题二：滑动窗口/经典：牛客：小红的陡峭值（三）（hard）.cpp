// ţ�ͣ�С��Ķ���ֵ��������hard��
// ���ӣ�https://ac.nowcoder.com/acm/contest/103152/D

// ��������������
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    long long ret = 0, count = 0;

    // �ȴ����һ������
    for (int right = 1; right < k; right++)
    {
        count += abs(s[right] - s[right - 1]);
    }

    ret += count;

    // ��ʼ��������
    for (int right = k; right < n; right++)
    {
        count -= abs(s[right - k] - s[right - k + 1]);
        count += abs(s[right - 1] - s[right]);
        ret += count;
    }

    cout << ret << endl;
    return 0;
}


// �Ż���һ����λ
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    long long ret = 0, count = 0;

    for (int right = 0; right < n; right++)
    {
        if (right > 0 && right < k)
        {
            count += abs(s[right] - s[right - 1]);
            if (right == k - 1)
            {
                ret += count;
            }
        }
        else if (right >= k)
        {
            count -= abs(s[right - k] - s[right - k + 1]);
            count += abs(s[right - 1] - s[right]);
            ret += count;
        }
    }

    cout << ret << endl;
    return 0;
}