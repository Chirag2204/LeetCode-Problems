//dp solution tle
// class Solution {
// public:
//     //dp section
//     int solve(vector<vector<int>>& courses,int index,int end,vector<vector<int>>& dp){
//        if(index>=courses.size())return 0;
        
//         if(dp[index][end]!=-1)return dp[index][end];
//         int include=0;
       
//         if(courses[index][1]>=end+courses[index][0]){
//             include=1+solve(courses,index+1,end+courses[index][0],dp);
//         }
//         int notinclude=solve(courses,index+1,end,dp);
//         // cout<<end<<" "<<index<<endl;
//         return dp[index][end]=max(include,notinclude);
        
//     }
//     //main method
//     int scheduleCourse(vector<vector<int>>& courses) {
//         // sort(courses.begin(),courses.end(),mysort);
        
//         int count=0;
//         int end=0;
//         vector<vector<int>> dp(courses.size()+1,vector<int>(courses[courses.size()-1][1]+1,-1));
        
//         int ans= solve(courses,0,end,dp);
//         // for(int& i:dp)cout<<i<<endl;
//         return ans;
//     }
//     //sorting
//     static bool mysort(vector<int>& a,vector<int>&b){
//         if(a[1]==b[1])return a[0]<b[0];
//         return a[1]<b[1];
//     }
// };

class Solution {
public:
   
    int scheduleCourse(vector<vector<int>>& courses) {
       sort(courses.begin(),courses.end(),mysort);
       priority_queue<int>pq;
        int total=0;
        for(int i=0;i<courses.size();i++){
            if(courses[i][0]+total <= courses[i][1]){
                total+=courses[i][0];
                pq.push(courses[i][0]);
            }
            else if(!pq.empty() && pq.top()>courses[i][0]){
                int t=pq.top();
                pq.pop();
                pq.push(courses[i][0]);
                total+=courses[i][0]-t;
            }
        }
        return pq.size();
    }
    
    static bool mysort(vector<int>& a,vector<int>&b){
        if(a[1]==b[1])return a[0]<b[0];
        return a[1]<b[1];
    }

};