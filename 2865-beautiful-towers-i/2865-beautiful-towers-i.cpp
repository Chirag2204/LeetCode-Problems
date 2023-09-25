class Solution {
public:
    long long maximumSumOfHeights(vector<int>& nums) {
        int mx=0,mxi=0;
        
        long long ans=0;
        int prev=mx;
        for(int mxi=0;mxi<nums.size();mxi++){
            long long sum=0;
            prev=nums[mxi];
            for(int i=mxi;i>=0;i--){
            
                sum+=min(prev,nums[i]);
                prev=min(prev,nums[i]);
        }
        
        prev=nums[mxi];
         for(int i=mxi+1;i<nums.size();i++){
            
                sum+=min(prev,nums[i]);
                prev=min(prev,nums[i]);
            
        }
            
            ans=max(ans,sum);
        }
        
        
        return ans;
    }
};