class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>copy(strs.begin(),strs.end());
        for(int i=0;i<strs.size();i++){
          sort(strs[i].begin(),strs[i].end());
        }
        map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            m[strs[i]].push_back(copy[i]);
        }
        vector<vector<string>> ans;
        for(auto x:m){
           ans.push_back(x.second); 
        }
        return ans;
    }
  
};