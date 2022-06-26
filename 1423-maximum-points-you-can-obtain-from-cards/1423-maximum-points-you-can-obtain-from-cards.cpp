class Solution
{
    public:
        int maxScore(vector<int> &nums, int k)
        {

            int n = nums.size();
            int ans = 0, sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (i < n - k)
                    ans += nums[i];
                sum += nums[i];
                nums[i] = sum;
            }

            int i = 0, j = n - k;
            while (j < n)
            {

                ans = min(ans, nums[j] - nums[i]);

                i++;
                j++;
            }
            
            return sum - ans;
        }
};