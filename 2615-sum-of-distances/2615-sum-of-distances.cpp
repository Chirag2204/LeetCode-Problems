class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,long long> sumleft,sumright,countleft,countright;
        
        vector<long long > ans(nums.size());
        
        for(int i=0;i<nums.size();i++){
            ans[i]= i*countleft[nums[i]]-sumleft[nums[i]];
            sumleft[nums[i]]+=i;
            countleft[nums[i]]++;
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]+=sumright[nums[i]]-i*countright[nums[i]];
            
            sumright[nums[i]]+=i;
            countright[nums[i]]++;
        }
        
        return ans;
        
    }
};