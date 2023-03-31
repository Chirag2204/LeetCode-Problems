class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        
        int i=0,j=nums.size()-1;
        string s1="",s2="";
        while(i<j){
            s1=to_string(nums[i++]);
            s2=to_string(nums[j--]);
            
            ans+= stoi(s1+s2);
        }
        
        if(i==j)ans+=nums[i];
        
        return ans;
    }
};