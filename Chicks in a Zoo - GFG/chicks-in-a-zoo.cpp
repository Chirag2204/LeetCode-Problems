//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int NoOfChicks(int n){
	    long long ans=1;
	    int count=1;
	    long long x=1;
	    long long rev=1;
	    vector<long long> nums(36,0);
	    nums[0]=1;
	    while(count<n){
	        
	        if(count>=6){
	           ans-=nums[count-6];
	        }
	        long long x=ans*2;
	        ans*=3;
	        nums[count]=x;
	        count++;
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
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends