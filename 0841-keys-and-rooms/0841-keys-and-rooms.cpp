class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int val,vector<int>& visited){
        if(visited[val])return ;
        visited[val]=1;
        for(int& i: rooms[val]){
            dfs(rooms,i,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size());
        dfs(rooms,0,visited);
        for(int &i:visited){
            if(i==0)return false;
        }
        return true;
    }
};