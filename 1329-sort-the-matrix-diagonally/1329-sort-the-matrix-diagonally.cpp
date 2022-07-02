class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,vector<int>> m;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                m[i-j].push_back(mat[i][j]);
            }
        }
        for(auto& x:m){
            sort(x.second.begin(),x.second.end());
            reverse(x.second.begin(),x.second.end());
        }
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mat[i][j]=m[i-j][m[i-j].size()-1];
                m[i-j].pop_back();
            }
        }
        return mat;
    }
};