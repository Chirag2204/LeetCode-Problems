class Solution {
public:
    unordered_map<int,vector<int>> m;
    int ans=0;
    int solve(int index,vector<int>& arr,int& diff,vector<int>& dp){
       if(index>=arr.size())return 0;
        
        if(dp[index]!=-1)return dp[index];
        
        int res=1;
        int nxtval= arr[index]+diff;
        if(m.count(nxtval)){
            auto nxt=upper_bound(m[nxtval].begin(),m[nxtval].end(),index);
            if(nxt!=m[nxtval].end()){
                res=max(res,1+ solve(*nxt,arr,diff,dp));
            }
        }
        solve(index+1,arr,diff,dp);
        
        ans=max(ans,res);
        
        return dp[index]=res;
        
    }
    
    int longestSubsequence(vector<int>& arr, int diff) {
        vector<int> dp(arr.size(),-1);
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
         solve(0,arr,diff,dp);
        return ans;
    }
};