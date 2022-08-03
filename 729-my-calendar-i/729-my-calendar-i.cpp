class MyCalendar {
public:
    set<pair<int,int>> slots;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
       if(slots.size()==0){
           slots.insert(make_pair(start,end));
           return true;
       } 
        pair<int,int> prev={0,0};
        for(auto &event:slots){
            
            if(prev.first==0 && prev.second==0){
                prev=event;
                
            }
            if((start>=event.first && end<event.second)||(start<event.second && end>=event.second)||(start<event.first && end>event.first)||(start<prev.second && end>event.first)){
                 return false;
            }
          }
    
        slots.insert(make_pair(start,end));
           return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */