class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        if(nums.size()==3)return 0;
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-3;
        int ans=1e9;
        while(j<nums.size()){
            ans=min(ans,abs(nums[i]-nums[j]));
            i++;
            j++;
        }
        return ans;
    }
};