class Solution {
public:
    int getupper(vector<vector<int>>& events,int& x){
        int ans=-1;
        int s=0,e=events.size()-1;
        int mid=s+(e-s)/2;
        
        while(s<=e){
            if(events[mid][0]>x){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
    
    int solve(int index,vector<vector<int>>& events,int count,vector<vector<int>>& dp){
        //cout<<index<<endl;
        if(index>=events.size() or index==-1 or count==0)return 0;
        if(dp[index][count]!=-1)return dp[index][count];
        int include=0,notinclude=0;
        
        include= events[index][2] + solve(getupper(events,events[index][1]),events,count-1,dp);
        // cout<<"-----"<<endl;
        notinclude= solve(index+1,events,count,dp);
        //cout<<"-----"<<endl;
        return dp[index][count]= max(include,notinclude);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {  
        vector<vector<int>> dp(events.size(),vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        return solve(0,events,k,dp);
    }
    
   
};