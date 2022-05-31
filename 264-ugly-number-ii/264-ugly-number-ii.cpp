class Solution {
public:
    
    
    int nthUglyNumber(int n) {
      priority_queue<long long, vector<long long>, greater<long long>> pq;
        map<long long,long long> m;
        pq.push(1);
        int count=0;
        long long x;
        while(count<n){
             x=pq.top();
            pq.pop();
            if(m[x]==0){
                count++;
               pq.push(x*2);
                pq.push(x*3);
                pq.push(x*5);
                m[x]=1;
            }
            
        }
        return x;
    }
};