//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        set<string> st;
        int i=0;
        for(int j=0;j<n;j++){
            if(contact[j][0]==s[0])st.insert(contact[j]);
        }
        vector<vector<string>> ans;
        vector<string> temp;
        for(auto& x:st){
            temp.push_back(x);
        }
        if(temp.size()==0)temp.push_back("0");
        ans.push_back(temp);
        temp.clear();
        i++;
        while(i<s.length()){
            if(st.size()==0){
                temp.push_back("0");
            }
            else{
               for(auto& x:st){
                if(s[i]==x[i]){
                    temp.push_back(x);
                }
              } 
              st.clear();
              for(string& x:temp)st.insert(x);
            }
            if(temp.size()==0)temp.push_back("0");
            ans.push_back(temp);
            temp.clear();
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends