//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        queue<pair<int,int>> q;// vertex dist
        
        map<int,vector<pair<int,int>>> m;
        for(auto& x:edges){
            m[x[0]].push_back({x[1],x[2]});
        }
        
        q.push({0,0});
        
        vector<int> dist(N,1e9);
        
        while(!q.empty()){
            int x=q.front().first;
            int dis= q.front().second;
            
            q.pop();
            
            if(dist[x]>dis){
                dist[x]=dis;
                for(auto& a:m[x]){
                    q.push({a.first,a.second+dis});
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9)dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends