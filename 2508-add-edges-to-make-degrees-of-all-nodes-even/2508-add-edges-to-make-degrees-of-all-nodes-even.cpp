class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        map<int,unordered_set<int>> m;
        vector<int> odd_vertices;
        for(auto& edge : edges){
            m[edge[0]].insert(edge[1]);
            m[edge[1]].insert(edge[0]);
        }
       int odd = 0;
       int even = 0;
    for (int i = 1; i<= n; i++) {
        int k = m[i].size();
        if (k%2==1) {
            if (k == n-1) {
                return false;
            }
            odd++;
            odd_vertices.push_back(i);
        } else {
            even++;
        }
    }
    //cout<<odd<<" "<<even<<endl;
     if (odd == 0) {
        return true;
    } 
    if (odd == 2) {
        int a = odd_vertices[0];
        int b = odd_vertices[1];
        //cout<<a<<" "<<b<<endl;
        
        for (int k = 1; k <= n; k++) {
            if (!m[a].count(k) && !m[b].count(k)){
                //cout<<k<<endl;
                return true;
            }
         
        }
        
        return false;
    } 
    if (odd == 4) {
        int a = odd_vertices[0];
        int b = odd_vertices[1];
        int c = odd_vertices[2];
        int d = odd_vertices[3];
        if ((!m[a].count(b) && !m[c].count(d)) ||
            (!m[a].count(c) && !m[b].count(d)) ||
            (!m[a].count(d) && !m[b].count(c))) {
            
           return true;
        }
        return false;
    } 
        return false;
        
        
    }
};