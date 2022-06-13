class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int i=4;
        while(i--){
           reverse(mat.begin(),mat.end());
        for(int i=0;i<mat.size();i++){
            for(int j=i+1;j<mat[i].size();j++){
                swap(mat[i][j],mat[j][i]);
                
            }
            // cout<<endl;
        }
//          for(int i=0;i<mat.size();i++){
//             for(int j=0;j<mat[i].size();j++){
//               cout<<mat[i][j]<<" ";
                
//             }
//             cout<<endl;
            if( mat==target)return true; 
          }
        
        return false; 
        }
       
   
};