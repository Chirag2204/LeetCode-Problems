class Solution {
public:
    //nnamive approach
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(auto& m:matrix){
            for(int& i:m)pq.push(-i);
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return -pq.top();
    }
};