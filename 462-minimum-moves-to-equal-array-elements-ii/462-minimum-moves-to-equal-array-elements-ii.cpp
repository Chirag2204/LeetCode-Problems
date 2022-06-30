class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int mid=nums.size()/2;
        if(nums.size()%2==0)mid=nums.size()/2 - 1;
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-nums[mid]);
        }
         return ans;
    }
};