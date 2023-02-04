class Solution {
public:
    bool checkInclusion(string p, string s) {
        vector<int> sv(26,0),pv(26,0);
        if(s.size()<p.size())
            return false;
        for(int i=0;i<p.size();i++){
            pv[int(p[i])-97]++;
            sv[int(s[i])-97]++;
            
        }
        if(pv==sv)
            return true;
        
        for(int i=p.size();i<s.size();i++){
            sv[int(s[i])-97]++;
            sv[int(s[i-p.size()])-97]--;
            if(sv==pv)
                return true;
            
        }
        return false; 
    }
};