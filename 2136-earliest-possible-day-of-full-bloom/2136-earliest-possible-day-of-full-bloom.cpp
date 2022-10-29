class Solution {
public:
    static bool mysort(pair<int,int>& a,pair<int,int>& b){
       if(b.second==a.second)return a.first<b.first;
        return a.second>b.second;
    } 
    
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> plants;
        for(int i=0;i<growTime.size();i++){
            plants.push_back({plantTime[i],growTime[i]});
        }
        sort(plants.begin(),plants.end(),mysort);
        int sum=0;
        int ans=0;
        for(int i=0;i<growTime.size();i++){
            sum+=plants[i].first;
            ans=max(ans,sum+plants[i].second);
        }
        return ans;
    }
};