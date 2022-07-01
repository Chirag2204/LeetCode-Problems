class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),mysort);
        int ans=0;
        int i=0;
        while(truckSize>0 && i<boxTypes.size()){
            int include=min(truckSize,boxTypes[i][0]);
            ans+=include*boxTypes[i][1];
            i++;
            truckSize-=include;
        }
        return ans;
    }
    static bool mysort(vector<int>& a,vector<int>&b){
        return a[1]>b[1];
    }
};