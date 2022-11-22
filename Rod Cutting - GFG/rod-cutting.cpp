//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price[], int index,int& n,int num,vector<vector<int>>& dp){
      if(index>=n){
          if(num==0)return 0;
          
          return -1e9;
      }
      
      if(dp[index][num]!= -1)return dp[index][num];
      int include=-1e9,notinclude=-1e9;
      if(index+1<=num){
          include=price[index]+solve(price,index,n,num-index-1,dp);
      }
      notinclude=solve(price,index+1,n,num,dp);
      
      return dp[index][num]= max(include,notinclude);
  }
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        return solve(price,0,n,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends