class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;
        int start=0;
        int count=0;
        while(start<s.length()){
            int x=startPos[0],y=startPos[1];
            for(int i=start;i<s.length();i++){
                if(s[i]=='U'){
                    x--;
                }
                if(s[i]=='R'){
                    y++;
                }
                if(s[i]=='L'){
                    y--;
                }
                if(s[i]=='D'){
                    x++;
                }
                if(x<0 || x>=n || y<0|| y>=n)
                    break;
                count++;
            }
            ans.push_back(count);
            count=0;
            start++;
        }
        return ans;
    }
};