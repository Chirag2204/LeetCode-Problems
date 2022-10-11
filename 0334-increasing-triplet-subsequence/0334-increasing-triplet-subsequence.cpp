class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int> leftmn(n);
        vector<int> rightmx(n);
        
        leftmn[0]=nums[0];
        rightmx[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            leftmn[i]=min(leftmn[i-1],nums[i]);
            rightmx[n-i-1]=max(rightmx[n-i],nums[n-i-1]);
            
        }
        for(int i=1;i<n;i++){
            if(leftmn[i]<nums[i] and rightmx[i]>nums[i])return true;
        }
        return false;
        
    }
};