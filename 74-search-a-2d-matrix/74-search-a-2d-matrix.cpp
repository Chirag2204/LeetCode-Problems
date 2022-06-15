class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size(),cols=matrix[0].size();
        int row=0,col=cols-1;
        while(row<rows && col>-1){
            int mid=matrix[row][col];
            if(mid==target)return true;
            if(mid>target)col--;
            if(mid<target)row++;
        }
        
        return false;
    }
};