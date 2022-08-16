class Solution {
public:
   void solve(vector<int>& cookies,int index,vector<int>& child,int& k,int& ans){
       if(index==cookies.size()){
           int mx=0;
           for(int& i:child)mx=max(mx,i);
           ans=min(ans,mx);
           return ;
           
       }

        for(int i=0;i<k;i++){
            child[i]+=cookies[index];
            solve(cookies,index+1,child,k,ans);
            child[i]-=cookies[index];
            if(child[i]==0) break;
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
       int ans=1000000;
        vector<int> child(k,0);
         solve(cookies,0,child,k,ans);
             return ans;
    }
};