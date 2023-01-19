//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int  count1=0,count2=0;
        int a=A,b=B;
        
        while(a>C){
            count1++;
            a/=2;
        }
        while(b>D){
            count1++;
            b/=2;
        }
        a=A,b=B;
        
        while(a>D){
            count2++;
            a/=2;
        }
        while(b>C){
            count2++;
            b/=2;
        }
        
        return min(count1,count2);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends