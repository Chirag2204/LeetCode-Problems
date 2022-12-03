class Solution {
public:
    string frequencySort(string s) {
        map<char,int> m;
        for(auto i: s){
            m[i]++;
        }
        priority_queue<pair<int,char> > pq;
        for(auto x:m){
              pq.push(make_pair(x.second,x.first));
        }
        string ans="";
        while(!pq.empty()){
            for(int i=0;i<pq.top().first;i++)
               ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};