class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.length()<3)return false;
        int counta=0,countb=0;
        for(int i=1;i<colors.length()-1;i++){
            if(colors[i]=='A' and colors[i]==colors[i-1] and colors[i]==colors[i+1])counta++;
            if(colors[i]=='B' and colors[i]==colors[i-1] and colors[i]==colors[i+1])countb++;
        }
        return counta>countb;
    }
};