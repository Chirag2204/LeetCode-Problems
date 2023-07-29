class Solution {
public:
    
    double solve(int vola,int volb, map<pair<int,int>,double>& um){
        if(vola==0 and volb==0)return 0.5;
        if(vola==0)return 1;
        if(volb==0)return 0;
        
        if(um.count({vola,volb}))return um[{vola,volb}];
        
        double casea= solve(vola- min(vola,100),volb,um);
        double caseb= solve(vola-min(vola,75),volb- min(volb,25),um);
        double casec= solve(vola-min(vola,50),volb- min(volb,50),um);
        double cased= solve(vola- min(vola,25),volb- min(volb,75),um);
        
       return um[{vola,volb}]= 0.25*(casea+caseb+casec+cased);
        // return m[{vola,volb}];
        //return 0.25*(casea+caseb+casec+cased);
    }
    
    double soupServings(int n) {
        if(n>4800)return 1;
         map<pair<int,int>,double> um;
    
        return solve(n,n,um);
    }
};
// class Solution {
// public:
   
    
//     double soupServings(int n) {
        
//     }
// };