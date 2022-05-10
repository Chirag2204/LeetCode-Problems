class Solution {
public:
     void solve(vector<vector<int> > &ans,vector<int>&candidates,vector<int> push,int target,int index,int& k){
        if(target==0 && push.size()==k){
            ans.push_back(push);
            return;
        }
        if(target<0 || index>=candidates.size()){
            return;
        }
       
        //not included
        solve(ans,candidates,push,target,index+1,k);
        
        //included
        push.push_back(candidates[index]);
        solve(ans,candidates,push,target-candidates[index],index+1,k);
        push.pop_back();
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> candidates{1,2,3,4,5,6,7,8,9};
        vector<int> push;
        solve(ans,candidates,push,n,0,k);
        return ans;
    }
};