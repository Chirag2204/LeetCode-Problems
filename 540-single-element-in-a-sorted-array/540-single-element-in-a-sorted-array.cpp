class Solution
{
    public:
        int singleNonDuplicate(vector<int> &nums)
        {
            int e = nums.size()-1, s = 0;
            int mid = s + (e - s) / 2;
            while (s < e)
            {
              if(mid%2==0 && nums[mid]==nums[mid+1] || mid%2==1 && nums[mid-1]==nums[mid]){
                    s=mid+1;
                  
              }else{
                e=mid;
              }
                 mid = s + (e - s) / 2;
            }
            return nums[s];
        }
};