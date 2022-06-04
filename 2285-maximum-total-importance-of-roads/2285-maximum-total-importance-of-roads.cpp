#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<ll,ll> m;
        for(int i=0;i<roads.size();i++){
            m[roads[i][0]]++;
            m[roads[i][1]]++;
        }
        priority_queue<pair<ll,ll>>pq;
        for(auto &x:m){
            pq.push(make_pair(x.second,x.first));
        }
        long long sum=0;
        while(!pq.empty()){
            pair<ll,ll> p=pq.top();
            pq.pop();
            sum+=(ll)(p.first * n);
            n--;
        }
        return sum;
    }
    
    
};