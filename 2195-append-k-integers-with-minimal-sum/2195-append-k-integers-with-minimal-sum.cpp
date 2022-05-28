class Solution {
public:
   
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        long long sum=(long long)k*(k+1)/2;
        int i=0;
        for(i=0;i<nums.size();i++){
            if(i>0 && nums[i-1]==nums[i])continue;
            else{
                if(nums[i]<=k){
                    sum-=nums[i];
                    sum+=(k+1);
                    k++;
                }
            }
        }
      
        return sum;
    }
};