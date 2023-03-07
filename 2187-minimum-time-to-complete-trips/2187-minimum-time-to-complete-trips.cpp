class Solution {
public:
    bool isPossible(vector<int>& time,long long mid,int t){
        long long ans=0;
        for(int i=0;i<time.size();i++){
            ans+=(long long)(mid/time[i]);
        }
        return ans>=t;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s=1,e=(long long)time[time.size()-1]*totalTrips;
        long long mid=s+(e-s)/2;
        long long ans=e;
        while(s<=e){
            if(isPossible(time,mid,totalTrips)){
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