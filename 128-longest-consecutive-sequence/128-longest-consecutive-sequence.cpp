class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
         if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        int count=1;
        int ans=1;
       
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1)count++;
            else count=1;
            
            ans=max(ans,count);
        }
        return ans;
    }
};