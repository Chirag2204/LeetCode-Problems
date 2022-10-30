//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   string solve(string &s , int &i){
        string ans="";
        
        while(i<s.length() and s[i] != ']'){
           if(!isdigit(s[i]) )ans.push_back(s[i++]);
            else{
                int n=0;
                while(i<s.length() and isdigit(s[i])){
                    n=n*10 + s[i++]-48;
                }
                i++;
                string str=solve(s,i);
                i++;
              
                while(n>0){
                    ans+=str;
                    n--;
                }
            }
        }
        return ans;
    }
    string decodedString(string s) {
        int i=0;
        
        return solve(s,i);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends