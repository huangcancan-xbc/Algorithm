// ���ۣ�912. ��������
// ���ӣ�https://leetcode.cn/problems/sort-an-array/description/

// �������鲢����
class Solution
{
public:
    void mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
        {
            return;                                     // �ݹ���ֹ������������ֻ��һ��Ԫ��
        }

        int mid = (left + right) / 2;                   // ȡ�м�λ�ã�Ҳ����д�� >>1��

        // �ݹ�������벿�ֺ��Ұ벿��
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);

        vector<int> temp(right - left + 1);             // �ϲ��������������飬��ʱ���飬���ںϲ�������

        int cur1 = left;                                // ��ָ�룬ָ����벿�ֵ���ʼλ��
        int cur2 = mid + 1;                             // ��ָ�룬ָ���Ұ벿�ֵ���ʼλ��
        int i = 0;                                      // temp ������±�

        while (cur1 <= mid && cur2 <= right)            // ˫ָ��ϲ�����
        {
            temp[i++] = nums[cur1] <= nums[cur2] ? nums[cur1++] : nums[cur2++];     // ÿ��ѡ���С��ֵ���� temp�����ƶ���Ӧָ��
        }

        while (cur1 <= mid)
        {
            temp[i++] = nums[cur1++];                   // ����벿�ֻ���ʣ�࣬ȫ�������� temp
        }
        while (cur2 <= right)
        {
            temp[i++] = nums[cur2++];                   // ���Ұ벿�ֻ���ʣ�࣬ȫ�������� temp
        }

        for (int i = left; i <= right; i++)
        {
            nums[i] = temp[i - left];                   // ���ϲ���Ľ��������ԭ�����Ӧλ��
        }
    }

    vector<int> sortArray(vector<int>& nums)
    {
        mergesort(nums, 0, nums.size() - 1);            // ������������й鲢����
        return nums;
    }
};



// �Ż���ʹ��ȫ�ֱ���
class Solution
{
public:
    vector<int> temp;                                   // ��ʱ������Ϊ���Ա������ÿ�εݹ鶼����������

    void mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }

        int mid = (left + right) / 2;
        // int mid = (left + right) >> 1; // �ȼ�����һ��

        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);

        int cur1 = left, cur2 = mid + 1, i = 0;
        while (cur1 <= mid && cur2 <= right)
        {
            temp[i++] = nums[cur1] <= nums[cur2] ? nums[cur1++] : nums[cur2++];
        }

        while (cur1 <= mid)
        {
            temp[i++] = nums[cur1++];                   // ����ʣ����ಿ��
        }
        while (cur2 <= right)
        {
            temp[i++] = nums[cur2++];                   // ����ʣ���Ҳಿ��
        }

        for (int i = left; i <= right; i++)
        {
            nums[i] = temp[i - left];
        }

    }

    vector<int> sortArray(vector<int>& nums)
    {
        temp.resize(nums.size());                       // ��ʼ����ʱ�����С��ֻ����һ�Σ�
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
};