class MyHashSet {
public:
    
    set<int> hash;
    MyHashSet() {
        
    }
    
    void add(int key) {
       hash.insert(key); 
    }
    
    void remove(int key) {
        
            hash.erase(key);
    
    }
    
    bool contains(int key) {
        for(auto i:hash){
            if(i==key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */