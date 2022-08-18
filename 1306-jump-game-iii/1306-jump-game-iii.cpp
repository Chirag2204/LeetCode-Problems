class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==0)return true;
        int n=arr.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int temp=q.front();
            if(arr[temp]==0)return true;
            q.pop();
            if(temp+arr[temp]<n and vis[temp+arr[temp]]==0){
                vis[temp+arr[temp]]=1;
                q.push(temp+arr[temp]);
            }
            if(temp-arr[temp]>=0 and vis[temp-arr[temp]]==0){
                vis[temp-arr[temp]]=1;
                q.push(temp-arr[temp]);
            }
        }
        return false;
    }
    
    
};