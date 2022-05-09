class Solution {
public:
   
    
    void solve(vector<vector<int> > &ans,vector<int>&candidates,vector<int> push,int target,int index){
        if(target==0){
            ans.push_back(push);
            return;
        }
        if(target<0 || index>=candidates.size()){
            return;
        }
       
        //not included
        solve(ans,candidates,push,target,index+1);
        
        //included
        push.push_back(candidates[index]);
        solve(ans,candidates,push,target-candidates[index],index);
        push.pop_back();
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> push;
        solve(ans,candidates,push,target,0);
 
        return ans;
    }
};