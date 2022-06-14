class Solution {
public:
   
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int rbegin=0,colbegin=0;
        int rend=matrix.size()-1,colend=matrix[0].size()-1;
        vector<int> ans;
        while(rbegin<=rend && colbegin<=colend){
            
                //traverse right
                for(int i=colbegin;i<=colend;i++){
                   ans.push_back(matrix[rbegin][i]); 
                }
            
            rbegin++;
           
                //traverse down
                for(int i=rbegin;i<=rend;i++){
                    ans.push_back(matrix[i][colend]);
                }
            
            colend--;
            if(rbegin<=rend){
                //traverse left
                for(int i=colend;i>=colbegin;i--){
                   ans.push_back(matrix[rend][i]); 
                }
            }
            rend--;
            if(colbegin<=colend){
                //traverse up
                for(int i=rend;i>=rbegin;i--){
                    ans.push_back(matrix[i][colbegin]);
                }
            }
            colbegin++;
        }
        return ans;
    }
};