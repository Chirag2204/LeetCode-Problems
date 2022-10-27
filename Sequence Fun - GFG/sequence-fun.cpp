//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
	int mod=1e9+7;
		int NthTerm(int n){
		    long long prev=1;
		    int i=1;
		    while(n--){
		        prev=i*prev+1;
		        prev%=mod;
		        i++;
		    }
		    return int(prev);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends