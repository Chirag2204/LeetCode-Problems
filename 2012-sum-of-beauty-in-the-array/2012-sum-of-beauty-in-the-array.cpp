class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int mx=0,mn=1e9;
        vector<int> mns(nums.size());
        vector<int> mxs(nums.size());
        
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            mxs[i]=mx;
        }
        for(int i=nums.size()-1;i>=0;i--){
            mn=min(mn,nums[i]);
            mns[i]=mn;
        }
        int ans=0;
        for(int i=1;i<nums.size()-1;i++){
            if(mxs[i-1]<nums[i] and mns[i+1]>nums[i])ans+=2;
            else if(nums[i]>nums[i-1] and nums[i]<nums[i+1])ans++;
        }
        return ans;
    }
};