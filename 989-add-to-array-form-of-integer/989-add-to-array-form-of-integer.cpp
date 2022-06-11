class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       int carry=0;
        int lnum=num[num.size()-1]+k;
        num[num.size()-1]=lnum%10;
        carry=lnum/10;
        int i=num.size()-2;
        while(carry!=0){
            if(i<0){
                num.insert(num.begin(),carry);
                carry=num[0]/10;
                num[0]=num[0]%10;
            }else{
            num[i]=num[i]+carry;
            carry=num[i]/10;
            num[i]=num[i]%10;
            i--;
            }
        }
        return num;
    }
};