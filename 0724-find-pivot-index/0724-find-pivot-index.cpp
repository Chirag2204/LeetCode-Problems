class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0){
            return -1;
        }
       
        vector<int> left(nums.size()),right(nums.size());
         left[0]=nums[0];
        right[nums.size()-1]=nums[nums.size()-1];
        for(int i=1;i<nums.size();i++){
            left[i]=left[i-1]+nums[i];
        }
        
         for(int i=nums.size()-2;i>=0;i--){
            right[i]=right[i+1]+nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(right[i]==left[i])
                return i;
        }
        return -1;
    }
};