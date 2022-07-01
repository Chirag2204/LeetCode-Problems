class Solution {
public:
    int minMoves(vector<int>& nums) {
       int mn=INT_MAX;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            mn=min(mn,nums[i]);
            sum+=nums[i];
        }
        int ans= sum-mn*nums.size();
        
        return ans;
    }
};