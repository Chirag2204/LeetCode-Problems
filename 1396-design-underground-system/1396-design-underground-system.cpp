struct details{
   int pasid;
    string startStation="",endStation="";
    double starttime=0,endtime=0;
};

class UndergroundSystem {
public:
    map<int,pair<string,double> > A;
    map<pair<string,string>, vector<double> > B;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
       A[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        B[make_pair(A[id].first,stationName)].push_back(t-A[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
       int count=B[make_pair(startStation,endStation)].size();
        double sum=0;
        for(auto &i:B[make_pair(startStation,endStation)]){
            sum+=i;
        }
        return double(sum)/double(count);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */