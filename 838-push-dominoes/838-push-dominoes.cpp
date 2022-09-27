class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> left(n,1e9),right(n,1e9);
        int count=-1;
        bool found=false;
        for(int i=0;i<n;i++){
           if(dominoes[i]=='R'){
               count=0;
               found=true;
           }
            else if(dominoes[i]=='L'){
               count=0;
                found=false;
            }else{
                if(found)count++;
            } 
            
            if(found)right[i]=count;
        }
        found=false,count=-1;
        for(int i=n-1;i>=0;i--){
           if(dominoes[i]=='L'){
               count=0;
               found=true;
           }
            else if(dominoes[i]=='R'){
               count=0;
                found=false;
            }else {
                if(found)count++;
            }
            
            if(found)left[i]=count;
        }
        
        dominoes.resize(n);
        for(int i=0;i<n;i++){
            //cout<<left[i]<<" "<<right[i]<<endl;
            if(left[i]==right[i])dominoes[i]='.';
            else{
                if(left[i]<right[i])dominoes[i]='L';
                else dominoes[i]='R';
            }
        }
        return dominoes;
    }
};