//���ۣ�15. ����֮��
//https://leetcode.cn/problems/3sum/description/

//�ⷨһ������+����ö��+setȥ��
//ʱ�临�Ӷ�O(n^3)����������С��ģ����

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ret;   // ��set�Զ�ȥ��
        int n = nums.size();

        // 1. ���򣬷����������
        sort(nums.begin(), nums.end());

        // 2. ����ѭ������ö��ÿ����Ԫ��
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    // 3. ��鵱ǰ��Ԫ���Ƿ������Ϊ0
                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        ret.insert({ nums[i], nums[j], nums[k] });  // ʹ��setȥ��
                    }
                }
            }
        }

        // ��setת��Ϊvector���з���
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};






//�ⷨ����˫ָ��+����
//ʱ�临�Ӷ�O(n^2)
//�㷨ԭ��
//1.����
//2.�̶�һ�������Ż����������򣬵��̶���Ϊ����ʱ���̶����Ҳ����������0���Ͳ����ں�Ϊ0����Ԫ�飬ֱ�ӷ��ء�
//3.�ڸ�������������ڣ����á�˫ָ���㷨�������ҵ��������ĺ�Ϊ-�̶������̶������෴����������������������С�
//˫ָ��ֱ�ָ����������(�̶����������һ������ʼ����ָ�������ڶ�������ʼ����ָ����������һ������ʼ)�����м��ƶ����ж��Ƿ���ں�Ϊ0����Ԫ��

//����֮�صĴ���ϸ�����⣺
//1.ȥ�أ�
//      -�ҵ�һ�ֽ����left��rightָ��Ҫ�����ظ�Ԫ��
//      -��ʹ����һ��˫ָ���㷨��iҲҪ�����ظ�Ԫ�أ����̶��������ظ�Ԫ�أ�
//      -����Խ�磬������ȫ��0��ʱ��ָ���һֱ�ƶ�����Խ�磬����Ҫ�����ж�
//2.��©��
//      -�ҵ�һ�ֽ���󣬲�Ҫ��ͣ������С���䣬����Ѱ����һ�ֽ��


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;  // ��Ž��������
        int n = nums.size();

        // 1. ���򣬷�������˫ָ���ȥ��
        sort(nums.begin(), nums.end());

        // 2. �̶�һ�������������п��ܵ���Ԫ��
        for (int i = 0; i < n; )
        {
            // ����̶����Ѿ�����0��ֱ�ӷ��ؽ��
            if (nums[i] > 0)
            {
                break;
            }

            int left = i + 1, right = n - 1;  // ��ʼ��˫ָ��
            int target = -nums[i];            // Ŀ�����Һ�Ϊ -nums[i] ��������

            // 3. ˫ָ��Ѱ���������ĺ͵��� -nums[i]
            while (left < right)
            {
                int temp = nums[left] + nums[right];

                // ����ʹ���Ŀ��ֵ����ָ������
                if (temp > target)
                {
                    right--;
                }
                // �����С��Ŀ��ֵ����ָ������
                else if (temp < target)
                {
                    left++;
                }
                // ����͵���Ŀ��ֵ���ҵ�һ����Ԫ��
                else
                {
                    ret.push_back({ nums[i], nums[left], nums[right] });
                    left++;
                    right--;

                    // �����ظ���leftԪ��
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    // �����ظ���rightԪ��
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }

            // �����ظ���iԪ�أ�������Ԫ���ظ�
            i++;
            while (i < n && nums[i] == nums[i - 1])
            {
                i++;
            }
        }

        return ret;
    }
};
