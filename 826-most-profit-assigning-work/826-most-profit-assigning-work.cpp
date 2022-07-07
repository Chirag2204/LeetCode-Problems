class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> vp;
        for(int i=0;i<profit.size();i++){
            vp.push_back(make_pair(difficulty[i],profit[i]));
        }
        sort(vp.begin(),vp.end());
        sort(worker.begin(),worker.end());
        int ans=0,mx=0;
        int x=0;
        for(int i=0;i<worker.size();i++){
            while(x<profit.size() && worker[i]>=vp[x].first){
                mx=max(mx,vp[x].second);
                x++;
            }
            ans+=mx;
          }
        
        return ans;
    }
    
};