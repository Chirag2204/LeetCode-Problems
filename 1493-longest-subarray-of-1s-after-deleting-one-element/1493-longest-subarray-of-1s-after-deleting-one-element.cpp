class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count=0,ans=0;
        int i=0,j=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==0){
                if(count==0)count++;
                else{
                    while(nums[i]!=0)i++;
                    i++;
                }
            }
            ans=max(ans,j-i+1-count);
        }
        if(count==0)return ans-1;
        return ans;
    }
};