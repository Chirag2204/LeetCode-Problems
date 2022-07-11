class Solution {
public:
    int getlvl(int n){
        int count=0;
        while(n){
            n/=2;
            count++;
        }
        return count;
    }
    vector<int> pathInZigZagTree(int label) {
        int level=getlvl(label);
        vector<int> ans(level);
        while(level>0){
             ans[level-1]=label;
            label/=2;
            level--;
            label=pow(2,level)+pow(2,level-1)-1-label;
        }
       return ans;
        
    }
};