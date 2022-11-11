//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int K){
		    int ans=0;
		    for(int i=0;i<26;i++){
		        int count=0;
		        char c=char(65+i);
		        int j=0,k=0;
		        //cout<<c<<endl;
		        while(k<s.length()){
		            if(s[k]!=c){
		                if(count<K){
		                    count++;
		                }else{
		                    while(s[j]==c)j++;
		                    j++;
		                    
		                }
		                
		            }
		            //cout<<k<<" "<<j<<count<<endl;
		            ans=max(ans,k-j+1);
		            k++;
		        }
		        
		    }
		    return ans;
		}
		
// 		RXDMBPZHNXQPPGHRIZ
//          6

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends