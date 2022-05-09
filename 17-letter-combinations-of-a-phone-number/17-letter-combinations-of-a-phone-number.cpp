class Solution {
public:
    void solve(unordered_map<int,string> umap,string digits,string current,int index,vector<string>& ans){
        if(index>=digits.length()){
                ans.push_back(current);  
            return;
        }
        int n=int(digits[index]-48);
         string value=umap[n];   
        
        for(int i=0;i<value.length();i++){
            current.push_back(value[i]);
            solve(umap,digits,current,index+1,ans);
            // cout<<current<<" ";
             current.pop_back();
            // cout<<current<<endl;
        }
            
    }
   
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        unordered_map<int,string> umap;
        umap[2]="abc";
        umap[3]="def";
         umap[4]="ghi";
         umap[5]="jkl";
         umap[6]="mno";
         umap[7]="pqrs";
         umap[8]="tuv";
         umap[9]="wxyz";
        int index=0;
        string current;
        solve(umap,digits,current,index,ans);
        return ans;
    }
};