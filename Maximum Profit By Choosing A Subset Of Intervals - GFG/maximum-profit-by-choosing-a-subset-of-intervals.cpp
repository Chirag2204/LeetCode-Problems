//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  static bool mysort(vector<int>& a,vector<int>& b){
    if(a[0]==b[0]){
        if(a[1]==b[1])return a[2]>b[2];
        return a[1]<b[1];
    }
    return a[0]<b[0];
}

int find(int end,vector<vector<int>>& slots){
    int ans=slots.size();

    int s=0,e=slots.size()-1;
    int mid=s+(e-s)/2;

    while(s<=e){
        if(slots[mid][0]>=end){
            ans=mid;
            e=mid-1;
        }else s=mid+1;

        mid=s+(e-s)/2;
    }
    return ans;
}

  
  int solve(vector<vector<int>>& slots,int index, vector<int>& dp ){
       if(index>=slots.size()){
           return 0;
       }

        if( dp[index]!=-1)return dp[index];
        int include=0,notinclude=0;

    
           int newindex=find(slots[index][1],slots);
           include=slots[index][2] + solve(slots,newindex,dp);

            notinclude= solve(slots,index+1,dp);

            return dp[index]=max(include,notinclude);
   }
  
    int maximum_profit(int n, vector<vector<int>> &slots) {
         sort(slots.begin(),slots.end(),mysort);
        vector<int> dp(n+1,-1);

       return solve(slots,0,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends