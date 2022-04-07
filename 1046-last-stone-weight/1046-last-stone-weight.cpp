class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int i=pq.top();
            pq.pop();
            int j=pq.top();
            pq.pop();
            if(i!=j){
                pq.push(i-j);
            }
            if(pq.size()==1){
                return pq.top();
            }
        }
        if(pq.size()==1){
                return pq.top();
            }
        return 0;
    }
};