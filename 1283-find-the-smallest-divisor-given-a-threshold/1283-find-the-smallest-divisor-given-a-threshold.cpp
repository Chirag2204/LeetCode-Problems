class Solution {
public:
    bool isPossible(vector<int>& nums,int val,int& t){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%val==0){
               count+=nums[i]/val; 
            }else{
                count+=(nums[i]/val + 1);
            }
            if(count>t)return false;
        }
        return true;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int s=1,e=nums[nums.size()-1];
        int mid=s+(e-s)/2;
        int ans=e;
        while(s<=e){
            if(isPossible(nums,mid,threshold)){
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