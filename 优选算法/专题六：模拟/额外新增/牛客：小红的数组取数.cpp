// ţ�ͣ�С�������ȡ��
// ���ӣ�https://ac.nowcoder.com/acm/contest/117763/B

// �������ҹ���
//�𰸾��ǣ�A �������Сֵ�±� �� B ��������ֵ�±ꡣ

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }

    int minA = a[1], idxA = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] < minA)
        {
            minA = a[i];
            idxA = i;
        }
    }

    int maxB = b[1], idxB = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (b[i] > maxB)
        {
            maxB = b[i];
            idxB = i;
        }
    }

    cout << idxA << " " << idxB << "\n";
    return 0;
}




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> b[i];
    }

    int idxA = min_element(a.begin() + 1, a.end()) - a.begin(); // A �������Сֵ�±�
    int idxB = max_element(b.begin() + 1, b.end()) - b.begin(); // B ��������ֵ�±�

    cout << idxA << " " << idxB << endl;
    return 0;
}