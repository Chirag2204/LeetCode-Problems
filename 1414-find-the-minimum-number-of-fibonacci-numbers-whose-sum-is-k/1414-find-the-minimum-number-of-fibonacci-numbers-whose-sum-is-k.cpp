class Solution {
public:
    int findMinFibonacciNumbers(int k) {
       vector<int> nums;
        nums.push_back(1);
        nums.push_back(1);
        int n=2;
        while(n<=k){
            nums.push_back(n);
            n=nums[nums.size()-1]+nums[nums.size()-2];
        }
        int count=0;
        for(int i=nums.size()-1;i>=0;i--){
            // cout<<nums[i]<<" "<<k<<"->";
            if(k>=nums[i]){
                count+=k/nums[i];
                k=k-(k/nums[i])*nums[i];
                
            }
        }
        
        cout<<endl;
        return count;
    }
};