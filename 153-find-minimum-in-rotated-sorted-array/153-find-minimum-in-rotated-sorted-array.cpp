class Solution {
public:
    int findMin(vector<int>& nums) {
         if(nums.size()==1){
            return nums[0];
        }
        int p=findPivot(nums);
        
   
        return nums[p];
    }
    
    int findPivot(vector<int>& nums){
        int n=nums.size();
        if(nums[0]<nums[n-1]){
            return 0;
        }
        int s=0,e=n-1;
        int m=s+(e-s)/2;
        
        while(s<e){
            if(nums[m]<nums[0]){
                e=m;
            }
            if(nums[m]>=nums[0]){
                s=m+1;
            }
            m=s+(e-s)/2;
        }
        return m;
    }
};