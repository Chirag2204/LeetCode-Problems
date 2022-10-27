//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   map<int,int> m;
    int getPosition(vector<int>& inorder,int& x){
        if(m.count(x))return m[x];
        return -1;
    }
    vector<int> ans;
    
    int  solve(vector<int>& preorder,vector<int>& inorder,int& index,int start,int end){
        if(index>=inorder.size() || start>end){
            return -1;
        }
        int x=preorder[index];
        index++;
       
        int position=getPosition(inorder,x);//to get position of element in inorder
        
        int left=solve(preorder,inorder,index,start,position-1);
        int right=solve(preorder,inorder,index,position+1,end);
        if(left==-1 and right==-1)ans.push_back(x);
        return x;
        
    }
    vector<int> leafNodes(int arr[],int N) {
        vector<int> inorder;
        vector<int> preorder;
        for(int i=0;i<N;i++){
            inorder.push_back(arr[i]);
            preorder.push_back(arr[i]);
        }
        
        sort(inorder.begin(),inorder.end());
         for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        int index=0;
        solve(preorder,inorder,index,0,preorder.size()-1);
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
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends