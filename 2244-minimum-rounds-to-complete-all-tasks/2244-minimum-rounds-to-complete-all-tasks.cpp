class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> m;
        
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        bool ans=true;
        int count=0;
        for(auto i:m){
           if(i.second==1){
               ans=false;
               break;
           }
            if(i.second%3==0){
                count+= i.second/3;
            }
            else if(i.second%3==1){
                count+= (i.second-4)/3 + 2;
            }
            else if(i.second%3==2){
                count+=i.second/3 + 1;
            }
               
        }
        if(ans)
            return count;
        else
            return -1;
    }
};