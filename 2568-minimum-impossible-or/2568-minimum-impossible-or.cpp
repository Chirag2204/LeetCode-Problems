class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int ans=1;
        unordered_set<int> s(nums.begin(),nums.end());
        
        while(s.count(ans))ans*=2;
        
        return ans;
        
    }
};