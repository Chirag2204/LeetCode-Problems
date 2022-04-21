class MyHashSet {
public:
    int i=0;
    vector<int> hash;
    MyHashSet() {
        
    }
    
    void add(int key) {
       if(!contains(key))hash.push_back(key); 
    }
    
    void remove(int key) {
        if(contains(key)){
            hash.erase(hash.begin()+i);
        }
    }
    
    bool contains(int key) {
        for(int x=0;x<hash.size();x++){
            i=x;
            if(hash[i]==key){
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