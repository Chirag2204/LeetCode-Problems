class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        vector<int> frontsum(n);
        map<int,int> backsum;
          int ans=INT_MAX;
        int rsum=0;
        for(int j=n-1;j>=0;j--){
            rsum+=nums[j];
            backsum[rsum]=j;
            if(rsum==x){
                ans=min(ans,n-j);
            }
        }
      
        frontsum[0]=nums[0];
        for(int i=1;i<n;i++){
           frontsum[i]=frontsum[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            if(frontsum[i]==x){
                ans=min(ans,i+1);
            }
            if(backsum.count(x-frontsum[i]) && i<backsum[x-frontsum[i]]){
                ans=min(ans,n-backsum[x-frontsum[i]]+i+1);
            }
        }
        if(ans==INT_MAX)return -1;
       return ans; 
    }
};