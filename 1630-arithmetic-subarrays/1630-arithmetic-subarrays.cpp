class Solution {
public:
    bool isSubArray(vector<int> nums,int start,int end ){
        sort(nums.begin()+start,nums.begin()+end+1);
        int dif=nums[start+1]-nums[start];
        
        for(int i=start;i<=end-1;i++){
            if(nums[i+1]-nums[i]!=dif)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            ans.push_back(isSubArray(nums,l[i],r[i]));
        }
        return ans;
    }
};