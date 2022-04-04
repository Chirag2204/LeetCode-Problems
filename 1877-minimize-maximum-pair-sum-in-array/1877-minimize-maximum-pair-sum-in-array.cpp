class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,q=nums.size()-1;
        int max=0;
        while(i<=q){
            if(max<nums[i]+nums[q])
                max=nums[i]+nums[q];
            i++;
            q--;
        }
        return max;
    }
};