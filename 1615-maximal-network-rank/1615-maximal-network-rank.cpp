class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,set<int>> m;
        int mx1=-1,mx2=-1;
        for(auto& x: roads){
            m[x[0]].insert(x[1]);
            m[x[1]].insert(x[0]);
        }
        int ans=0;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                count= m[i].size()+ m[j].size();
                if(m[i].count(j))count--;
                ans=max(ans,count);
            }
        }
        
        return ans;
        
    }
};