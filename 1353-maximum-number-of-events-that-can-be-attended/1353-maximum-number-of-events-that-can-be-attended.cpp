class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int count=0;
        
        int end=0;
        for(auto& x:events){
            end=max(end,x[1]);
        }
        priority_queue<int> pq;
        int j=0;
        for(int i=1;i<=end;i++){
            //these are not possible to attend
            while(!pq.empty() and -pq.top()<i){
               pq.pop();    
            }
            
            //getting all events going to start on day i
            while(j<events.size() and events[j][0]==i){
                pq.push(-events[j][1]);//pushing their end date
                j++;
            }
            
            //finishing the event with most close end date on day i
            if(!pq.empty()){
                pq.pop();
                count++;
            }
        }
        
        return count;
    }
 
};