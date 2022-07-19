class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        vector<int> prev;
        int count=0;
        while(count<=rowIndex){
            ans.resize(count+1);
            ans[0]=1;
            ans[count]=1;
            for(int i=1;i<count;i++){
                ans[i]=prev[i-1]+prev[i];
            }
           prev=ans;
            count++;
        }
        return ans;
    }
};