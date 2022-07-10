class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<long long> diffs(100001,0);
        priority_queue<long long> pq;
        for(int i=0;i<nums1.size();i++){
            long long n=abs(nums1[i]-nums2[i]);
            if(diffs[n]==0)
              pq.push(n);
            diffs[n]++;
        }
        
        long long k=k1+k2;
        while(k>0){
            if(pq.empty())return 0;
            int t=pq.top();
            if(t==0)return 0;
            if(diffs[t]<=k){
                k-=diffs[t];
                pq.pop();
                if(diffs[t-1]==0)pq.push(t-1);
                diffs[t-1]+=diffs[t];
                diffs[t]=0;
            }
            else{
               if(diffs[t-1]==0)pq.push(t-1); 
                diffs[t-1]+=k;
                diffs[t]-=k;
                k=0;
                break;
            }
        }
        
        long long ans=0;
        while(!pq.empty()){
            long long t=pq.top();
            pq.pop();
            ans+=diffs[t]*t*t;
        }
        return ans;
    }
};