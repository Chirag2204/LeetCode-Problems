class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        
 
        
        vector<int> vis(arr.size(),0);
        queue<pair<int,int>> q;
        q.push({0,0});
        
        while(!q.empty()){
            int node=q.front().first;
            int dist= q.front().second;
            //cout<<node<<" ";
            if(node==arr.size()-1)return dist;
            vector<int> &next=m[arr[node]];
            if(node>0)next.push_back(node-1);
            if(node<arr.size()-1)next.push_back(node+1);
            
            q.pop();
            vis[node]=1;
        
            for(auto& x: next){
                if(!vis[x]){
                    vis[x]=1;
                   
                    q.push({x,dist+1});
                }
            }
            next.clear();
          
        }
        return -1;
    }
    
};