// PTA��L1-027 ����
// ���ӣ�https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805107638517760&page=0

// ����������ģ�� + ��ϣ
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> arr;
    vector<bool> hash(10, false);

    // �洢�绰����ĳ��ֵ����ּ�arr����
    for (int i = 0; i < s.size(); i++)
    {
        int num = s[i] - '0';
        if (!hash[num])
        {
            arr.push_back(num);
            hash[num] = true;
        }
    }

    sort(arr.begin(), arr.end(), greater<int>());

    printf("int[] arr = new int[]{");
    for (auto x : arr)
    {
        cout << x;
        if (x != arr.back())
        {
            cout << ",";
        }
        else
        {
            cout << "};" << endl;
        }
    }

    printf("int[] index = new int[]{");
    vector<int> ret;
    for (auto x : s)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (x - '0' == arr[i])
            {
                ret.push_back(i);
                break;
            }
        }
    }

    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i];
        if (i != ret.size() - 1)
        {
            cout << ",";
        }
    }

    cout << "};" << endl;

    return 0;
}


// ����д�ıȽ�ʺ�ˣ��������Ż���Ĵ��룺
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;

    vector<int> arr;
    vector<bool> vis(10, false);                        // ��¼�����Ƿ��Ѵ���

    // �洢���ظ������֣�������˳�����������
    for (int i = 0; i < s.size(); i++)
    {
        int num = s[i] - '0';
        if (!vis[num])
        {
            arr.push_back(num);
            vis[num] = true;
        }
    }
    
    sort(arr.begin(), arr.end(), greater<int>());       // ����������

    vector<int> ret(10);
    for (int i = 0; i < arr.size(); i++)
    {
        ret[arr[i]] = i;
    }

    printf("int[] arr = new int[]{");
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
        {
            cout << ",";
        }
        else
        {
            cout << "};" << endl;
        }
    }

    printf("int[] index = new int[]{");
    for (int i = 0; i < s.size(); i++)
    {
        int num = s[i] - '0';
        cout << ret[num];
        if (i != s.size() - 1)
        {
            cout << ",";
        }
        else
        {
            cout << "};";
        }
    }

    return 0;
}