class Solution {
public:
    
     void solve(set<vector<int> > &ans,vector<int>& candidates,vector<int> push,int target,int index){
       
       
           if(target==0){  
               ans.insert(push);
            }
            // cout<<target<<" "<<index;
           if(index>=candidates.size())
            return;
     
          for(int j=index; j<candidates.size(); j++)
        {
            if(candidates[j]>target)
                return;
            if(index!=j && candidates[j]==candidates[j-1])
                continue;
            push.push_back(candidates[j]);
            solve(ans,candidates,push,target-candidates[j],j+1);
            push.pop_back();  
        }
   
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       
        set<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> push;
        
         solve(ans,candidates,push,target,0);
       vector<vector<int> > ans1(ans.begin(),ans.end());
        return ans1;
    }
};