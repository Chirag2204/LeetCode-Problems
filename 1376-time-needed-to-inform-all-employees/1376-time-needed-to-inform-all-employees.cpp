class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1)return 0;
        map<int,vector<int>> m;
        for(int i=0;i<manager.size();i++){
            if(manager[i]!=-1)
              m[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push({headID,0});
        int ans=0;
        while(!q.empty()){
            int emp=q.front().first;
            int time=q.front().second;
            ans=max(ans,time);
            q.pop();
            for(auto& i:m[emp]){
                q.push({i,time+informTime[emp]});
            }
        }
        return ans;
    }
};