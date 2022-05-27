class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> s;
        for(int &i:nums){
            s.push_back(to_string(i));
        }
        sort(s.begin(),s.end(),sortbytens);
        string ans="";
        for(string& i:s){
            
            ans.append(i);
        }
        if(ans[0]=='0'){
            while(ans.size()!=1 && ans[0]=='0'){
                ans.erase(ans.begin());
            }
        }
        return ans;
    }
    static bool sortbytens(string a,string b){
       return a+b>b+a;
    }
};