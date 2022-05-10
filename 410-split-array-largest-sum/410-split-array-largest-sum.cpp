class Solution {
public:
    bool isPossible(int mid,vector<int>& nums,int m){
        int count=0,parts=1;
        for(int i=0;i<nums.size();i++){
            if(count+nums[i]<=mid){
                count+=nums[i];
            }else{
                parts++;
                if(nums[i]>mid || parts>m){
                    return false;
                }
                count=nums[i];
            }
            
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
       int e=0;
        for(int i :nums){
            e+=i;
        }
        int s=1;
        int mid=s+(e-s)/2;
        int ans=0;
        while(s<=e){
            if(isPossible(mid,nums,m)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};