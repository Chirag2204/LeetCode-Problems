class Solution {
public:
    bool isSubArray(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int dif=nums[1]-nums[0];
       
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]!=dif)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            vector<int> topass(nums.begin()+l[i],nums.begin()+r[i]+1);
            ans.push_back(isSubArray(topass));
        }
        return ans;
    }
};