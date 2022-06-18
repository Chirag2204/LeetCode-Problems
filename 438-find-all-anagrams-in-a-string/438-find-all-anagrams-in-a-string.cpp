class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices;
        vector<int> sv(26,0),pv(26,0);
        if(s.size()<p.size())
            return indices;
        for(int i=0;i<p.size();i++){
            pv[int(p[i])-97]++;
            sv[int(s[i])-97]++;
            
        }
        if(pv==sv)
            indices.push_back(0);
        
        for(int i=p.size();i<s.size();i++){
            sv[int(s[i])-97]++;
            sv[int(s[i-p.size()])-97]--;
            if(sv==pv)
                indices.push_back(i-p.size()+1);
            
        }
        return indices;
    }
    
//     bool isAnagram(string s, string t) {
//         vector<int> count (26);
//         if(s.length()!=t.length())
//             return false;
//         int n=s.length();
//         for(int i=0;i<s.length();i++){
//             count[int(s[i])-97]++;
//             count[int(t[i]-97)]--;
//         }
//         for(int i=0;i<26;i++){
//             if(count[i])
//                 return false;
//         }
//         return true;
//     }
};