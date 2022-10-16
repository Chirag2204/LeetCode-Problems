class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        
        bool mnfound=false,mxfound=false;
        int start=0,mnstart=0,mxstart=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxK or nums[i]<minK){
                mnfound=false;
                mxfound=false;
                start=i+1;
            }
            
            if(nums[i]==maxK){
                mxfound=true;
                mxstart=i;
            }
            
            if(nums[i]==minK){
                mnfound=true;
                mnstart=i;
            }
            
            if(mxfound and mnfound){
                ans+=(min(mnstart,mxstart)-start+1);
            }
            
        }
        return ans;
    }
};