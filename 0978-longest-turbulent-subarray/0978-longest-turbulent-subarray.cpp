class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int count=0;
        int ans=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]<arr[i+1]){
              if(count<=0)count--;
                else count=-1;
            }
            else if(arr[i]>arr[i+1]){
               if(count>=0)count++;
                else count=1;
            }else count=0;
            
            ans=max(ans,abs(count));
            
            count=-count;
        }
        return ans+1;
        
    }
};