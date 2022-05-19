class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int count=0;
        vector<int> ans(3);
        ans[0]=a;
        ans[1]=b;
        ans[2]=c;
         sort(ans.begin(),ans.end());
        while(ans[0]!=0 || ans[1]!=0 ){
           
            ans[1]--;
            ans[2]--;
            count++;
             sort(ans.begin(),ans.end());
        }
        return count;
    }
};