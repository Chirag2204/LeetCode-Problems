class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> a;
        vector<pair<int,int>> b;
        
        int n=img1.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j])a.push_back({i,j});
                if(img2[i][j])b.push_back({i,j});
            }
        }
        int ans=0;
        map<pair<int,int>,int> m;
        for(auto& x1:a){
            for(auto& x2:b){
                m[{x1.first-x2.first,x1.second-x2.second}]++;
                ans=max(ans,m[{x1.first-x2.first,x1.second-x2.second}]);
            }
        }
        return ans;
    }
};