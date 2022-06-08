class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
       int n=nums.size();
        if(n==1 && k%2==1){
            return -1;
        }
       int ans=0;
        for(int i=0;i<min(n,k-1);i++){
            ans=max(ans,nums[i]);
        }
        if(k<n){
            ans=max(ans,nums[k]);
        }
        return ans;
    }
    
   
};