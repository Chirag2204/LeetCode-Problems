class Solution {
public:
    
     void solve1(string nums,int index,set<string>& ans){
        if(index>=nums.size()){
            ans.insert(nums);
            return;
        }
        
       for(int i=index;i<nums.size();i++){
          swap(nums[i],nums[index]);
           
           solve1(nums,index+1,ans);
           
           //backtracking
           swap(nums[index],nums[i]);
           //we have to perform operations on original number sequence only
       }
    }
    
    void solve(string tiles,int index,string output,set<string>& ans1){
        if(index>=tiles.size()){
            ans1.insert(output);
            return ;
        }
        //exclude
        solve(tiles,index+1,output,ans1);
        
        //include
        output.push_back(tiles[index]);
         solve(tiles,index+1,output,ans1);
    }
    int numTilePossibilities(string tiles) {
        set<string> ans1;
        set<string> ans;
        solve(tiles,0,"",ans1);
        for(string s:ans1){
            if(s!=""){
               solve1(s,0,ans);
            // cout<<s<<" "<<ans.size()<<endl;
            // count+=ans.size();
            }
           
        }
        return ans.size();
    }
};