//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int isPossible(int arr[],int &n,int& k,int& x){
        int sum=0;
        int count=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]>x)return false;
            if(sum+arr[i]>x){
                count++;
                sum=0;
            }
            sum+=arr[i];
        }
        if(count>=k)return false;
        if(count<k-1)return 2;
        return count==k-1;
    }
    
    int splitArray(int arr[] ,int n, int k) {
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
        int s=1,e=sum;
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
          
            int res=isPossible(arr,n,k,mid);
             //cout<<mid<<" "<<res<<endl;
            if(res){
                // if(res==1)
                   ans=mid;
                 e=mid-1;
                
            }else s=mid+1;
            mid=s+(e-s)/2;
        }
        return ans;
    }
    
    // 9 6
    //  5 10 10 2 1 7 8 9 5
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends