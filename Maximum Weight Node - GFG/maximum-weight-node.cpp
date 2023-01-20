//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      if(Edge.size()==1)return 0;
      unordered_map<int,int> m;
      int mx=0;
      int ans=0;
      for(int i=0;i<N;i++){
          m[Edge[i]]+=i;
          if(mx<=m[Edge[i]]){
              if(mx==m[Edge[i]] and Edge[i]>ans){
                  ans=Edge[i];
              }else if(mx<m[Edge[i]]){
                  mx=m[Edge[i]];
                  ans=Edge[i];
              }
          }
      }
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends