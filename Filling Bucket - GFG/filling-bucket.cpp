//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int mod=1e8;
  long long solve(int n,vector<long long>& dp){
     if(n==0)return 1;
     
     if(dp[n]!=-1)return dp[n];
     
     long long one=solve(n-1,dp);
     
     long long two=0;
     if(n>=2)two=solve(n-2,dp);
     
     return dp[n]=(one + two )%mod;
     }
  
    int fillingBucket(int N) {
        vector<long long> dp(N+1,-1);
        
        return (int)solve(N,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends