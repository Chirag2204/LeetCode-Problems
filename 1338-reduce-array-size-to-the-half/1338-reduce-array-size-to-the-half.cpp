class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> m;
        priority_queue<pair<int,int>> pq;
        for(auto i: arr){
            m[i]++;
        }
        for(auto i:m){
            pq.push(make_pair(i.second,i.first));
        }
        int n=arr.size();
        int sum=0;
        int count=0;
        while(sum<n/2){
            count++;
            pair<int,int> p=pq.top();
            pq.pop();
            sum+=p.first;
        }
        return count;
    }
};