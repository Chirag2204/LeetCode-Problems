//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool comp(vector<int>& a,vector<int>& b){
      for(int i=0;i<4;i++){
          if(a[i]<b[i])return false;
          if(a[i]>b[i])return true;
      }
      return false;
  }
  
    vector<int> satisfyEqn(int A[], int N) {
        vector<int> ans;
        vector<int> temp;
        map<int,pair<int,int>> m;
        
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(m.count(A[i]+A[j])){
                    //cout<<"here "<<i<<" "<<j<<endl;
                    int x=m[A[i]+A[j]].first;
                    int y=m[A[i]+A[j]].second;
                   if((x!=i and x!=j) and (y!=i and y!=j)){
                       temp={x ,y,i,j};
                      if(ans.size()==0 or comp(ans,temp))
                       ans=temp;
                   }
                   
                }else m[A[i]+A[j]]={i,j};
            }
        }
        if(ans.size()==0)return {-1,-1,-1,-1};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends