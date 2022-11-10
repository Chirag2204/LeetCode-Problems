//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    string isSumOfTwo(int N){
        vector<bool> primes(N+1,true);
        for(int i=2;i<=N;i++){
            if(primes[i]){
                for(int j=2;j<=N/i;j++){
                    primes[i*j]=false;
                }
            }
        }
        
        for(int i=2;i<=N/2;i++){
            if(primes[i] and primes[N-i])return "Yes";
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends