class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        
        unordered_map<int,int> m;
        for(int& i:nums){
           m[i]++;
        }
        for(int i=1;i<=nums.size();i++){
            if(!m.count(i))ans[1]=i;
            if(m[i]==2)ans[0]=i;
        }
        return ans;
    }
};