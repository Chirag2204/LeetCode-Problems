class Solution {
public:
    string multiply(string num1, string num2) {
        string ans(num1.size()+num2.size(),'0');
        for(int i=num1.size()-1;i>=0;i--){
            int carry=0;
            for(int j=num2.size()-1;j>=0;j--){
                int temp=(ans[i+j+1]-'0')+carry + (num1[i]-'0')*(num2[j]-'0');
                ans[i+j+1]=temp%10 + '0';
                carry=temp/10;
            }
            ans[i]+=carry;
        }
        // cout<<ans<<endl;
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='0'){
                ans.erase(ans.begin()+i);
                i--;
            }
             else break;
        }
        if(ans.size()==0)return "0";
        return ans;
    }
};