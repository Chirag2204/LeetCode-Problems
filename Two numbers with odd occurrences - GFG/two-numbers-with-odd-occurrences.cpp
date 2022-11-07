//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int nums[], long long int N)  
    {
         long long xr=0;
        for(long long i=0;i<N;i++)xr^=nums[i];

        xr&=-xr;//to get least or right most bit in xr

        vector<long long> ans{0,0};

        for(long long i=0;i<N;i++){
            if(xr&nums[i])ans[0]^=nums[i];
            else ans[1]^=nums[i];
        }
        if(ans[1]>ans[0])swap(ans[0],ans[1]);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends