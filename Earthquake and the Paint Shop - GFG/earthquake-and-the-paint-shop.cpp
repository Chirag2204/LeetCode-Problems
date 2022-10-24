//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct alphanumeric {
    string name;
    int count;
    
};
class Solution {
  public:
  static bool mysort(alphanumeric& a,alphanumeric& b){
      if(a.name==b.name)return a.count<b.count;
      
      return a.name< b.name;
  }
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        map<string,int> m;
        for(string &s:A){
            m[s]++;
        }
        
        vector<alphanumeric> ans;
        for(auto& x: m){
            alphanumeric a;
            a.name=x.first;
            a.count=x.second;
            ans.push_back(a);
        }
        sort(ans.begin(),ans.end(),mysort);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u : ans) cout << u.name << " " << u.count << "\n";
    }
}
// } Driver Code Ends