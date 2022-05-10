class Solution {
public:
    bool isPossible(int mid,vector<int>& weights,int days){
        int count=0,dayscount=1;
        for(int i=0;i<weights.size();i++){
            if(count+weights[i]<=mid){
                count+=weights[i];
            }else{
                // cout<<"->"<<dayscount<<" "<<count<<" ";
                dayscount++;
                if(weights[i]>mid || dayscount>days){
                    return false;
                }
                count=weights[i];
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {

        int e=0;
        for(int i: weights){
            e+=i;
        }
        int s=1;
        int mid=s+(e-s)/2;
        int ans=0;
        while(s<=e){
            // cout<<endl;
            // cout<<mid<<endl;
            if(isPossible(mid,weights,days)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};