class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minindex=0,maxindex=0,mn=INT_MAX,mx=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mn>nums[i]){
                mn=nums[i];
                minindex=i;
            }
            if(mx<nums[i]){
                mx=nums[i];
                maxindex=i;
            }
        }
        int ans=min(maxindex+n-minindex+1,minindex+n-maxindex+1);
        ans=min(ans,max(minindex+1,maxindex+1));
        ans=min(ans,max(n-minindex,n-maxindex));
        return ans;
    }
};