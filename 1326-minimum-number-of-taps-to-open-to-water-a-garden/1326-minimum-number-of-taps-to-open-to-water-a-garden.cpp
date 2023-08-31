class Solution {
public:
    static bool mysort(vector<int> a,vector<int> b){
        if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    
    int solve(int index,vector<int>& intervals,int &n,vector<int>& dp){
       if(index>=n)return 0;
        
        if(intervals[index]==0)return 1e7;
        
        if(dp[index]!=-1)return dp[index];
        int ans=1e7;
        for(int i=index+1;i<=intervals[index];i++){
            ans = min(ans,1+solve(i,intervals,n,dp));
        }
        
        return dp[index]=ans;
       
    }
    
    int minTaps(int n, vector<int>& ranges) {
       vector<int> maxreach(n+1);
        int left=0,right=0;
        for(int i=0;i<=n;i++){
            left= max(0,i-ranges[i]);
            right= min(n, i+ranges[i]);
            
            maxreach[left]= max(maxreach[left],right);
        }
        vector<int> dp(n+1,-1);
        int ans= solve(0,maxreach,n,dp);
        
        return ans<1000000?ans:-1;
    }
};