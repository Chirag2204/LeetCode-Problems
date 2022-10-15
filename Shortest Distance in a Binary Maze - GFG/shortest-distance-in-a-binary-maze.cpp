//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool isvalid(vector<vector<int>>& grid,int x,int y){
      return x>=0 and x<grid.size() and y>=0 and y<grid[0].size() and grid[x][y]==1;
  }
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        if(grid[source.first][source.second]!=1)return -1;
        if(source==destination)return 0;
        
        queue<pair<pair<int,int>,int>> q;//point dist
        
        q.push({source,0});
        grid[source.first][source.second]=0;
        while(!q.empty()){
            int x=q.front().first.first;
            int y= q.front().first.second;
            int dist=q.front().second;
           // cout<<x<<" "<<y<<" "<<dist<<endl;
            q.pop();
            
            if(isvalid(grid,x-1,y)){
                if(x-1== destination.first and y==destination.second)return dist+1;
                grid[x-1][y]=0;
                q.push({{x-1,y},dist+1});
            }
            
             if(isvalid(grid,x,y-1)){
                if(x== destination.first and y-1==destination.second)return dist+1;
                grid[x][y-1]=0;
                q.push({{x,y-1},dist+1});
            }
            
            if(isvalid(grid,x+1,y)){
                if(x+1== destination.first and y==destination.second)return dist+1;
                grid[x+1][y]=0;
                q.push({{x+1,y},dist+1});
            }
            
             if(isvalid(grid,x,y+1)){
                if(x== destination.first and y+1==destination.second)return dist+1;
                grid[x][y+1]=0;
                q.push({{x,y+1},dist+1});
            }
            
        }
        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends