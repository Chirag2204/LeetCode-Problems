class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int num=nums[0];
        for(int i=1;i<nums.size();i++){
           ans.push_back(num^(int(pow(2,maximumBit)-1)));
            num^=nums[i];
        }
         ans.push_back(num^(int(pow(2,maximumBit)-1)));
        reverse(ans.begin(),ans.end());
        return ans;
    }
};