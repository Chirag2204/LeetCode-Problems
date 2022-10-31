class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int start=-matrix[0].size()+1;
        int n=matrix.size();
        
        // cout<<start<<endl;
        // cout<<matrix.size()<<endl;
        while(start<n){
           // cout<<"here";
            int x=start,y=0;
            
            while(x<n and y<matrix[0].size()){
                 //cout<<x<<" "<<y<<endl;
                if(x>0 and y>0){
                   
                    if(matrix[x][y]!=matrix[x-1][y-1])return false;
                }
                x++;
                y++;
            }
            start++;
        }
        return true;
    }
};