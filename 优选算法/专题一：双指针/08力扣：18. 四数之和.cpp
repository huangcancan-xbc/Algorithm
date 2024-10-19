//���ۣ�18. ����֮��
//https://leetcode.cn/problems/4sum/description/
//����������ۣ�15. ����֮�ͷǳ����ƣ�ֻ��������һ��ά�ȡ��㷨ԭ�����һ�¡�


//�ⷨһ������+����ö��
//ʱ�临�Ӷ�O(n^4)����򵥵�˼·������ʱ����ͨ����
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ret;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        // ����ѭ��ö���ĸ���
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                for (int k = j + 1; k < n - 1; k++) {
                    for (int q = k + 1; q < n; q++) {
                        // ʹ�� long long ����������֮�ͣ��������
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[q];
                        if (sum == target) {
                            ret.insert({ nums[i], nums[j], nums[k], nums[q] });
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};






//�ⷨ��������+˫ָ��
//ʱ�临�Ӷ�O(n^3)
//�㷨ԭ��
//1.���ι̶�һ����a
//2.��a����������ڣ����á�����֮�͡��ҵ���������ʹ���������ĺ͵���target-a����
//      -���ι̶�һ����b
//      -��b����������ڣ����á�˫ָ�롱�ҵ���������ʹ���������ĺ͵���target-a-b����
//**����ϸ������**
//1.ȥ�أ�
//      -�ҵ�һ�ֽ����left��rightָ��Ҫ�����ظ�Ԫ��
//      -��ʹ����һ��˫ָ���㷨��jҲҪ�����ظ�Ԫ�أ����̶��������ظ�Ԫ�أ�����ʹ����һ������֮���㷨��iҲҪ�����ظ�Ԫ��
//2.��©��
//      -�ҵ�һ�ֽ���󣬲�Ҫ��ͣ������С���䣬����Ѱ����һ�ֽ��


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;  // �������յĽ��

        sort(nums.begin(), nums.end());  // �ȶ������������
        int n = nums.size();  // ��ȡ����ĳ���

        // ��һ��ѭ�����̶���һ��Ԫ��
        for (int i = 0; i < n;) 
        {
            // �ڶ���ѭ�����̶��ڶ���Ԫ��
            for (int j = i + 1; j < n;) 
            {
                int left = j + 1;           // ��ָ���j����һ������ʼ����ʱ�൱������֮�ͣ���ָ��ָ��̶����ĺ�һ��λ��
                int right = n - 1;          // ��ָ�������ĩβ��ʼ
                long long sum = (long long)target - nums[i] - nums[j];
                // ����ʣ����������Ŀ��ͣ���target��ȥnums[i]��nums[j]��Ϊ��֤���ݷ�Χ��ʹ��long long���ͣ��������

                // ˫ָ�룬Ѱ�ҷ���������������
                while (left < right) 
                {
                    int temp = nums[left] + nums[right];  // ��ǰ����ָ��ĺ�

                    if (temp > sum) 
                    {
                        right--;  // �����ǰ�ʹ���Ŀ�꣬��ָ������
                    }
                    else if (temp < sum) 
                    {
                        left++;   // �����ǰ��С��Ŀ�꣬��ָ������
                    }
                    else if (temp == sum) 
                    {
                        // ����ҵ��ĸ����ĺ͵���Ŀ��
                        ret.push_back({ nums[i], nums[j], nums[left], nums[right] });
                        left++, right--;  // ����ָ�룬����Ѱ����һ�����ܵĽ�

                        // �����ظ�Ԫ��
                        while (left < right && nums[left] == nums[left - 1]) 
                        {
                            left++;  // ȷ��leftָ��ָ��ͬ��Ԫ��
                        }
                        while (left < right && nums[right] == nums[right + 1]) 
                        {
                            right--;  // ȷ��rightָ��ָ��ͬ��Ԫ��
                        }
                    }
                }

                //�Եڶ�������b������ȥ��
                j++;
                while (j < n && nums[j] == nums[j - 1]) 
                {
                    j++;
                }
            }

            //�Ե�һ����(a)����ȥ��
            i++;
            while (i < n && nums[i] == nums[i - 1]) 
            {
                i++;
            }
        }

        return ret;
    }
};
