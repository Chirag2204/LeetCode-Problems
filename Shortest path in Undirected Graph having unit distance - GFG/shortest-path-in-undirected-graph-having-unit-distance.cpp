//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> dist(N,1e9);
        
        map<int,vector<int>> m;
        for(auto& x:edges){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        
        queue<pair<int,int>> q;
        q.push({src,0});
        
        while(!q.empty()){
            int x=q.front().first;
            int dis=q.front().second;
            q.pop();
            if(dis<dist[x]){
                dist[x]=dis;
                for(auto& i:m[x]){
                    q.push({i,dis+1});
                }
            }
        }
        for(int i=0;i<N;i++)if(dist[i]==1e9)dist[i]=-1;
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends