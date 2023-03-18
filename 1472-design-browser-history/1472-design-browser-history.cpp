class BrowserHistory {
public:
    int ind;
    vector<string> urls;
    BrowserHistory(string homepage) {
        urls.push_back(homepage);
        ind=0;
    }
    
    void visit(string url) {
        int n= urls.size()-1;
        while(n>ind){
            urls.pop_back();
            n--;
        }
        urls.push_back(url);
        ind= urls.size()-1;
        
        
    }
    
    string back(int steps) {
       int n= ind-steps;
        if(ind<0)return "";
        if(n<0){
            ind=0;
            return urls[0];
        }
        ind=n;
        return urls[n];
      
    }
    
    string forward(int steps) {
        int n= ind+steps;
        if(ind<0)return "";
        if(n>=urls.size()){
            ind=urls.size()-1;
            return urls[ind];
        }
        ind=n;
        return urls[n];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */