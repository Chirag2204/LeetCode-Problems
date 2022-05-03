class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       int p=-1,q=-1;
        vector<int> nums1=nums;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=nums1[i]){
                if(p==-1){
                    p=i;
                    q=i;
                }else{
                    q=i;
                }
            }
        }
        if(p==q)return 0;
        return q-p+1;
    }
};