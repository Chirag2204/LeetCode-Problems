class Solution {
public:
    int solve(int index,map<char,int>& m,vector<string> &arr){
        if(index>=arr.size())return 0;
        
        int include=0,notinclude=0;
        bool yes=true;
        int len=0;
        for(char& c:arr[index]){
            if(m.count(c) and m[c]>0)
                yes=false;
            m[c]++;
            len++;
        }
        
        if(yes){
            
            include=len+solve(index+1,m,arr);
        }
        //cout<<index<<endl;
        for(char& c:arr[index]){
            m[c]--;
        }
        notinclude=solve(index+1,m,arr);
        //cout<<"____________"<<endl;
        return max(include,notinclude);
        
        
    }
        int maxLength(vector<string>& arr) {
        map<char,int> m;
        return solve(0,m,arr);
    }
};