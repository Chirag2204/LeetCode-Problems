class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       sort(nums.begin(),nums.end());
        int res=nums[0]+nums[1]+nums[nums.size()-1];
        int ans=res;
        for(int i=0;i<nums.size();i++){
            int start=i+1,end=nums.size()-1;
            while(start<end){
                int res=nums[i]+nums[start]+nums[end];
                if(res>target){
                    end--;
                }
                if(res<target){
                    start++;
                }
                if(res==target){
                    return res;
                }
                if(abs(res-target)<abs(ans-target)){
                    ans=res;
                }
            }
        }
        return ans;
    }
};