class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> frontavg(nums.size());
        vector<long long> backavg(nums.size());
        long long count=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            count++;
            frontavg[i]=sum/count;
        }
        count=0;
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            count++;
            backavg[i]=sum/count;
        }
        int minindex=0;
        long long min=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            
            if(abs(frontavg[i]-backavg[i+1])<min){
                minindex=i;
                min=abs(frontavg[i]-backavg[i+1]);
            }
        }
        if(frontavg[nums.size()-1]<min){
            minindex=nums.size()-1;
        }
        return minindex;
    }
};