//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        map<int,vector<pair<int,int>>> m;// node node,dist
        
        vector<int> cities(n+1,1e9);
        
        for(auto& x:flights){
            m[x[0]].push_back({x[1],x[2]});
        }
        
        queue<pair<int,int>> q;// node dist
        
        q.push({k,0});
        
        while(!q.empty()){
            int x=q.front().first;
            int dist= q.front().second;
            
            q.pop();
            if(cities[x]>dist){
                cities[x]=dist;
                for(auto& v: m[x]){
                    q.push({v.first,dist+v.second});
                }
            }
        }
        
        int ans=0;
        for(int i=1;i<=n;i++){
            // cout<<i<<" ";
            ans=max(cities[i],ans);
        }
        
        if(ans==1e9)return -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends