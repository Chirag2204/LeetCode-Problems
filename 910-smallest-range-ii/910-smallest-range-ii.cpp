class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=nums[nums.size()-1]-nums[0];
        int left=nums[0]+k,right=nums[nums.size()-1]-k;
        for(int i=0;i<nums.size()-1;i++){
            int mx=max(right,nums[i]+k),mn=min(nums[i+1]-k,left);
            ans=min(ans,mx-mn);
        }
        return ans;
    }
};