//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    string BalancedString(int n) {
        string s="abcdefghijklmnopqrstuvwxyz";
        string ans="";
        int temp=n;
        while(n>=26){
            ans+=s;
            n-=26;
        }
        
        int x=n/2;
        for(int i=0;i<x;i++)ans.push_back(s[i]);
        string next="";
        for(int i=25;i>25-x;i--)next.push_back(s[i]);
        if(temp%2){
            string num=to_string(temp);
            int sum=0;
            for(char& c:num)sum+=c-48;
            if(sum%2==0)
             ans.push_back(s[x]);
             else
             next.push_back(s[25-x]);
        }
        reverse(next.begin(),next.end());
        return ans+next;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends