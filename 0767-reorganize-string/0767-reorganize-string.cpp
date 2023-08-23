class Solution
{
    public:
        string reorganizeString(string s) {
            map<char,int> m;
            for( char c:s){
               m[c]++; 
            }
            priority_queue<pair<int,char>>pq;
            for(auto x:m){
                pq.push(make_pair(x.second,x.first));
            }    
            string ans="";
            while(!pq.empty()){
                pair<int,char> p=pq.top();
                pq.pop();
                if(ans.size()>0 && ans[ans.size()-1]==p.second){
                    if(pq.empty()){
                        return "";
                    }
                    pair<int,char> p1=pq.top();
                    pq.pop();
                    ans.push_back(p1.second);
                    if(p1.first>1){
                       pq.push(make_pair(p1.first-1,p1.second)); 
                    }  
                }
                 ans.push_back(p.second);
                    if(p.first>1){
                       pq.push(make_pair(p.first-1,p.second)); 
                    }
                cout<<ans<<endl;
            }
            return ans;
        }
};