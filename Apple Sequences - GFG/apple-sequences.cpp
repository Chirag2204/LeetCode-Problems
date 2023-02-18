//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int i=0,j=0;
        int count=0;
        int ans=0;
        while(j< arr.length()){
            if(arr[j]=='O'){
                if(count>=m){
                while(arr[i]!='O')i++;
                i++;
                
              }else count++;
            }
            
            //cout<<i<<" "<<j<<endl;
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends