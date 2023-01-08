class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size()==1)return 1;
        double m=1e9,m1=1e9;
        double x=0,x1=0,y=0,y1=0;
        sort(points.begin(),points.end());
        int ans=2,count=2;
        for(int i=0;i<points.size();i++){
            for(int j=points.size()-1;j>i;j--){
                x=points[j][0]-points[i][0];
                y=points[j][1]-points[i][1];
                m=1e9;
                if(x!=0)
                  m=y/x;
                m1=1e9;
                count=2;
                //cout<<points[i][0]<<" "<<points[j][0]<<endl;
                for(int k=j-1;k>i;k--){
                   x1=points[k][0]-points[i][0];
                   y1=points[k][1]-points[i][1];
                  m1=1e9;
                  if(x1 !=0)
                    m1=y1/x1; 
                  //cout<<points[k][0]<<" "<<m1<<" "<<m<<endl;
                    if(m1==m)count++;
                    ans=max(ans,count);
                }
                
            }
        }
        return ans;
    }
};