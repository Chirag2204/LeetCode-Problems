class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
       int m=mat.size(),n=mat[0].size();
        int i=0,j=0;
        bool up=true;
        while( i<m && j<n){
            // cout<<i<<" "<<j<<" "<<up<<endl;
            ans.push_back(mat[i][j]);
            if(up){
               if(i>0 && j<n-1){
                   i--;
                   j++;
               } 
                else if(i==0 && j==n-1){
                    i++;
                    up=false;
                    
                }
                else if(i==0){
                    j++;
                    up=false;
                }
                else if(j==n-1){
                    i++;
                    up=false;
                }
            }else{
                if(i<m-1 && j>0){
                   i++;
                   j--;
               } 
                else if(i==m-1 && j==0){
                    j++;
                    up=true;
                    
                }
                else if(i==m-1){
                  j++;
                    up=true;
                }
                else if(j==0){
                    i++;
                    up=true;
                }
            }
        }
        // ans.push_back(mat[i][j]);
        return ans;
    }
};