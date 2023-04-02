class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<spells.size();i++){
           int s=0,e=potions.size()-1;
            int mid=s+(e-s)/2;
            int topush=0;
            while(s<=e){
                if((long long)(spells[i])*(long long)(potions[mid])>=success){
                    topush=potions.size()-mid;
                    e=mid-1;
                }else{
                    s=mid+1;
                }
                mid=s+(e-s)/2;
            }
            ans.push_back(topush);
        }
        return ans;
    }
};