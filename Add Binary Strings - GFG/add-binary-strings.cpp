//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b)
	{
	
	    while(a[0]=='0')a.erase(a.begin());
	    while(b[0]=='0')b.erase(b.begin());
	    int diff=max(a.length(),b.length())-min(a.length(),b.length());
	    
	    string s(diff,'0');
	    
	    if(a.length()<b.length())a=s+a;
	    else b=s+b;
	    string ans="";
	    int carry=0;
	    for(int i=a.length()-1;i>=0;i--){
	        if(a[i]=='1' and b[i]=='1'){
	            if(carry){
	                ans.push_back('1');
	            }else ans.push_back('0');
	            carry=1;
	        }
	        else if(a[i]=='0' and b[i]=='0'){
	            if(carry){
	                ans.push_back('1');
	            }else ans.push_back('0');
	            carry=0;
	        }
	        else{
	           if(carry){
	                ans.push_back('0');
	                carry=1; 
	            }else {
	                ans.push_back('1');
	                carry=0;
	            }
	            
	        }
	    }
	    if(carry)ans.push_back('1');
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends