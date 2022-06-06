class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
       map<int,int> m;
        for(int& i:arr){
            m[i]++;
        }
        vector<pair<int,int>> v;
        for(auto& x:m){
            v.push_back(make_pair(x.second,x.first));
        }
        sort(v.begin(),v.end());
        int count=0;
        for(int i=0;i<v.size();i++){
            if(k-v[i].first>=0){
                count++;
                k-=v[i].first;
            }else{
                break;
            }
        }
        return v.size()-count;
    }
};