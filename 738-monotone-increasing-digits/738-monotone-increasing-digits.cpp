class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        vector<int> nums;
        int temp=n;
        while(temp>0){
            int mod=temp%10;
            nums.push_back(mod);
            temp/=10;
        }
        reverse(nums.begin(),nums.end());
        int flag=nums.size();
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]<nums[i-1]){
                flag=i;
                nums[i-1]--;
            }
        }
        for(int i=flag;i<nums.size();i++){
            nums[i]=9;
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans*10 + nums[i];
        }
        return ans;
    }
};