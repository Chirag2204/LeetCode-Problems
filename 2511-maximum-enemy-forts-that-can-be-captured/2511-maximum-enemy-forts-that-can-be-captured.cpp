class Solution {
public:
    int captureForts(vector<int>& forts) {
        int count=0,ans=0;
        bool found1=false;
        for(int i=0;i<forts.size();i++){
             if(forts[i]==1){
                found1=true;
                count=0;
            }
            if(forts[i]==0 and found1)count++;
            if(forts[i]==-1){
                ans=max(ans,count);
                count=0;
                found1=false;
            }
        }
        count=0;
        found1=false;
        reverse(forts.begin(),forts.end());
        for(int i=0;i<forts.size();i++){
            if(forts[i]==1){
                found1=true;
                count=0;
            }
            if(forts[i]==0 and found1)count++;
            if(forts[i]==-1){
                ans=max(ans,count);
                count=0;
                found1=false;
            }
        }
        return ans;
    }
};