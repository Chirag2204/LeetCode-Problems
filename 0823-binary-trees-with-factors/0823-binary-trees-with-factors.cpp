class Solution {
public:
    unordered_set<int> s;
    unordered_map<int,long long> m;
    long long solve(vector<int>& nums,int num1){
       if(m.count(num1))return m[num1];
        
        long long count=1;
        for(int &i:nums){
            if(num1>=i && num1%i==0 && s.count(num1/i)){
                count+=solve(nums,i)*solve(nums,num1/i);
            }
        }
        return m[num1]=count;
        
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        s.insert(arr.begin(),arr.end());
        long long ans=0;
        for(int& i:arr){
            ans+=solve(arr,i);
            ans%=1000000007;
        }
        return (int)ans%1000000007;
    }
};