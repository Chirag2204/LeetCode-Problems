class Solution {
public:
    set<vector<int>> ans;
    void solve(vector<int>& nums,int index,vector<int> temp){
        if(index>= nums.size()){
            if(temp.size()>1)
            ans.insert(temp);
            return ;
        }
        
        if(temp.size()==0 or nums[index]>=temp[temp.size()-1]){
            temp.push_back(nums[index]);
            solve(nums,index+1,temp);
            temp.pop_back();
        }
        
        solve(nums,index+1,temp);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        solve(nums,0,temp);
        vector<vector<int>> ans1(ans.begin(),ans.end());
        return ans1;
    }
};