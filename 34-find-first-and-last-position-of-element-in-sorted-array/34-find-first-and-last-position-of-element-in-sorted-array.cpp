class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]>target)
        //         break;
        //     if(nums[i]==target && ans[0]==-1)
        //         ans[0]=i;
        //     if(nums[i]==target)
        //         ans[1]=i;
        // }
        int s=0,e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans[0]=mid;
                e=mid-1;
            }
            if(nums[mid]>target){
                e=mid-1;
            }
            if(nums[mid]<target){
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
         s=0,e=nums.size()-1;
         mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans[1]=mid;
                s=mid+1;
            }
            if(nums[mid]>target){
                e=mid-1;
            }
            if(nums[mid]<target){
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};