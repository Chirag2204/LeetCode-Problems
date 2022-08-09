class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         queue<pair<int,int>> q;
        q.push({sr,sc});
         cout<<sr<<" "<<sc<<" "<<newColor<<endl;
        
        int color=image[sr][sc];
        if(color==newColor)return image;
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int x=p.first,y=p.second;
          
                image[x][y]=newColor;
                if(x>0 && image[x-1][y]==color){
                    q.push({x-1,y});
                }
                if(x<image.size()-1 && image[x+1][y]==color){
                    q.push({x+1,y});
                }
                if(y>0 && image[x][y-1]==color){
                    q.push({x,y-1});
                }
                if(y<image[0].size()-1 && image[x][y+1]==color){
                    q.push({x,y+1});
                }
            
        }
        return image;
    }
};