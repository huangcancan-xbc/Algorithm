//���ۣ�611. ��Ч�����εĸ���
//https://leetcode.cn/problems/valid-triangle-number/description/

//�ⷨһ������ö�ٷ�
//ö�������ε������ߣ�Ȼ���ж��Ƿ���������
//ʱ�临�Ӷ�O(n^3)���ṩ�򵥵�˼·�����޷�ͨ�����۲���

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();    // ��ȡ����Ĵ�С
        int ret = 0;            // ���ڼ�¼���������������θ���

        // ����ѭ��ö�����п��ܵ�������
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    // �ж������Ƿ�������������
                    // ��������������֮�ʹ��ڵ�����
                    if (nums[i] + nums[j] > nums[k] && nums[j] + nums[k] > nums[i] && nums[i] + nums[k] > nums[j])
                    {
                        ret++;  // ������������������θ���+1
                    }
                }
            }
        }

        return ret;  
    }
};




//�ⷨ�������õ����ԣ�ʹ��˫ָ���㷨������
//�㷨ԭ��
//1.�����򣬹̶�������
//2.����������������ڣ�ʹ��˫ָ���㷨������ͳ�Ƴ�����Ҫ�����Ԫ��ĸ���

//���
//1.a+b>c->right-left,right--
//2.a+b<=c,left++
//���ͣ�
//��C�Ѿ�����ˣ���ߵ�����С��C���������ߵ�����Cǰһ��������C��˵��������ߵ�����Cǰһ������������������Σ�right-left����
//�������ߵ�����Cǰһ����С��C��˵������ߵ�����Cǰһ������������������Σ���ʼleft++
//����C��ߵ�������������֮�Ͷ�С��C��˵��û�������ο�����ɣ��ı������C����forѭ��ʹ�������С�������ж�


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // �����򣬷���ʹ��˫ָ��

        int ret = 0, n = nums.size() - 1;

        for (int i = n; i >= 2; i--)  // �̶����� nums[i]
        {
            int left = 0, right = i - 1;  // ˫ָ���ʼλ�ã�����ʹδ��

            while (left < right)
            {
                // �����С������֮�ʹ������ߣ�˵�������������
                if (nums[left] + nums[right] > nums[i])
                {
                    ret += right - left;  // ������������Ԫ��������� left �� right ȫ������
                    right--;  // ��ָ�����ƣ�Ѱ���µ����
                }
                else
                {
                    left++;  // �������֮�Ͳ��������ߣ�������ߣ������µ����
                }
            }
        }

        return ret;  // ���ط��������������θ���
    }
};