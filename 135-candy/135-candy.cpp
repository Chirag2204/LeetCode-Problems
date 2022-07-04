class Solution {
public:
    int candy(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans1(n,1);
        vector<int> ans2(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                ans1[i]=ans1[i-1]+1;
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                ans2[i]=1+ans2[i+1];
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=max(ans1[i],ans2[i]);
        }
        return sum;
    }
};