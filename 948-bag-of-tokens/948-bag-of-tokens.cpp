class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0)return 0;
        sort(tokens.begin(),tokens.end());
        int score=0;
        if(tokens[0]>power)return 0;
        
        power-=tokens[0];
        score=1;
        int i=1,j=tokens.size()-1;
        int ans=score;
        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                i++;
                score++;
            }else{
                power+=tokens[j];
                j--;
                score--;
            }
            ans=max(score,ans);
        }
        return max(score,ans);
    }
};