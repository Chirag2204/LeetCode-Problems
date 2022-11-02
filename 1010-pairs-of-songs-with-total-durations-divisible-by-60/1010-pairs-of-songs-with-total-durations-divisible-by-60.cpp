class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> umap;
        int ans=0;
      
        for(int i=0;i<time.size();i++){
            int mod=time[i]%60;
            if(mod==0)ans+=umap[0];
            if(umap[60-mod]>0){
                ans+=umap[60-mod];
             
            }
            umap[mod]++;
        }
      
        return ans;
        
    }
};