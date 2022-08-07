class Solution {
public:
    map<int,vector<int>> m;//size set
    
    int solve(vector<int>& nums,int index,int prev,int size,vector<int>& topush,vector<vector<int>>& dp){
        if(index>nums.size()){
            // cout<<size<<endl;
            // for(int&i:topush)cout<<i<<" ";
            // cout<<endl;
         m[size]=topush;
            return 0;
            
        }
        
        if(dp[prev][size]!=-1)return dp[prev][size];
        
        int include=0,notinclude=0;
        if(prev==0 || nums[index-1]%nums[prev-1]==0){
            topush.push_back(nums[index-1]);
            include=1+solve(nums,index+1,index,size+1,topush,dp);
            topush.pop_back();
        }
        
        notinclude=solve(nums,index+1,prev,size,topush,dp);
        
        return dp[prev][size]=max(include,notinclude);
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> topush;
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        int size= solve(nums,1,0,0,topush,dp);
        cout<<size<<endl;
       
        return m[size];
    }
};