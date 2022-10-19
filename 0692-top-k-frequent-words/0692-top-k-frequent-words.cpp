class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> m;
        for(string& s:words){
            m[s]++;
        }
        
        vector<pair<int,string>>v;
        
       
        for(auto& x:m){
            v.push_back(make_pair(x.second,x.first));
        }
        sort(v.begin(),v.end(),mysort);
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        
        return ans;
    }
    static bool mysort(pair<int,string> a,pair<int,string> b){
        if(a.first==b.first)return a.second<b.second;
        else return a.first>b.first;
    }
};