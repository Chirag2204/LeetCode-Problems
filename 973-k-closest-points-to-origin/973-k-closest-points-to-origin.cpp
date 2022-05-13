class Solution {
public:
    static long long getDist(vector<int> p1){
        return pow(p1[0],2)+pow(p1[1],2);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans(k,vector<int>(2));
       
        sort(points.begin(),points.end(),compareDist);
        for(int i=0;i<k;i++){
            // cout<<getDist(points[i])<<endl;
            ans[i][1]=points[i][1];
            ans[i][0]=points[i][0];
        }
        return ans;
    }
    
    static bool compareDist(vector<int> v1,vector<int> v2){
       
        return getDist(v1)<getDist(v2);
    }
};