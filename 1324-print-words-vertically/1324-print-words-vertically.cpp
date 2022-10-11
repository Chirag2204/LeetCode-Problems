class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> strs;
        string str="";
        int mxlen=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                int n=str.length();
                mxlen=max(mxlen,n);
                strs.push_back(str);
                str="";
            }else str.push_back(s[i]);
        }
        int n=str.length();
        mxlen=max(mxlen,n);
        strs.push_back(str);
        vector<string> ans;
        for(int i=0;i<mxlen;i++){
            str="";
            for(string& x:strs){
                if(i>=x.length() )str.push_back(' ');
                else str.push_back(x[i]);
            }
            int lastchar=0;
            for(int j=0;j<str.length();j++){
                if(str[j]!=' ')lastchar=j;
            }
            //cout<<str<<":"<<lastchar<<endl;
            ans.push_back(str.substr(0,lastchar+1));
            
        }
        
        return ans;
    }
};