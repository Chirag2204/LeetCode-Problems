class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> nums(n*n+1);
        bool rev=false;
        int count=1;
        reverse(board.begin(),board.end());
        for(int i=0;i<n;i++){
            if(rev){
                for(int j=n-1;j>=0;j--){
                    nums[count++]=board[i][j];
                }
            }
            else{
                for(int j=0;j<n;j++){
                    nums[count++]=board[i][j];
                }
            }
            rev=!rev;
        }
        
        int ans=0;
       queue<pair<int,int>> q;
        
        q.push({1,0});        
        while(!q.empty()){
            
            int x=q.front().first;
            ans=  q.front().second;
           cout<<x<<","<<ans<<" ";
            q.pop();
            
            if(x==n*n)return ans;
            
            for(int i=x+1;i<=min(n*n,x+6);i++){
                if(nums[i]!=0){
                    if(nums[i]==-1)q.push({i,ans+1});
                    else {
                       
                        
                        if(nums[i]!=0)
                        q.push({nums[i],ans+1});
                        nums[i]=0;
                    }
                    nums[i]=0;
                }
            
             }
            
        }
       // cout<<endl;
        return -1;
    }
};