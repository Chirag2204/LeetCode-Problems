//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int,int> m;
        
        for(int& i:nums){
            m[i%k]++;
        }
        
        if(m[0]%2)return false;
        
        for(int i=1;i<k;i++){
            if(m[i]!=m[k-i])return false;
            m[i]=0;
            m[k-i]=0;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends