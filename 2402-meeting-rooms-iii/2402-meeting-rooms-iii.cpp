class Solution {
public:

//     int mostBooked(int n, vector<vector<int>>& meetings) {
//         vector<int> rooms(n,0);
//         priority_queue<pair<int,int>> pq;//endtime,room
        
//         sort(meetings.begin(),meetings.end());
        
//         int count=0;
//         int totaldif=0;
//         for(int i=0;i<meetings.size();i++){
//            if(pq.empty()){
//                pq.push({-meetings[i][1],0});
//                cout<<meetings[i][0]<<" "<<0<<endl;
//                rooms[0]++;
//                count=1;
//            }else{
//                int end=-pq.top().first;
//                int room=pq.top().second;
               
               
//                if(end <= meetings[i][0]+totaldif){
//                    pq.pop();
//                   pq.push({-(meetings[i][1]+totaldif),room});
//                    cout<<meetings[i][0]<<" "<<room<<endl;
//                    rooms[room]++;
//                }else{
//                    if(pq.size()<n){
//                        pq.push({-(meetings[i][1]+totaldif),count});
//                        cout<<meetings[i][0]<<" "<<count<<endl;
//                        rooms[count]++;
//                        count++;
//                    }else{
//                        cout<<meetings[i][0]<<" "<<room<<endl;
//                       int dif=end-(meetings[i][0]+totaldif);
//                        totaldif+=dif;
//                        // meetings[i][0]+=dif;
//                        // meetings[i][1]+=dif;
//                        pq.pop();//end meeting
//                        pq.push({-(meetings[i][1]+totaldif),room});
//                        rooms[room]++;
                       
//                    }
//                }
//            }
//         }
//         int ans=0,mx=0;
//         for(int i=0;i<n;i++){
//             if(mx<rooms[i]){
//                 mx=rooms[i];
//                 ans=i;
//             }
//         }
//         return ans;
//     }
    
    long long getmin(vector<long long>& nums,long long start){
        long long mn=1e18,ans=0;
        for(long long i=0;i<nums.size();i++){
           if(start>=nums[i])return i; 
        }
        
        for(long long i=0;i<nums.size();i++){
           if(mn>nums[i]){
              ans=i;
               mn=nums[i];
           }
        }
        return ans;
    }
    
     int mostBooked(int n, vector<vector<int>>& meetings) {
         vector<long long> endtime(n,-1);
         vector<int> rooms(n,0);
         
         sort(meetings.begin(),meetings.end());
         
         for(int i=0;i<meetings.size();i++){
            long long room=getmin(endtime,(long long)meetings[i][0]);
             
             long long dif= endtime[room]-meetings[i][0];
             long long val=meetings[i][1];
             if(dif>0){
                val+=dif;
             }
             
             endtime[room]=val;
                rooms[room]++;
         }
         int ans=0,mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(mx<rooms[i]){
                mx=rooms[i];
                ans=i;
            }
        }
        return ans;
    }
};