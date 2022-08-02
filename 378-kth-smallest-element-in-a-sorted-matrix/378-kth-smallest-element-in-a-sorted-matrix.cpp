class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //naive approach
        // priority_queue<int> pq;
        // for(auto& m:matrix){
        //     for(int& i:m)pq.push(-i);
        // }
        // while(k>1){
        //     pq.pop();
        //     k--;
        // }
        // return -pq.top();
        
        //binary search
        int n=matrix.size();
        int s=matrix[0][0],e=matrix[n-1][n-1];
        
        int mid=s+(e-s)/2;
        while(s<e){

            int pos=0;
            for(int i=0;i<n;i++){
                pos+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(pos<k){
                s=mid+1;
            }else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }
};