class Solution {
public:
    // double mini(double& a,double& b){
    //     if(a<b)return a;
    //     return b;
    // }
    
    double angleClock(int hour, int minutes) {
        int h=30,m=6;
        
        double tm=minutes*m;
        if(hour==12)hour=0;
        double th=h*hour + minutes*0.5;
        double ans=0;
        if(th>tm)
            ans=th-tm;
            
        else
        ans=tm-th;
        
        if(ans>180)return 360-ans;
        return ans;
    }
};