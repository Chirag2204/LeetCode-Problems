class Solution {
public:
    long long ans=0;
    long long solve(int root,int prev,unordered_map<int,vector<int>>& m,int depth,int& seats){
        long long count=1;
        for(auto& x:m[root]){
            if(x!=prev)
            count+= solve(x,root,m,depth+1,seats);
        }
         if(depth==0){
            return ans;
        }
        ans+= (count/seats)*depth + (count%seats?1:0) ;
        
        return count%seats;
    }
    
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
       unordered_map<int,vector<int>> m;
        for(auto& x:roads){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }
        
        solve(0,-1,m,0,seats);
        
        return ans;
    }
};