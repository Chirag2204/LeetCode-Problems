class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
//         sort(changed.begin(),changed.end());
//         map<int,int> m;
//         map<int,int> doubled;
//         for(int i=0;i<changed.size();i++){
//             if(changed[i]%2==0 && m[changed[i]/2]!=doubled[changed[i]]){
//                 doubled[changed[i]]++;
//             }else{
//                 m[changed[i]]++;
//             }
//         }
//         int count1=0,count2=0;
//         vector<int> ans;
//         for(auto &x:m){
//             count1+=x.second;
//         }
//         for(auto &x:doubled){
//             count2+=x.second;
//         }
//         if(count1==count2){
//             for(auto &x: m){
//                 int i=1;
//                 while(i<=x.second){
//                      ans.push_back(x.first);
//                     i++;
//                 }
               
//             }
//         }
//         return ans;
        
        vector<int> empty;
        vector<int> ans;
        
        map<int,int> m;
        for(int& x:changed)m[x]++;
        
        for(auto& x:m){
            if(x.first==0){
                if(x.second%2==0){
                    for(int i=0;i<x.second/2;i++){
                        ans.push_back(0); 
                    }
                   
                    x.second=0;
                }else return empty;
            }
            else if(x.second>0){
                // cout<<x.first<<endl;
                int temp=x.second;
                 m[x.first]=0;
                if(m.count(x.first*2) and m[x.first*2]>=temp){
                     m[x.first*2]-=temp;
                   
                    for(int i=0;i<temp;i++){
                        ans.push_back(x.first); 
                    }
                   
                }else return empty;
            }
        }
        return ans;
    }
};