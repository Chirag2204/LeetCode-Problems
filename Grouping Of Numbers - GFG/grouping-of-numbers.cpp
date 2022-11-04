//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int n, int k) {
        if(k==1 or n==1)return 1;
        vector<int> mods(k);
        int ans=0;
        for(int i=0;i<n;i++){
            mods[arr[i]%k]++;
        }
       
       if(mods[0])ans++;
        int i=1,j=k-1;
        while(i<j){
            ans+=max(mods[i],mods[j]);
            i++;
            j--;
        }
        if(i==j and mods[i])ans++;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends