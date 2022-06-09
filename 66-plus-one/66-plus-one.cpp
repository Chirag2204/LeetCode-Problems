class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size()-1]++;
       for(int i=digits.size()-1 ; i>0 ; i--){
           if(digits[i]>9){
               digits[i]=10-digits[i];
               digits[i-1]++;
           }
       }
        
        if(digits[0]>9){
            digits[0]=10-digits[0];
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};