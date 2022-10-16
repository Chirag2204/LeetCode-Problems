class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<labels.size();i++){
            pq.push({values[i],labels[i]});
        }
        
        map<int,int> m;
        int ans=0;
        while(numWanted and !pq.empty()){
            pair<int,int>t= pq.top();
            pq.pop();
            
            if(!m.count(t.second) or m[t.second]<useLimit){
                ans+=t.first;
                m[t.second]++;
                numWanted--;
            }
        }
        return ans;
    }
};