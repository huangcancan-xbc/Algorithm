// ��ȣ�P8627 [���ű� 2015 ʡ A] ���ϻ���
// ���ӣ�https://www.luogu.com.cn/problem/P8627

// ����һ������ѭ��ģ��
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int ret = n, gai = n;
	while (gai > 2)
	{
		ret += gai / 3;
		gai = gai / 3 + gai % 3;
	}

	cout << ret << endl;

	return 0;
}



// ���������ݹ�
#include <iostream>
using namespace std;

int is(int n)
{
	if (n < 3)
	{
		return 0;
	}

	int ret = n / 3;
	int gai = n % 3 + ret;

	return ret + is(gai);
}

int main()
{
	int n = 0;
	cin >> n;

	int ret = is(n) + n;
	cout << ret << endl;

	return 0;
}