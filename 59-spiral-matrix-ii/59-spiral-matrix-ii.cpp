class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int rbegin=0,rend=n-1;
        int colbegin=0,colend=n-1;
        int count=1;
        while(rbegin<=rend && colbegin<=colend){
            for(int i=colbegin;i<=colend;i++){
                ans[rbegin][i]=count;
                count++;
            }
            rbegin++;
            for(int i=rbegin;i<=rend;i++){
                ans[i][colend]=count;
                count++;
            }
            colend--;
            if(rbegin<=rend){
                for(int i=colend;i>=colbegin;i--){
                    ans[rend][i]=count;
                    count++;
                }
            }
            rend--;
            if(colbegin<=colend){
                for(int i=rend;i>=rbegin;i--){
                    ans[i][colbegin]=count;
                    count++;
                }
            }
            colbegin++;
        }
        return ans;
    }
};