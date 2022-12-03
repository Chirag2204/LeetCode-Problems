//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(int& x,int k,vector<int>& stalls){
        int prev=stalls[0];
        
        for(int i=1;i<stalls.size();i++){
            if(k==1)return true;
            if(stalls[i]-prev>=x){
                k--;
                prev=stalls[i];
            }
        }
        return k==1;
        
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        
        int s=0,e=stalls[stalls.size()-1];
        int mid=s+(e-s)/2;
        int ans=0;
        while(s<=e){
            if(isPossible(mid,k,stalls)){
                ans=mid;
                s=mid+1;
            }else e=mid-1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends