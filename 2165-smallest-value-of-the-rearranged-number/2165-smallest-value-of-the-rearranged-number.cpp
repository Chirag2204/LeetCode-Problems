class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0)return 0;
        int sign=1;
        if(num<0){
            sign=-1;
            num=-num;
       }
        vector<int> nums;
        while(num>0){
            int mod=num%10;
            nums.push_back(mod);
            num/=10;
        }
        sort(nums.begin(),nums.end());
        if(sign==1){
            int firstnonzero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                firstnonzero=i;
                break;
            }
        }
        swap(nums[0],nums[firstnonzero]); 
        }
        else{
            reverse(nums.begin(),nums.end());
        }
       long long ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans*10 + nums[i];
        }
       
        return ans*sign;
    }
};