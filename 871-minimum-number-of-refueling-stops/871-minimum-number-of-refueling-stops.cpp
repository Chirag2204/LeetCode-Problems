class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(target<=startFuel)return 0;
        if(target>startFuel and stations.size()==0)return -1;
        if(startFuel<stations[0][0])return -1;
        
       priority_queue<int> pq;
        
        int count=0,fuel=startFuel,i=0;
        while(fuel<target){
            while(i<stations.size() and stations[i][0]<=fuel){
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty())return -1;
            
            count++;
            fuel+=pq.top();
            pq.pop();
            
        }
        return count;
        
    }
};