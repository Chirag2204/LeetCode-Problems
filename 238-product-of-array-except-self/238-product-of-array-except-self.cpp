class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long m=1;
        int count=0;
        for(int &i:nums){
            if(i==0)count++;
            else
                m*=i;
            if(count>1){
                m=0;
                break;
            }
           
        }
        for(int i=0;i<nums.size();i++){
            if(count>1){
                nums[i]=0;
            }
            else if(nums[i]!=0)
                if(count==1)nums[i]=0;
                else  nums[i]=m/nums[i];
                
            else
                nums[i]=m;
        }
        return nums;
    }
};