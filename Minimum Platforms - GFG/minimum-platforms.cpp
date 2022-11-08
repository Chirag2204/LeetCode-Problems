//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool mysort(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first)return a.second<b.second;
        return a.first<b.first;
    }
    
    int findPlatform(int at[], int dt[], int n)
    {
    	vector<pair<int,int>> nums;
    for(int i=0;i<n;i++){
        nums.push_back({at[i],dt[i]});
    }
    
    sort(nums.begin(),nums.end(),mysort);
   
    
    int mx=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    int n1;
    for(int i=0;i<n;i++){
        if(!pq.empty() and pq.top()<nums[i].first)pq.pop();
        pq.push(nums[i].second);
        n1=pq.size();
        mx=max(mx,n1);
    }
//     mx=max(mx,pq.size());
    return mx;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends