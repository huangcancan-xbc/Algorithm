//���ۣ�11. ʢ���ˮ������
//https://leetcode.cn/problems/container-with-most-water/description/

//����ö�٣�ʱ�临�Ӷ�O(n^2)
//ע�⣺�˶δ���ֻ��һ�ֽⷨ��ʵ��ʱ�临�ӶȽϸߣ��޷�ͨ�����۵Ĳ���������

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        // �������п��ܵ������������
        for (int i = 0; i < height.size() - 1; i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                // ����߶ȺͿ��
                int temp = min(height[i], height[j]) * (j - i);
                // ����������
                ret = max(ret, temp);
            }
        }

        return ret;
    }
};





//���õ����ԣ�ʹ��˫ָ����������⡣ʱ�临�Ӷ�O(n)
//�㷨ԭ��

//�趨����ָ�룬left��right���ֱ�ָ��������������ˡ�
//ÿ���ƶ�ָ�룬ʹ��left��right֮��ľ��뾡����С��ֱ��left��right�غϡ�
//���ƶ�ָ��Ĺ����У����㵱ǰ�����������ret���бȽϣ�����ret��
//���height[left] < height[right]����left���ƣ�����right���ơ�
//ֱ��left��right�غϣ�����ret��

class Solution {
public:
    // �����ܹ����ɵ����ˮ��
    int maxArea(vector<int>& height) {
        int left = 0;                        // ��ʼ����ָ�룬ָ������Ŀ�ʼ
        int right = height.size() - 1;      // ��ʼ����ָ�룬ָ������Ľ���
        int ret = 0;                         // ���ڴ洢���ˮ��

        // ����ָ��С����ָ��ʱ����������
        while (left < right)
        {
            // ���㵱ǰ��ˮ����ȡ���߽�С�ĸ߶ȣ����Կ��
            int v = min(height[left], height[right]) * (right - left);
            ret = max(ret, v);               // �������ˮ��ret

            // �ƶ�ָ�룺ѡ���С�ĸ߶ȣ������ҵ������ˮ��
            if (height[left] < height[right])
            {
                left++;                      // ��ָ������
            }
            else
            {
                right--;                     // ��ָ������
            }
        }

        return ret;                          // �����ҵ������ˮ��
    }
};
