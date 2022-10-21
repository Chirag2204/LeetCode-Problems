//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        vector<int> ans;
        
        int startrow=0,startcol=0,endrow=R-1,endcol=C-1;
        
        while(startrow<=endrow and startcol<=endcol){
            for(int i=startcol;i<=endcol;i++){
                ans.push_back(a[startrow][i]);
            }
            
            startrow++;
              for(int i=startrow;i<=endrow;i++){
                  ans.push_back(a[i][endcol]);
              }
              endcol--;
              if(startrow<=endrow){
                  for(int i=endcol;i>=startcol;i--){
                     ans.push_back(a[endrow][i]); 
                  }
                  endrow--;
              }
              if(startcol<=endcol){
                  for(int i=endrow;i>=startrow;i--){
                      ans.push_back(a[i][startcol]);
                  }
                  startcol++;
              }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends