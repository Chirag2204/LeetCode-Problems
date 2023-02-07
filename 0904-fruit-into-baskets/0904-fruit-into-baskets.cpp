class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0;
        int i=0,j=0;
        map<int,int> m;
        int val1=-1,val2=-1;
        while(j<fruits.size()){
            //cout<<j<<" "<<ans<<endl;
            if(val1!=-1 and val2!=-1 and val1!= fruits[j] and val2!=fruits[j] ){
                ans=max(ans,j-i);
                
                i=min(m[val1],m[val2])+1;
                if(m[val1]<m[val2])
                val1=-1;
                else val2=-1;

            }
            if(val1==-1 and val2!= fruits[j]){
                val1=fruits[j];
            }else if(val1!=fruits[j]){
                val2=fruits[j];
            }
            m[fruits[j]]=j;
            j++;
        }
        ans=max(j-i,ans);
        return ans;
    }
};