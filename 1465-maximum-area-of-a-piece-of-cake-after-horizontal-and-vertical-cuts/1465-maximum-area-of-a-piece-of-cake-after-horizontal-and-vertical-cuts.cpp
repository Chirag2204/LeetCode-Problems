class Solution {
public:
    
    int maxArea(int h, int v, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int mxh=max(hc[0],h-hc[hc.size()-1]),mxv=max(vc[0],v-vc[vc.size()-1]);
        for(int i=1;i<hc.size();i++){
            mxh=max(mxh,hc[i]-hc[i-1]);
        }
       
        for(int i=1;i<vc.size();i++){
            mxv=max(mxv,vc[i]-vc[i-1]);
        }
       
        return (long)mxv*mxh%1000000007;
    }
};