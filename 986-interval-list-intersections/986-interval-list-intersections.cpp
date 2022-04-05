class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        
      
        for(int i=0;i<firstList.size();i++){
            for(int j=0;j<secondList.size();j++){
                vector<int> topush;
                if(firstList[i][0]>secondList[j][1]){
                    continue;
                }
                if(firstList[i][1]<secondList[j][0]){
                    break;
                }
                topush.push_back(max(firstList[i][0],secondList[j][0]));
                topush.push_back(min(firstList[i][1],secondList[j][1]));
          ans.push_back(topush);
            }
            
        }
        return ans;
    }
};