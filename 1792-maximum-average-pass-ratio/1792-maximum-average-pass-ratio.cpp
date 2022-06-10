class Solution {
public:
    double onadding1(vector<int>& v){
        return ((double)(v[0]+1)/(double)(v[1]+1))-((double)(v[0])/(double)(v[1]));
    }
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<classes.size();i++){
            pq.push(make_pair(onadding1(classes[i]),i));
        }
        while(extraStudents--){
            pair<double,int> p=pq.top();
            pq.pop();
            // cout<<p.first<<" "<<p.second<<endl;
            classes[p.second][0]++;
            classes[p.second][1]++;
            p.first=onadding1(classes[p.second]);
            pq.push(p);
        }
        double ans=0;
        for(int i=0;i<classes.size();i++){
            ans+=(double)(classes[i][0])/(double)(classes[i][1]);
        }
        return ans/classes.size();
    }
};