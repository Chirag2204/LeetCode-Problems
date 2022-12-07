class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<string> strs(numRows);
        
        int i=0,j=0;
        bool inc=true;
        while(j<s.length()){
            //cout<<i<<" "<<j<<endl;
            if(inc)
            strs[i++].push_back(s[j++]);
            else
            strs[i--].push_back(s[j++]);
            
            // if(inc)i++;
            // else i--;
            
            if(i==0){
                inc=true;
                
            }
            if(i==numRows-1){
                inc=false;
                
            }
        }
        
        string ans="";
        for(string& str:strs){
            //cout<<str<<endl;
            ans+=str;
        }
        
        return ans;
        
    }
};