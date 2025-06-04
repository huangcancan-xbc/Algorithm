// ţ�ͣ��Ƿ��ϣ�����û����
// ���ӣ�https://ac.nowcoder.com/acm/contest/98971/H

// ��������̬�滮
//1. ״̬��ʾ
//���� dp[i][j] ��ʾ����ǰ i ������ʱ����Ϊ j �������е������������ i ���Դ� 0 �� n��j ���Դ� 0 �� target��
//
//2. ״̬ת�Ʒ���
//����ÿ������ nums[i - 1]����Ϊ���������� 0 ��ʼ��������������ѡ��
//    1. ��ѡ������֣���ô dp[i][j] ��ֵ���� dp[i - 1][j]���������ǵ�ǰ����ʱ��Ϊ j ��������������
//    2. ѡ������֣���� j >= nums[i - 1]����ô dp[i][j] ��ֵ����Ҫ���� dp[i - 1][j - nums[i - 1]]�������ǵ�ǰ����ʱ����Ϊ j - nums[i - 1] ��������������
//��ˣ�״̬ת�Ʒ���Ϊ��dp[i][j] = dp[i - 1][j] + (j��nums[i - 1] ? dp[i - 1][j - nums[i - 1]] : 0)
//
//3. ��ʼ��
//dp[0][0] = 1����ʾ����ǰ 0 ������ʱ����Ϊ 0 ���������� 1 �������������У���
//dp[0][j] = 0������ j > 0������ʾ����ǰ 0 ������ʱ����Ϊ j > 0 �������в����ڡ�
//
//4. ���˳��
//ͨ�������ǰ�˳����ÿ�����֣�i �� 1 �� n��������ÿ�� i���ٿ������п��ܵĺ� j �� 0 �� target��
//
//5. ����ֵ
//���յĽ���� dp[n][target]������������ n ������ʱ����Ϊ target ��������������


// �����ά DP���ڴ泬�ޣ���
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int main()
{
    int n = 0;
    cin >> n;

    long long target = 0;
    cin >> target;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(target + 1));
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i - 1])
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - v[i - 1]]) % MOD;
            }
        }
    }

    cout << dp[n][target];
    return 0;
}



// һά DP �����Ż�
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;
int main()
{
    int n = 0;
    cin >> n;

    long long target = 0;
    cin >> target;

    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<long long> dp(target + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // for (int j = target; j >= v[i - 1]; j--)
        for (int j = target; j >= 0; j--)
        {
            dp[j] = dp[j];
            if (j >= v[i - 1])
            {
                dp[j] = (dp[j] + dp[j - v[i - 1]]) % MOD;
            }
        }
    }

    cout << dp[target];
    return 0;
}