class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
      
        int type=3;
        for(int i=1;i<nums.size();i++){
            if(type==3){
                if(nums[i]>nums[i-1])type=1;
                if(nums[i]<nums[i-1])type=2;
            }else{
                if(type==1 && nums[i]<nums[i-1])return false;
                if(type==2 && nums[i]>nums[i-1])return false;
            }
         }
        return true;
    }
};