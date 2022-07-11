class Solution {
public:
    pair<int,int> getnums(string num){
        int i=num.find('+');
        int real=stoi(num.substr(0,i));
        int complex=stoi(num.substr(i+1,num.size()-i-2));
        
        return make_pair(real,complex);
        
    }
    string complexNumberMultiply(string num1, string num2) {
        pair<int,int> n1=getnums(num1);
        pair<int,int> n2=getnums(num2);
        
        int real=n1.first*n2.first-n1.second*n2.second;
        int complex=n1.first*n2.second+n2.first*n1.second;
        
        return to_string(real)+'+'+to_string(complex)+'i';
    }
};