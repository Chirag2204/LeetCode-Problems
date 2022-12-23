class Solution {
public:
   long long ans=0;
    map<long long,int> count;
    int n=0;
    long long maxl(long long& a,long long& b){
        if(a<b)return b;
        return a;
    }
    int solve(map<int,vector<int>>& m,int val){
        int left=0,right=0;
        if(m[val].size()>0)
        left= solve(m,m[val][0]);
        if(m[val].size()==2){
            right= solve(m,m[val][1]);
        }
        //cout<<val<<" "<<left<<" "<<right<<endl;
        long long mult=n-1-left-right;
        if(left)mult*=left;
        if(right)mult*=right;
        count[mult]++;
        ans=maxl(ans,mult);
        
        return left+right+1;
        
    }
    
    int countHighestScoreNodes(vector<int>& parents) {
        n=parents.size();
        map<int,vector<int>> m;
        for(int i=1;i<parents.size();i++){
           
                m[parents[i]].push_back(i);
            
        }
        int left=0,right=0;
        if(m[0].size()>0)
        left=solve(m,m[0][0]);
        if(m[0].size()>1)
        right=solve(m,m[0][1]);
        //cout<<0<<" "<<left<<" "<<right<<endl;
        long long mult=1;
        if(left)mult*=left;
        if(right)mult*=right;
        count[mult]++;
        ans=maxl(ans,mult);
        //cout<<ans<<endl;
        return  count[ans];
    }
};