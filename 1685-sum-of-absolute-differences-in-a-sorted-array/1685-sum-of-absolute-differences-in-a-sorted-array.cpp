class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> leftsum(n);
        vector<int> rightsum(n);
        
        leftsum[0]=nums[0];
        rightsum[n-1]=nums[n-1];
        int sum=nums[0];
        for(int i=1;i<n;i++){
            sum+=nums[i];
            leftsum[i]=leftsum[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            rightsum[i]=rightsum[i+1]+nums[i];
        }
        ans[n-1]=abs(n*nums[n-1] - sum);
        ans[0]=abs(n*nums[0]-sum);
        
        for(int i=1;i<n-1;i++){
            ans[i]=abs(i*nums[i]-leftsum[i-1])+abs((n-i-1)*nums[i] - rightsum[i+1]);
        }
        return ans;
    }
};