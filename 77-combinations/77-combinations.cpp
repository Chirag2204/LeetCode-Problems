class Solution {
public:
    void solve(vector<vector<int>>& ans,int &n,int& k,int index,vector<int> topush){
       if(topush.size()==k){
           ans.push_back(topush);
           return;
           }
           if(index>n ) return;
        
           for(int i=index;i<=n;i++){
               topush.push_back(i);
               solve(ans,n,k,i+1,topush);
               topush.pop_back();
           }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> topush;
        solve(ans,n,k,1,topush);
      
        return ans;
    }
};