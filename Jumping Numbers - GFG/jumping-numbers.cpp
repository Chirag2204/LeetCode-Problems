//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
 long long maxi(long long &a,long long &b){
     if(a<b)return b;
     return a;
 }
 
    long long jumpingNums(long long X) {
        queue<long long> q;
        
        for(long long i=1;i<=9;i++)q.push(i);
        long long  ans=0;
        while(!q.empty()){
            long long x=q.front();
            
            q.pop();
            if(x>X)continue;
            ans=maxi(ans,x);
            long long mod=x%10;
            if(mod>=1){
               q.push(x*10 + mod-1);
            }
            if(mod<9){
                q.push(x*10 + mod+1);
            }
        }
        return ans;
        
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends