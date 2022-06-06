class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),mysort);
        int start=pairs[0][0];
        int end=pairs[0][1];
        int count=1,ans=1;
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>end){
                count++;
                end=pairs[i][1];
            }
            
            ans=max(ans,count);
        }
        return ans;
    }
    static bool mysort(vector<int> a,vector<int>b){
        return a[1]<b[1];
    }
};