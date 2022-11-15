//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        vector<int> m(26);
        int ans=0;
        for(int i=0;i<s.length();i++){
           for(int j=i;j<s.length();j++){
               m[s[j]-97]++;
               int mn=1e9,mx=0;
               for(int i=0;i<26;i++){
                   mx=max(mx,m[i]);
                   if(m[i]!=0)
                   mn=min(mn,m[i]);
               }
               if(mn<1e9)
                 ans+=mx-mn;
           }
           for(int i=0;i<26;i++)m[i]=0;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends