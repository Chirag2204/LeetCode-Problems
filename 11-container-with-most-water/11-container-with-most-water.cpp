class Solution {
public:
    int maxArea(vector<int>& heights) {
        int h=0,water=0;
        int i=0,j=heights.size()-1;
        while(i<j){
           h=min(heights[i],heights[j]);
            water=max(water,h*(j-i));
            while(heights[i]<=h && i<j)i++;
            while(heights[j]<=h && i<j)j--;
        }
        return water;
    }
    
    
};