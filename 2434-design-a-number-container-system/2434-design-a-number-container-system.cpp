class NumberContainers {
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indextonumber.find(index)!=indextonumber.end()){
            int prev = indextonumber[index];
            numbertoindex[prev].erase(index);
            if(numbertoindex[prev].empty()){
                numbertoindex.erase(prev);
            }
        }
        indextonumber[index]=number;
        numbertoindex[number].insert(index);
        
    }
    
    int find(int number) {
        if(numbertoindex.find(number)!=numbertoindex.end()){
            return *numbertoindex[number].begin();
        }
        return -1;
        
    }

private:
    unordered_map<int,set<int>>numbertoindex;
    unordered_map<int,int>indextonumber;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */