//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        vector<int> vis(S.length());
        int count=0;
    
            int i=0,j=0;
            while(j<S.length()){
                if(!vis[j] and S[j]==W[i]){
                    i++;
                    vis[j]=1;
                }
                if(i==W.length()){
                    //cout<<temp<<" "<<j<<endl;
                    i=0;
                    j=0;
                    count++;
                 }
                j++;
                
            }
        
        
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends