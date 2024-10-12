//���ۣ�283. �ƶ���
//https://leetcode.cn/problems/move-zeroes/description/

//�㷨ԭ��
//�������黮��/����ֿ�������
//ʹ��˫ָ���㷨-->���������±�䵱ָ��

//����ָ������ã�
//1. curָ�룺��������ɨ�����飬��������
//2. destָ�룺�Ѿ�����������ڣ�����Ԫ�ص����һ��λ��

//�������䣺
//[0, dest]     [dest + 1, cur - 1]     [cur, n - 1]
//   ��0                0                  ������

//���������
//cur��ǰ��������Ĺ����У�
//1.����0Ԫ�أ�cur++
//2.������0Ԫ��
//      a. swap(nums[dest + 1], nums[cur])
//      b. dest++, cur++


class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        for (int cur = 0, dest = -1; cur < nums.size(); cur++)
        {
            // �жϵ�ǰԪ���Ƿ�Ϊ����Ԫ��
            if (nums[cur])
            {
                // swap: ����nums[dest + 1]��nums[cur]��ֵ
                // Ŀ�ģ�������Ԫ���Ƶ�ǰ�棬��Ԫ�����ں���
                swap(nums[++dest], nums[cur]);
            }
        }
    }
};