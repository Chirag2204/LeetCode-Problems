class Solution {
public:
    static bool mysort(vector<int>& a,vector<int>& b){
       if(a[0]==b[0]){
           return a[1]>b[1];
       }    
        return a[0]<b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        sort(props.begin(),props.end(),mysort);
        int mx=0;
        int n=props.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(props[i][1]<mx)
                ans++;
            
            mx=max(mx,props[i][1]);
        }
        return ans;
    }
};