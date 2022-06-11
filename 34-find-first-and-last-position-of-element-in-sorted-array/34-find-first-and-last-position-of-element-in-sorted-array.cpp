class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>target)
                break;
            if(nums[i]==target && ans[0]==-1)
                ans[0]=i;
            if(nums[i]==target)
                ans[1]=i;
        }
        return ans;
    }
};