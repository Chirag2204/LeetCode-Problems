class Solution {
public:
    bool isPossible(vector<int>& nums,int maxOperations,int mid){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0){
                count+=(nums[i]/mid)-1;
            }else count+=(nums[i]/mid);
            
            if(count>maxOperations) return false;
            
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int e=0;
        for(int i:nums){
            if(i>e)e=i;
        }
        int s=1;
        int mid=s+(e-s)/2;
        int ans=0;
        while(s<=e){
            if(isPossible(nums,maxOperations,mid)){
                ans=mid;
                e=mid-1;
            }
            else 
                s=mid+1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
};