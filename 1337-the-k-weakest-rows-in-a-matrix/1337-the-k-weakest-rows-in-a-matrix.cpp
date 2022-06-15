class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       set< pair<int,int> > topush;
        vector<int> ans;
        int j=0;
        for(int i=0;i<mat.size();i++){
            for(j=0;j<mat[i].size();j++){
                if(mat[i][j]!=1 ){
                    
                    topush.insert({j,i});
                    break;
                }
                if(j==mat[i].size()-1)
                    topush.insert({j+1,i});
            }
            // cout<<i<<" "<<j<<endl;
        }
        
        int count=0;
        for(auto i:topush){
            // cout<<i.first<<" "<<i.second<<endl;
            ans.push_back(i.second);
            count++;
            if(count>=k)
                break;
        }
        return ans;
    }
};