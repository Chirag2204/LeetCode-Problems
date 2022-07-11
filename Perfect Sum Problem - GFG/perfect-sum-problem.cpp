// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int arr[],int& n,int index,int target,vector<vector<int>>& dp){
	    
	    
	    if(index==n-1){
	        if(target==0 && arr[index]==0)return 2;
	        if(target==0 || target==arr[index])return 1;
	        return 0;
	    }
	    if(dp[index][target]!=-1)return dp[index][target];
	    
	    int notinclude=solve(arr,n,index+1,target,dp);
	    int include=0;
	    if(target>=arr[index])
	    include=solve(arr,n,index+1,target-arr[index],dp);
	    
	    
	   
	    return dp[index][target]=(include+notinclude)%1000000007;
	    
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    
        vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        return solve(arr,n,0,sum,dp);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends