class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mpp;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        auto adrs = mpp[key].first;
        dll.erase(adrs);
        dll.push_front(key);
        mpp[key].first = dll.begin();
        return mpp[key].second;
 
    }
    
    void put(int key, int value) {
        if(mpp.count(key)){
            auto adrs = mpp[key].first;
            dll.erase(adrs);
            dll.push_front(key);
            mpp[key] = {dll.begin(),value};
        }
        else{
            dll.push_front(key);
            mpp[key] ={dll.begin(),value};
            capacity--;
        }
        if(capacity<0){
            mpp.erase(dll.back());
            dll.pop_back();
            capacity++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */