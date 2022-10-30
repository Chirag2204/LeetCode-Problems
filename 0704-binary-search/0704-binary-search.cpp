class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg=0;
        int end=nums.size()-1;
        while(beg<=end){
            int mid=(beg+end)/2;
            if(target==nums[mid])
                return mid;
            if(target>nums[mid])
                beg=mid+1;
            if(target<nums[mid])
                end=mid-1;
        }
        return -1;
    }
};