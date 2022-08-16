class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> m;
        int ans=0;
        for(int& i: answers){
            if(i==0)ans++;
            else
            m[i]++;
        }
        
        for(auto& x:m){
            ans+=x.second;
            if(x.second%(x.first+1))
            ans+=x.first+1-x.second%(x.first+1);
        }
        
        return ans;
    }
};