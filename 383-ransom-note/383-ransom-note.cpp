class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> mymap;
        for(char& c:m)mymap[c]++;
        for(char& c:r){
            if(mymap.count(c)){
                if(mymap[c]==0)return false;
                mymap[c]--;
            }else{
                return false;
            }
        }
        return true;
    }
};