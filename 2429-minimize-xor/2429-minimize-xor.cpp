class Solution {
public:
    int countbits(int n){
        int count=0;
        while(n){
            if(n%2)count++;
            n/=2;
        }
        return count;
    }
    
//     string getbinary(int n){
//         string s="";
//          while(n){
//             if(n%2)s.push_back('1');
//              else s.push_back('0');
//             n/=2;
//         }
//         reverse(s.begin(),s.end());
//         return s;
        
//     }
    
    int getnum(string s){
        int ans=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1'){
                 ans+= pow(2*(s[i]-48),s.length()-1-i);
            }
           
            //cout<<i<<" "<<ans<<endl;
        }
        return ans;
    }
    
    int minimizeXor(int num1, int num2) {
        bitset<31> b1(num1);
        bitset<31> b2(num2);
        
        int bits=countbits(num2);
        //cout<<bits<<endl;
        string s="";
        for(int i=31;i>=0;i--){
            if(b1[i]==1 and bits){
                s.push_back('1');
                bits--;
            }else s.push_back('0');
        }
        int i=s.length()-1;
        while(bits){
            if(s[i]!='1'){
               s[i]='1'; 
                bits--;
            }
           i--;
        }
        //cout<<s<<endl;
        return getnum(s);
    }
};