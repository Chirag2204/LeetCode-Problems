class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> umap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
            
        }
        for(auto& x:umap){
            if(x.second>n/3 )
               ans.push_back(x.first);
        }
        return ans;
    }
};