//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void dfs(vector<vector<int>>& mat,int i,int j,int& count){
        if(i>0 and mat[i-1][j]){
            mat[i-1][j]=0;
            count++;
            dfs(mat,i-1,j,count);
        }
         if(i<mat.size()-1 and mat[i+1][j]){
            mat[i+1][j]=0;
            count++;
            dfs(mat,i+1,j,count);
        }
         if(j>0 and mat[i][j-1]){
            mat[i][j-1]=0;
            count++;
            dfs(mat,i,j-1,count);
        }
         if(j<mat[0].size()-1 and mat[i][j+1]){
            mat[i][j+1]=0;
            count++;
            dfs(mat,i,j+1,count);
        }
    }
    
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            vector<int> srow(n,0);
            vector<int> scol(m,0);
            
            for(auto& x:enemy){
                srow[x[0]-1]=1;
               scol[x[1]-1]=1;
            }
            
          
           
           int rows=0,cols=0;
           int count=0;
           for(int i=0;i<n;i++){
               if(!srow[i])count++;
               else count=0;
               rows=max(rows,count);
           }
           count=0;
           for(int i=0;i<m;i++){
               if(!scol[i])count++;
               else count=0;
               cols=max(cols,count);
           }
            return rows*cols;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends