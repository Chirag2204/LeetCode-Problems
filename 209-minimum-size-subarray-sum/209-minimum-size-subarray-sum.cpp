class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=INT_MAX;
        int i=0,j=0,sum=0;
        while(j<nums.size()){
           
            if(sum>=target){
                // cout<<j<<" "<<i<<endl;
                ans=min(ans,j-i);
                sum-=nums[i];
                i++;
            }else{
                sum+=nums[j];
                j++;
            }
        }
        while(sum>=target){
            //cout<<j<<" "<<i<<endl;
            ans=min(ans,j-i);
            sum-=nums[i];
            i++;
        }
                
        if(ans==INT_MAX)return 0;
        return ans;
    }
};