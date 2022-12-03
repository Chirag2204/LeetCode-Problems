class Solution {
public:
    static bool mysort(pair<int,int>& a,pair<int,int>& b){
        if(a.second==b.second)return a.first>b.first;
        return a.second<b.second;
    }
    
    vector<int> frequencySort(vector<int>& num) {
        unordered_map<int,int> m;
        for(int& i:num){
            m[i]++;
        }
       vector<pair<int,int>> nums;
        
        for(auto& x:m){
            nums.push_back({x.first,x.second});
        }
        sort(nums.begin(),nums.end(),mysort);
        
        vector<int> ans;
        for(auto& x:nums)
            for(int i=0;i<x.second;i++)
               ans.push_back(x.first);
        
        
        return ans;
        
    }
};