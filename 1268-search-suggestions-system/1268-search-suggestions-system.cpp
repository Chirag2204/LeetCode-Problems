class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
      
        string prefix;
        int i=0;
        while(i<searchWord.size()){
            prefix.push_back(searchWord[i]);
            int count=0;
            vector<string>temp;
            for(int j=0;j<products.size();j++){
                if(products[j].substr(0,i+1)==prefix){
                    // cout<<prefix<<" "<<products[j]<<" "<<count<<endl;
                    temp.push_back(products[j]);
                    count++;
                }
                if(count==3)break;
            }
            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};