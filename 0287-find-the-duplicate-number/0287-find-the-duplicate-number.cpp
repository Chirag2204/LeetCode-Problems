class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=0,e=nums.size()-1;
        int mid=s+(e-s)/2;
        int ans;
        while(s<=e){
            if(nums[mid]==mid+1)
                s=mid+1;
            if(nums[mid]<mid+1){
                ans=nums[mid];
                e=mid-1;
            }
            if(nums[mid]>mid+1){
                ans=nums[mid];
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};