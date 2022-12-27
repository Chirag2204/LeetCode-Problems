class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        vector<int> data;
        int n=rocks.size();
        for(int i=0;i<n;i++){
           data.push_back(capacity[i]-rocks[i]);
        }
  
        sort(data.begin(),data.end());

         
        int count=0;
        int i=0;
        while(true){
           if(i<n && data[i]<=a ){
                // cout<<"hello"<<" "<<i<<endl;
               count++;
               a-=data[i];
               i++;
           }else break;
        }
       
        return count;
    }
    
    
};