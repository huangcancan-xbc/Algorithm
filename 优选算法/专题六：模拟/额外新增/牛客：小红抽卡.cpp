// ţ�ͣ�С��鿨
// ���ӣ�https://ac.nowcoder.com/acm/contest/117763/C

// ������ģ�� + ��ѧ��֦
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n, k, x;
    cin >> n >> k >> x;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    // �����û� P��λ�� i -> ��λ��
    vector<int> P(n + 1);
    // �ѵ� x �����Ƶ���ǰ
    P[x] = 1;
    // ǰ x-1 ��������������һ��
    for (int i = 1; i < x; i++) P[i] = i + 1;
    // ����ı������˳��
    for (int i = x + 1; i <= n; i++) P[i] = i;

    // ret[pos] = �����ڸ�λ�õ���
    vector<int> ret(n + 1, 0);
    vector<int> vis(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }

        // �ҵ���
        vector<int> huan;
        int cur = i;
        while (!vis[cur])
        {
            vis[cur] = 1;
            huan.push_back(cur);
            cur = P[cur];
        }

        int L = huan.size();
        // �ڻ����ƶ� k mod L ��
        for (int j = 0; j < L; j++)
        {
            int temp = huan[j];
            int to = huan[(j + k % L) % L];
            ret[to] = a[temp];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ret[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}