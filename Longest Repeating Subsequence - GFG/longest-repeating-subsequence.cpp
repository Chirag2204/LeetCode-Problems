//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int solve(int index1,int index2,string& str,vector<vector<int>>& dp){
	        if(index1>=str.length() or index2>=str.length())return 0;
	        
	        if(dp[index1][index2]!=-1)return dp[index1][index2];
	        
	        int match=0,move1=0,move2=0;
	        
	        if(index1!=index2 and str[index1]==str[index2]){
	            match=1+ solve(index1+1,index2+1,str,dp);
	        }
	        else{
	            move1= solve(index1+1,index2,str,dp);
	            move2= solve(index1,index2+1,str,dp);
	        }
	        
	        return dp[index1][index2]= max(match,max(move1,move2));
	        
	    }
	    
		int LongestRepeatingSubsequence(string str){
	        vector<vector<int>> dp(str.length()+1,vector<int>(str.length()+1,-1));
	        
	        return solve(0,0,str,dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends