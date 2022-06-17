class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target)
                return 0;
            else
                return -1;
        }
        int p=findPivot(nums);
        
        if(target<=nums[p-1] && target>=nums[0]){
            int s=0,e=p-1;
            int m=s+(e-s)/2;
            while(s<=e){
                if(nums[m]==target){
                    return m;
                }
                if(nums[m]<target){
                    s=m+1;
                }
                if(nums[m]>target){
                    e=m-1;
                }
                m=s+(e-s)/2;
            }
            
        }else{
             int s=p,e=nums.size()-1;
            int m=s+(e-s)/2;
            while(s<=e){
                if(nums[m]==target){
                    return m;
                }
                if(nums[m]<target){
                    s=m+1;
                }
                if(nums[m]>target){
                    e=m-1;
                }
                m=s+(e-s)/2;
            }
            
        }
        return -1;
    }
    
    int findPivot(vector<int>& nums){
        int n=nums.size();
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
        return s;
    }
};