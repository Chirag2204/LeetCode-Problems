//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string buildLowestNumber(string num, int k);
// Driver program to test above function
int main()
{
    int t,n;
    string str;
    cin>>t;
    while(t--)
    {
    cin>>n;
    cin>>str;
    cout << buildLowestNumber(str, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends


string buildLowestNumber(string num, int k)
{
    stack<char> st;
    st.push(num[0]);
    for(int i=1;i<num.length();i++){
        while(!st.empty() and num[i]<st.top() and k>0){
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while(k--)st.pop();
    
    string ans="";
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    while(ans.back()=='0')ans.pop_back();
    reverse(ans.begin(),ans.end());
    if(ans.size()==0)return "0";
    return ans;
}