class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int> trustto;
        unordered_map<int,int> trustedby;
        //trustto=0 and trustby=n-1 for town judge
        for(int i=1;i<=n ; i++){
            trustto[i]=0;
            trustedby[i]=0;
        }
        for(int i=0 ; i<trust.size() ; i++){
            //cout<<trust[i][0]<<" "<<trust[i][1]<<endl;
            trustto[trust[i][0]]++;
            trustedby[trust[i][1]]++;
        }
        for(int i=1;i<=n ; i++){
            ///cout<<trustto[i]<<" "<<trustedby[i]<<endl;
            if(trustto[i]==0){
                if(trustedby[i]==n-1){
                    return i;
                }
            }
        }
        return -1;
    }
};