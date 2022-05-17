class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
       int res=0,count=0;
        int ans=0;
        int i=0,j=0;
        while(j<nums.length()){
            if(nums[j]=='F'){
                count++;
            }
            while(count>k){
                if(nums[i]=='F')count--;
                i++;
            }
            
            res=max(res,j-i+1);
            j++;
        }
        // cout<<res<<endl;
        count=0;
        i=0;
        j=0;
        while(j<nums.length()){
            if(nums[j]=='T'){
                count++;
            }
            while(count>k){
                if(nums[i]=='T')count--;
                i++;
            }
            // cout<<i<<" "<<j<<" "<<count<<endl;
            res=max(res,j-i+1);
            j++;
        }
        return res;
    }
};