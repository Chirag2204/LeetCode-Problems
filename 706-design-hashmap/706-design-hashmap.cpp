class MyHashMap {
public:
    set<pair<int,int> > hashmap;
    MyHashMap() {
        
    }
    
   
    
    
    void put(int key, int value) {
        
            for(auto i:hashmap){
                
                if(i.first==key){
                    remove(i.first);
                }
            }
         hashmap.insert(make_pair(key,value));
    }
    
    int get(int key) {
       for(auto i:hashmap){
           
                if(i.first==key){
                    cout<<i.first<<"-> "<<i.second<<endl;
                    return i.second;
            } 
       }
        return -1;
    }
    
    void remove(int key) {
         for(auto i:hashmap){
                if(i.first==key)hashmap.erase(i);
            } 
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */