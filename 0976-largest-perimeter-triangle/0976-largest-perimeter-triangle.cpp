class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=n-3;
        while(i>=0){
            if(nums[i+2]<nums[i]+nums[i+1])return nums[i]+nums[i+1]+nums[i+2];
            i--;
        }
        return 0;
    }
};