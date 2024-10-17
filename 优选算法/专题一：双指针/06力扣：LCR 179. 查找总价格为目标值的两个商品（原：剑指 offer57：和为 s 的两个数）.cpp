//���ۣ�LCR 179. �����ܼ۸�ΪĿ��ֵ��������Ʒ��ԭ����ָ offer57����Ϊ s ����������
//https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/
//ע�⣺����������ʹ�õ����б��ʼ����C++�ķ��������Ƶ������ԣ�������ѧϰ���֪ʶ�㣬��߱��������
//ͬʱ���ҷ���һ�����׵�ͼƬ���������ʹ���б��ʼ����C++�ķ��������Ƶ������ԡ�



// ����ö�ٲ��ԣ�
// ʱ�临�Ӷ�O(n^2)����򵥵ķ��������ᳬʱ
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int n = price.size(); // ��ȡ����ĳ���

        // ö�������������
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // �ж�������֮���Ƿ����Ŀ��ֵ
                if (price[i] + price[j] == target) {
                    return { price[i], price[j] }; // �ҵ���������ֱ�ӷ���
                }
            }
        }

        // ���û���ҵ�������{-1,-1}��ʾ�޽�
        return { -1, -1 };
    }
};





//�㷨ԭ�����õ����ԣ�ʹ��˫ָ���㷨�������
//ʱ�临�Ӷ�O(n)
//��Ϊ�����ǵ��������ģ�������������ĵ����ԣ�ָ��leftָ������ĵ�һ��Ԫ�أ�ָ��rightָ����������һ��Ԫ��
//��sum�����������ĺͣ����sumС��target����left���ƣ����sum����target����right���ƣ����sum����target���򷵻�������
class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int left = 0;                           // ��ָ��ָ���һ��Ԫ��
        int right = price.size() - 1;           // ��ָ��ָ�����һ��Ԫ��
        int sum = 0;                            // �洢�������ĺ�

        // ����ָ��С����ָ��ʱ����ѭ��
        while (left < right) 
        {
            sum = price[left] + price[right];   // �����������ĺ�

            if (sum < target) 
            {
                left++; // ��С��Ŀ��ֵ��������ָ�룬�����
            }
            else if (sum > target) 
            {
                right--; // �ʹ���Ŀ��ֵ��������ָ�룬��С��
            }
            else 
            {
                // �ҵ�������������������ֱ�ӷ���
                return { price[left], price[right] };
            }
        }

        // ���û���ҵ�������������������{-1,-1}
        return { -1, -1 };
    }
};
