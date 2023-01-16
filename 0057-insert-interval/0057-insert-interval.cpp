class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newint) {
     

        vector<vector<int>> ans;
        bool change=false;
        bool insert=true;
        for(auto& x:intervals){
            if(newint[0]<=x[1] and newint[1]>=x[0]){
                newint[0]=min(newint[0],x[0]);
                newint[1]=max(newint[1],x[1]);
                change=true;
            }else{
                if(change or (insert and x[0]>newint[1])){
                  ans.push_back(newint);
                  insert=false;
                  change=false;
                }
                ans.push_back(x);
                
            }
        }
        if(insert)
        ans.push_back(newint);
        return ans;
    }
};