class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
    
        pq.push({a,'a'});
        pq.push({b,'b'});
        pq.push({c,'c'});
        
        int count=0;
        string ans="";
        pair<int,char> left;
        bool push=false;
        while(!pq.empty() and pq.top().first>0){
            if(count>=2 and pq.top().second==ans[ans.size()-1]){
                left=pq.top();
                push=true;
                pq.pop();
                count=0;
            }else{
               char t=pq.top().second;
               int amt=pq.top().first;
               pq.pop();
                if(ans.size()==0 or t==ans[ans.size()-1]){
                    count++; 
                }else 
                    count=1;
                
               ans.push_back(t);
              
                if(amt-1>0)
                  pq.push({amt-1,t});
                
                if(push){
                    pq.push(left);
                    push=false;
                }
            }
 
        }
        return ans;
    }
};