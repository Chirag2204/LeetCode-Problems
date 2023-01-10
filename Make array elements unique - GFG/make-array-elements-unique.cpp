//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // long long ans=0;
        // unordered_set<int> s;
        // long long prev=0;
        
        // sort(arr.begin(),arr.end());
        
        // for(int &i:arr){
        //     if(!s.count(i)){
        //         s.insert(i);
        //         prev=i;
        //     }else{
        //         ans+= abs(i-prev)+1;
        //         prev++;
        //         s.insert(prev);
        //     }
        // }
        // return ans;
        
        //alternate
        long long ans=0;
        unordered_set<int> s;
        sort(arr.begin(),arr.end());
        
        for(int& i:arr){
            if(!s.count(i))s.insert(i);
            else{
                int j=0;
                while(s.count(i+j))j++;
                s.insert(i+j);
                ans+=j;
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends