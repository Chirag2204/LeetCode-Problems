class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> nums;
        vector<int> ans;
        for(int i=1;i<=m;i++){
            nums.push_back(i);
        }
        
        for(int i=0;i<queries.size();i++){
            int pos=find(nums.begin(),nums.end(),queries[i])-nums.begin();
            ans.push_back(pos);
            nums.erase(nums.begin()+pos);
            nums.insert(nums.begin(),queries[i]);
        }
        return ans;
    }
};