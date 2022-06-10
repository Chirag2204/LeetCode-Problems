class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       if(target<letters[0] || target>=letters[letters.size()-1])return letters[0];
        map<char,int>m;
        for(int i=0;i<letters.size();i++){
            m[letters[i]]=1;
        }
        letters.clear();
        for(auto& x:m){
            letters.push_back(x.first);
        }
        int s=0,e=letters.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            if(letters[mid]==target)return letters[mid+1];
            else{
                if(letters[mid]>target){
                    e=mid;
                }else{
                    s=mid+1;
                }
            }
            mid=s+(e-s)/2;
        }
        return letters[mid];
    }
};